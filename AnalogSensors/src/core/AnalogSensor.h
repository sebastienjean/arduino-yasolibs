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

#ifndef ANALOG_SENSOR_h
#define ANALOG_SENSOR_h

#include <Arduino.h>
#include <core/AnalogToDigitalConverter.h>

/**
 * This class allows to handle an analog sensor (up to 16-bit resolution)
 */
class AnalogSensor
{
protected:

  /**
   * ADC to which the analog sensor is attached
   */
  AnalogToDigitalConverter *adc;

  /**
   * (ADC) channel to which the analog sensor is attached
   */
  uint8_t channel;

public:

  /**
   * Creates an analog sensor attached to a given channel of a given ADC.
   *
   * @param adc ADC to which the analog sensor is attached
   * @param channel analog channel to which the sensor is attached
   */
  AnalogSensor(AnalogToDigitalConverter *adc, uint8_t channel);

  /**
   * Reads analog sensor value.
   *
   * @return analog sensor value
   */
  virtual uint16_t
  read(void);

  /**
   * Gets ADC resolution (in bits).
   *
   * @return ADC resolution (in bits)
   */
  virtual uint8_t
  getAdcResolution(void);
};

#endif

