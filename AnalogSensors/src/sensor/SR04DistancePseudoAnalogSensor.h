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

#ifndef SR04_DISTANCE_PSEUDO_ANALOG_SENSOR_h
#define SR04_DISTANCE_PSEUDO_ANALOG_SENSOR_h

#include <Arduino.h>
#include <core/AnalogSensor.h>

#define SR04_DISTANCE_PSEUDO_ADC_RESOLUTION 12
#define SR04_MICROS_PER_CM 58

/**
 * This class allows to consider an SR04 ultrasonic distance sensor as a pseudo ADC
 * on which  a (pseudo) distance analog sensor is attached
 */
class SR04DistancePseudoAnalogSensor : public AnalogSensor
{
private:

  /**
   * Trig pin
   */
  uint8_t trigPin;

  /**
   * Echo pin
   */
  uint8_t echoPin;

public:

  /**
   * Creates a SR04 distance pseudo analog sensor instance.
   *
   * @param trigPin digital pin wired to SR04 TRIG input
   * @param echoPin digital pin wired to SR04 ECHO output
   */
  SR04DistancePseudoAnalogSensor(uint8_t trigPin, uint8_t echoPin);

  /**
   * Reads analog sensor value.
   *
   * @return analog sensor value
   */
  uint16_t
  read(void);

  /**
   * Gets ADC resolution (in bits).
   *
   * @return ADC resolution (in bits)
   */
  uint8_t
  getAdcResolution(void);
};

#endif

