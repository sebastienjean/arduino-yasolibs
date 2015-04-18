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

#ifndef ANALOG_SENSORS_h
#define ANALOG_SENSORS_h

#include <pins_arduino.h>

#include <core/AnalogSensor.h>

/**
 * This class wraps a set of analog sensors.
 */
class AnalogSensors
{
private:

  /**
   * Sensors (pointers) contained in this set
   */
  AnalogSensor** analogSensors;

  /**
   * Number of sensors in this set
   */
  uint16_t analogSensorsAmount;

public:

  /**
   * Creates a new analog sensors set containing existing analog sensors
   *
   * @param analogSensors an array containing sensors to add to this set
   * @param analogSensorsAmount the number of sensors to add from <tt>analogSensors</tt>
   */
  AnalogSensors(AnalogSensor** analogSensors, uint16_t analogSensorsAmount);

  /**
   * Reads a given sensor value.
   *
   * @param sensorNumber the number of the sensor to read (starting at 1)
   * @return value of sensor <tt>sensorNumber</tt> if it exists, -1 else
   */
  uint16_t
  read(uint16_t sensorNumber);

  /**
   * Returns the amount of analog sensors in this set
   *
   * @return the amount of analog sensors in this set
   */
  uint16_t
  getAmount(void);

  /**
   * Gets an analog sensor by its number (starting at 1)
   * @param analogSensornumber the offset of the analog sensor to retrieve (starting at 1)
   * @return the analog sensor at given offset
   */
  AnalogSensor *
  getAnalogSensor(uint16_t analogSensorNumber);
};

#endif

