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

#ifndef HMC6352_HEADING_PSEUDO_ANALOG_SENSOR_h
#define HMC6352_HEADING_PSEUDO_ANALOG_SENSOR_h

#include <Arduino.h>
#include <AnalogSensor.h>

#define HMC6352_ADDRESS 0b00000000
#define HMC6352_HEADING_PSEUDO_ADC_RESOLUTION 12

/**
 * This class allows to consider an HMC6352 I2C compass as a pseudo ADC on which
 * a (pseudo) heading analog sensor is attached
 */
class HMC6352HeadingPseudoAnalogSensor : public AnalogSensor
{
public:

  /**
   * Creates a HMC6352 heading pseudo analog sensor instance.
   *
   * @param address address on the I2C bus
   */
  HMC6352HeadingPseudoAnalogSensor();

  /**
   * Reads analog sensor value.
   *
   * @return analog sensor value
   */
  uint16_t
  read();

  /**
    * Gets ADC resolution (in bits).
    *
    * @return ADC resolution (in bits)
    */
   uint8_t
   getAdcResolution(void);
};

#endif

