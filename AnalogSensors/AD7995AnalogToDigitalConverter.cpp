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

#include <AD7995AnalogToDigitalConverter.h>
#include <Wire.h>

AD7995AnalogToDigitalConverter::AD7995AnalogToDigitalConverter(uint8_t address)
{
  this->address = address;
  Wire.begin();
}

uint16_t
AD7995AnalogToDigitalConverter::read(uint8_t channel)
{
  uint16_t result = 0;
  Wire.beginTransmission(this->address);
  Wire.write(AD7995_CHANNEL_SELECTION_BASE_MASK << channel);
  Wire.requestFrom(this->address, (uint8_t) 2);

  while (Wire.available())
    {
      result = result << 8;
      result += Wire.read();
    }
  Wire.endTransmission();
  return ((result & AD7995_RAW_TO_RESULT_CONVERSION_MASK) >> 2);
}

uint8_t
AD7995AnalogToDigitalConverter::getResolution()
{
  return AD7995_RESOLUTION;
}
