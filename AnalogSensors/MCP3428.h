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

#ifndef MCP3428_h
#define MCP3428_h

#include <Arduino.h>

#define MCP3428_BASE_ADDRESS  0b01101000

#define MCP3428_NUMBER_OF_CHANNELS 4

#define MCP3428_NUMBER_OF_BYTES_TO_READ 3

#define MCP3428_CONFIGURATION_REGISTER_READY_SHIFT_OFFSET 7

#define MCP3428_CONFIGURATION_REGISTER_CHANNEL_SHIFT_OFFSET 5

#define MCP3428_CONFIGURATION_REGISTER_16BITS_RESOLUTION_MASK 0b00001000

/**
 * This class allows to handle an I2C AD7995 (both 0 or 1 models) ADC
 */
class MCP3428
{
private:

  /**
   * Address on the I2C bus
   */
  uint8_t address;

public:

  /**
   * Creates a MCP3428 ADC instance.
   *
   * @param addressBit0 first address configuration bit value
   * @param addressBit1 first address configuration bit value
   */
  MCP3428(boolean addressBit0, boolean addressBit1);

  /**
   * Reads analog sensor value.
   *
   * @param channel analog channel number
   * @return analog sensor value
   */
  uint16_t
  read(uint8_t channel);

};

#endif

