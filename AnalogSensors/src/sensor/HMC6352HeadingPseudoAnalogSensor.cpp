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

#include <sensor/HMC6352HeadingPseudoAnalogSensor.h>
#include <Wire.h>

HMC6352HeadingPseudoAnalogSensor::HMC6352HeadingPseudoAnalogSensor() :
    AnalogSensor(NULL, 0)
{
  Wire.begin();
}

uint16_t
HMC6352HeadingPseudoAnalogSensor::read()
{
  Wire.beginTransmission(HMC6352_ADDRESS);
  Wire.write(HMC6352_GET_DATA_COMMAND);
  Wire.endTransmission();

  delay(HMC6352_MAXIMUM_CONVERSION_DELAY_MILLIS);

  Wire.requestFrom(HMC6352_ADDRESS, HMC6352_NUMBER_OF_BYTES_TO_READ);

  int16_t byteRead = Wire.read();
  if (byteRead == -1)
    return 0;
  uint8_t dataMSB = byteRead;

  byteRead = Wire.read();
  if (byteRead == -1)
    return 0;
  uint8_t dataLSB = byteRead;

  Wire.endTransmission();

  uint16_t result = (((uint16_t) dataMSB) << 8) | dataLSB;
  return result;
}

uint8_t
HMC6352HeadingPseudoAnalogSensor::getAdcResolution()
{
  return HMC6352_HEADING_PSEUDO_ADC_RESOLUTION;
}
