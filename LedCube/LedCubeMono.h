/*
 * Copyright (c) 2013 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 *
 * Contributors:
 *     Sebastien Jean - initial API and implementation
 */

#ifndef LED_CUBE_MONO_h
#define LED_CUBE_MONO_h

#include <inttypes.h>
#include <Stream.h>

/**
 * Driver for Mono LED cube
 */

class LedCubeMono
{

private:
  // per object data

  uint8_t size;

  uint8_t layerStillNessMillis;

  uint8_t numberOfregistersUsedForLayer;

  /**
   * Pin used for serial data input
   */
  uint8_t sdiPin;

  /**
   * Pin used for clock
   */
  uint8_t clockPin;

  /**
   * Pin used for clock
   */
  uint8_t latchPin;

  // private methods

  /**
   * Latch all registers simultaneously
   */
  void
  latchRegisters();

  /**
   * Push 16 bits in registers
   * @param bits
   */
  void
  push16bitsInRegister(uint16_t bits);

public:

  // public methods
  /**
   * Construct a new LED cube driver, with given pins
   * @param dataInPin
   * @param clockPin
   * @param latchPin
   */
  LedCubeMono(uint8_t size, uint8_t dataInPin, uint8_t clockPin,
      uint8_t latchPin);

  /**
   * Turn LED cube off
   */
  void
  off();

  /**
   * Draw a layer
   * @param layerMask the mask of the layer to draw
   * @param ledsMask the led pattern to draw on this layer
   */
  void
  drawLayer(uint16_t layerMask, uint16_t *ledsMask);

  /**
   * Draw a single frame
   * @param frameMask array of 4x16bits masks representing leds mask for each layer (in ascending order)
   */
  void
  drawFrame(uint16_t *frameMask);

};
#endif
