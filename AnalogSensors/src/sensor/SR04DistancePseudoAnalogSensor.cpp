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

#include <sensor/SR04DistancePseudoAnalogSensor.h>
#include <Wire.h>

SR04DistancePseudoAnalogSensor::SR04DistancePseudoAnalogSensor(uint8_t trigPin, uint8_t echoPin) :
    AnalogSensor(NULL, 0)
{
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  pinMode(this->trigPin, OUTPUT);
  pinMode(this->echoPin , INPUT);
  digitalWrite(this->trigPin , LOW);
}

uint16_t
SR04DistancePseudoAnalogSensor::read()
{
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigPin, LOW);
  return pulseInLong(this->echoPin, HIGH);
}

uint8_t
SR04DistancePseudoAnalogSensor::getAdcResolution()
{
  return SR04_DISTANCE_PSEUDO_ADC_RESOLUTION;
}
