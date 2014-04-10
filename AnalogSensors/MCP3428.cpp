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

#include <MCP3428.h>
#include <Wire.h>

MCP3428::MCP3428(boolean addressBit0, boolean addressBit1)
{
  this->address = MCP3428_BASE_ADDRESS;
  if (addressBit0) this->address = (this->address & 0b00000100);
  if (addressBit1) this->address = (this->address & 0b00000010);

  Wire.begin();
}

uint16_t
MCP3428::read(uint8_t channel)
{

      // Conf. register, 16 bit resolution, continuous conversion, x1 gain
      uint8_t configurationRegister = 0b00000000;
      configurationRegister |= MCP3428_CONFIGURATION_REGISTER_16BITS_RESOLUTION_MASK;
      configurationRegister |= (1 << MCP3428_CONFIGURATION_REGISTER_READY_SHIFT_OFFSET);
      configurationRegister |= (channel << MCP3428_CONFIGURATION_REGISTER_CHANNEL_SHIFT_OFFSET);

      Wire.beginTransmission(this->address);
      Wire.write(configurationRegister);
      Wire.endTransmission();

      Wire.requestFrom(this->address, (uint8_t) MCP3428_NUMBER_OF_BYTES_TO_READ);

      uint8_t dataMSB = Wire.read();
      uint8_t dataLSB = Wire.read();
      configurationRegister = Wire.read();

      uint16_t result = (((uint16_t) dataMSB) << 8) |  dataLSB;

      return result;
 }
