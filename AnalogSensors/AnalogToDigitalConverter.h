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

#ifndef ANALOG_TO_DIGITAL_CONVERTER_h
#define ANALOG_TO_DIGITAL_CONVERTER_h

//#include <Arduino.h>

/**
 * This abstract class allows to handle ADCs (Analog to Digital Converters)
 */
class AnalogToDigitalConverter
{
public:

  /**
   * Reads analog sensor value.
   *
   * @param channel analog channel number
   * @return analog sensor value
   */
  virtual uint16_t
  read(uint8_t channel) = 0;

  /**
    * Gets resolution (in bits).
    *
    * @return resolution (in bits)
    */
   virtual uint8_t
   getResolution(void) = 0;
};

#endif

