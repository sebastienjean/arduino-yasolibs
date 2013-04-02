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
#include <FCOEV2.h>

FCOEV2::FCOEV2(uint8_t pwmPin)
{
  this->pwmPin = pwmPin;
  pinMode(this->pwmPin, OUTPUT);
  this->resetMode();
}

void
FCOEV2::resetMode()
{
  this->mode = MODE_VIDEO;
}

void
FCOEV2::idle()
{
  for (int i = 0; i < IDLE_PERIODS; i++)
    {
      digitalWrite(this->pwmPin, HIGH);
      delayMicroseconds(IDLE_HIGH_MICROS);
      digitalWrite(this->pwmPin, LOW);
      delay(PERIOD_MILLIS);
    }
}

void
FCOEV2::signal(uint16_t pulseWidthMicros, uint8_t periods)
{
  for (int i = 0; i < periods; i++)
    {
      digitalWrite(this->pwmPin, HIGH);
      delayMicroseconds(pulseWidthMicros);
      digitalWrite(this->pwmPin, LOW);
      delay(PERIOD_MILLIS);
    }
}

void
FCOEV2::toggleAction()
{
  idle();
  signal(ACTION_OR_MODE_HIGH_MICROS, ACTION_PERIODS);
  idle();
}

void
FCOEV2::switchToNextMode()
{
  idle();
  signal(ACTION_OR_MODE_HIGH_MICROS, CHANGE_MODE_PERIODS);
  idle();
  if (this->mode == MODE_VIDEO)
    this->mode = MODE_PHOTO_SERIAL;
  else if (this->mode == MODE_PHOTO_SERIAL)
    this->mode = MODE_PHOTO_SINGLE;
  else if (this->mode == MODE_PHOTO_SINGLE)
    this->mode = MODE_VIDEO;
  delay(SWITCH_MODE_PAUSE_MILLIS);
}

void
FCOEV2::switchToMode(FCOEV2_mode_status_enum mode)
{
  for (int i = 0; i < ((mode - this->mode) % 3); i++)
    {
      this->switchToNextMode();
    }
}

FCOEV2_mode_status_enum
FCOEV2::getCurrentMode()
{
  return this->mode;
}
