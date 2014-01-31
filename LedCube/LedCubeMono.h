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
 * Driver for mono-colored LED cube, suitable from 1x1x1 (!) to 16x16x16 cubes.
 * The cube is driven by a chain of 16-bits shift registers, the last of them allowing to select
 * the active layer.
 * It is supposed that if the cube is driven by n+1 shift registers, there is no register
 * between the first n ones that is associated to more than one layer.
 * Below is illustrated the example of a 4x4x4 LED cube, that needs only 2 16-bits shift
 * registers :
 *  - the first allows to select which LED is lit on the layer (4x4 = 16 LEDs by layer)
 *  - the second allows to select which layer is active (4 layers)
 *
 *                ------        --------
 *   data in ----| leds |------| layers |
 *                ------        --------
 *                 |..|           |..|
 *               (to leds)     (to layers)
 *
 */
class LedCubeMono
{

private:

  // fields

  /**
   * Number of layers
   */
  uint8_t numberOfLayers;

  /**
   * Frame rate (in FPS)
   */
  uint8_t frameRate;

  /**
   * Number of registers used for each layer
   */
  uint8_t numberOfRegistersUsedForEachLayer;

  /**
   * Pin used for serial data input
   */
  uint8_t sdiPin;

  /**
   * Pin used for clock
   */
  uint8_t clockPin;

  /**
   * Pin used for latch
   */
  uint8_t latchPin;

  // methods

  /**
   * LED cube driver initialization (used by constructors, initializes everything but the frame rate
   * @param numberOfLayers number of layers
   * @param dataInPin serial data input pin
   * @param clockPin clock pin
   * @param latchPin latch pin
   */
  void
  initialize(uint8_t numberOfLayers, uint8_t sdiPin, uint8_t clockPin, uint8_t latchPin);

  /**
   * Latch all registers simultaneously
   */
  void
  latchRegisters();

  /**
   * Push 16 bits in shift registers chain
   * @param bits the 16 bits to push, starting by the least significant one
   */
  void
  push16bitsInRegister(uint16_t bits);

public:

  // methods
  /**
   * Construct a new LED cube driver, with given control pins and a default frame rate (50 FPS, to avoid flickering)
   * @param numberOfLayers number of layers
   * @param dataInPin serial data input pin
   * @param clockPin clock pin
   * @param latchPin latch pin
   */
  LedCubeMono(uint8_t numberOfLayers, uint8_t dataInPin, uint8_t clockPin, uint8_t latchPin);

  /**
   * Construct a new LED cube driver, with given control pins and a given frame rate
   * @param numberOfLayers number of layers
   * @param dataInPin serial data input pin
   * @param clockPin clock pin
   * @param latchPin latch pin
   * @param frameRate frame rate (in FPS)
   */
  LedCubeMono(uint8_t numberOfLayers, uint8_t dataInPin, uint8_t clockPin, uint8_t latchPin, uint8_t frameRate);

  /**
   * Turn LED cube off
   */
  void
  off();

  /**
   * Draw a layer
   * @param layerMask the mask of the layer to draw
   * @param ledsMask the LED pattern to draw on this layer
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
