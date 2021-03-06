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

#ifndef AD7995_h
#define AD7995_h

#include <Arduino.h>
#include <core/AnalogToDigitalConverter.h>

#define AD7995_RESOLUTION 10;

#define AD7995_0_ADDRESS  0b00101000

#define AD7995_1_ADDRESS  0b00101001

#define AD7995_CHANNEL_SELECTION_BASE_MASK 0b00010000

#define AD7995_RAW_TO_RESULT_CONVERSION_MASK 0b0000111111111100

#define AD7995_NUMBER_OF_CHANNELS 4

#define AD7995_NUMBER_OF_BYTES_TO_READ 2

#define AD7995_MAXIMUM_CONVERSION_DELAY_MILLIS 10

/**
 * This class allows to handle an I2C AD7995 (both 0 or 1 models) ADC
 */
class AD7995AnalogToDigitalConverter : public AnalogToDigitalConverter
{
private:

  /**
   * Address on the I2C bus
   */
  uint8_t address;

public:

  /**
   * Creates a AD7995 ADC instance.
   *
   * @param address address on the I2C bus
   */
  AD7995AnalogToDigitalConverter(uint8_t address);

  /**
   * Reads analog sensor value.
   *
   * @param channel analog channel number
   * @return analog sensor value
   */
  uint16_t
  read(uint8_t channel);

  /**
    * Gets resolution (in bits).
    *
    * @return resolution (in bits)
    */
   uint8_t
   getResolution(void);
};

#endif

