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

#ifndef HMC6352_HEADING_ANALOG_SENSOR_h
#define HMC6352_HEADING_ANALOG_SENSOR_h

#include <Arduino.h>

#define HMC6352_BASE_ADDRESS  0b00000000

/**
 * This class allows to handle an I2C HMC6352 compass as an heading (pseudo) analog sensor.
 * "pseudo" means that it is not an analog sensor but it can be seen like one. Note here that
 * only heading is provided.
 */
class HMC6352HeadingPseudoAnalogSensor
{
private:

  /**
   * Address on the I2C bus
   */
  int address;

public:

  /**
   * Creates a HMC6352 heading pseudo analog sensor  instance.
   */
  HMC6352HeadingPseudoAnalogSensor();

  /**
     * Reads heading and returns it as an analog sensor value.
     *
     * @return heading as an analog sensor value
     */
  int
  read();

};

#endif

