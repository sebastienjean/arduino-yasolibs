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

/**
 * Test application for FCOEV2 library
 *
 * This test application supposes the FCOEV2 to be attached on pin 4 and to be on.
 * Then it loops endlessly on:
 * 1 - triggering a recording (when on, the first mode is VIDEO) for 5 seconds
 * 2 - switching to PHOTO_SINGLE mode and taking 5 photos pausing 1s between each
 * 3 - switching to PHOTO_SERIAL mode and taking photos every 4s for 15s
 *
 * @author S.Jean
 * @date feb. 2013
 */

#include <Arduino.h>
#include <FCOEV2.h>

/**
 * FCOEV2 attached to pin 4
 */
FCOEV2 fcoev2(4);

/**
 * Arduino's setup function, called once at startup, after init
 */
void
setup()
{
  // Waiting for camera to power up properly
  delay(SWITCH_ON_PAUSE_MILLIS);
}

/**
 * Arduino's loop function, called in loop (incredible, isn't it ?)
 */
void
loop() // run over and over
{
  unsigned long startTimeMillis;

  // Switching to Video Mode
  // (the first time loop is called, it does nothing since it is the initial mode)
  fcoev2.switchToMode(MODE_VIDEO);
  // Recording for 5 seconds
  fcoev2.toggleAction();
  delay(5000);
  fcoev2.toggleAction();

  delay(1000);

  // Switching to Single Photo Mode
  fcoev2.switchToMode(MODE_PHOTO_SINGLE);
  // Taking 5 photos periodically, pausing 1s between each
  for (int i = 0; i < 5; i++)
    {
      delay(1000);
      fcoev2.toggleAction();
    }

  // Switching to Serial Photo Mode
  fcoev2.switchToMode(MODE_PHOTO_SERIAL);
  // Taking photo every 4 seconds for 15s
  fcoev2.toggleAction();
  startTimeMillis = millis();
  while (1)
    {
      delay(1000);
      if (((millis() - startTimeMillis) / 1000) > 15)
        break;
    }
  // Stopping taking photos
  fcoev2.toggleAction();
}
