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

#include <Arduino.h> 
#include <LedCubeMono.h>

#define ZERO_FILLED_REGISTER (uint16_t) 0b0000000000000000
#define REGISTER_SIZE 16

#define LAYER_MASK(l) (uint16_t) (0b0000000010000000 >> l)

LedCubeMono::LedCubeMono(uint8_t size, uint8_t sdiPin, uint8_t clockPin,
    uint8_t latchPin)
{
  this->size = size;

  this->layerStillNessMillis = 1000 / (25 * this->size * 2);
  this->numberOfregistersUsedForLayer = ((this->size * this->size) / REGISTER_SIZE)+1;
  if (((this->size * this->size) % REGISTER_SIZE) == 0) this->numberOfregistersUsedForLayer--;

  this->sdiPin = sdiPin;
  pinMode(this->sdiPin, OUTPUT);
  digitalWrite(this->sdiPin, LOW);

  this->clockPin = clockPin;
  pinMode(this->clockPin, OUTPUT);
  digitalWrite(this->clockPin, LOW);

  this->latchPin = latchPin;
  pinMode(this->latchPin, OUTPUT);
  digitalWrite(this->latchPin, LOW);
}

/**
 * Off
 *
 */
void
LedCubeMono::off()
{
  this->push16bitsInRegister(ZERO_FILLED_REGISTER);
  for (int registerNumber = 0; registerNumber < this->numberOfregistersUsedForLayer; registerNumber++)
    this->push16bitsInRegister(ZERO_FILLED_REGISTER);
  this->latchRegisters();
}

/**
 * Latch
 *
 */
void
LedCubeMono::latchRegisters()
{
  digitalWrite(this->latchPin, HIGH);
  digitalWrite(this->latchPin, LOW);
}

void
LedCubeMono::push16bitsInRegister(uint16_t registerMask)
{
  for (int bit = 0; bit < REGISTER_SIZE; bit++)
    {
      if (registerMask & 0x01 << bit)
        {
          digitalWrite(this->sdiPin, HIGH);
        }
      digitalWrite(this->clockPin, HIGH);
      digitalWrite(this->sdiPin, LOW);
      digitalWrite(this->clockPin, LOW);
    }
}

void
LedCubeMono::drawLayer(uint16_t layerMask, uint16_t *ledsMask)
{
  this->push16bitsInRegister(layerMask);
  for (int registerNumber = 0; registerNumber < this->numberOfregistersUsedForLayer; registerNumber++)
    this->push16bitsInRegister(ledsMask[registerNumber]);
  this->latchRegisters();
}

void
LedCubeMono::drawFrame(uint16_t *frameMask)
{
  for (int layer = 0; layer < this->size; layer++)
    {
      this->drawLayer(LAYER_MASK(layer), (uint16_t *) (frameMask+ (layer* this->numberOfregistersUsedForLayer)));
      delay(this->layerStillNessMillis);
    }
}

