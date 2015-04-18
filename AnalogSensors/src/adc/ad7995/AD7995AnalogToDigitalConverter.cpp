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

#include <adc/ad7995/AD7995AnalogToDigitalConverter.h>
#include <Wire.h>

AD7995AnalogToDigitalConverter::AD7995AnalogToDigitalConverter(uint8_t address)
{
  this->address = address;
  Wire.begin();
}

uint16_t
AD7995AnalogToDigitalConverter::read(uint8_t channel)
{
  Wire.beginTransmission(this->address);
  Wire.write(AD7995_CHANNEL_SELECTION_BASE_MASK << channel);
  Wire.endTransmission();

  delay(AD7995_MAXIMUM_CONVERSION_DELAY_MILLIS);

  Wire.requestFrom(this->address, (uint8_t) AD7995_NUMBER_OF_BYTES_TO_READ);

  int16_t byteRead =  Wire.read();
  if (byteRead == -1) return 0;
  uint8_t dataMSB = byteRead;

  byteRead =  Wire.read();
  if (byteRead == -1) return 0;
  uint8_t dataLSB = byteRead;

  Wire.endTransmission();

  uint16_t result = (((uint16_t) dataMSB) << 8) |  dataLSB;

  return ((result & AD7995_RAW_TO_RESULT_CONVERSION_MASK) >> 2);
}

uint8_t
AD7995AnalogToDigitalConverter::getResolution()
{
  return (uint8_t) AD7995_RESOLUTION;
}
