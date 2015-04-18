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

#ifndef MOCK_ANALOG_SENSOR_h
#define MOCK_ANALOG_SENSOR_h

#include <core/AnalogSensor.h>
/**
 * This class allows to handle mock analog sensors.
 * Mock analog sensors always return the same preset value
 */
class MockAnalogSensor : public AnalogSensor
{
private:

  /**
   * Value to be returned
   */
  uint16_t valueToBeReturned;

  /**
   * Resolution to be returned
   */
  uint8_t resolutionToBeReturned;

public:

  /**
   * Creates a mock sensor associated to given return value and resolution
   *
   * @param valueToBeReturned value to be returned
   * @param resolutionToBeReturned resolution to be returned
   */
  MockAnalogSensor(uint16_t valueToBeReturned, uint8_t resolutionToBeReturned );

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

