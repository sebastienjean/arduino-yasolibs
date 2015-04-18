/*
 Copyright (C) 2012 Sebastien Jean <baz dot jean at gmail dot com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the version 3 GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <adc/mcp3428/MCP3428AnalogToDigitalConverter.h>
#include <Wire.h>

MCP3428AnalogToDigitalConverter::MCP3428AnalogToDigitalConverter(
    boolean addressBit0, boolean addressBit1)
{
  this->address = MCP3428_BASE_ADDRESS;
  this->resolution = MCP3428_DEFAULT_RESOLUTION;
  if (addressBit0)
    this->address = (this->address | 0b00000100);
  if (addressBit1)
    this->address = (this->address | 0b00000010);

  Wire.begin();
}

uint16_t
MCP3428AnalogToDigitalConverter::read(uint8_t channel)
{

  // Conf. register, 16 bit resolution, continuous conversion, x1 gain
  uint8_t configurationRegister = 0b00000000;
  configurationRegister |=
      MCP3428_CONFIGURATION_REGISTER_16BITS_RESOLUTION_MASK;
  configurationRegister |= (1
      << MCP3428_CONFIGURATION_REGISTER_READY_SHIFT_OFFSET);
  configurationRegister |= (channel
      << MCP3428_CONFIGURATION_REGISTER_CHANNEL_SHIFT_OFFSET);

  Wire.beginTransmission(this->address);
  Wire.write(configurationRegister);
  Wire.endTransmission();

  delay(MCP3428_MAXIMUM_CONVERSION_DELAY_MILLIS);

  Wire.requestFrom(this->address, (uint8_t) MCP3428_NUMBER_OF_BYTES_TO_READ);

  int16_t byteRead = Wire.read();
  if (byteRead == -1)
    return 0;
  uint8_t dataMSB = byteRead;

  byteRead = Wire.read();
  if (byteRead == -1)
    return 0;

  uint8_t dataLSB = byteRead;
  byteRead = Wire.read();
  if (byteRead == -1)
    return 0;

  configurationRegister = byteRead;

  Wire.endTransmission();

  uint16_t result = (((uint16_t) dataMSB) << 8) | dataLSB;

  return result;
}

uint8_t
MCP3428AnalogToDigitalConverter::getResolution()
{
  return this->resolution;
}

