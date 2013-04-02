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
 * 2 - switching to PHOTO_SERIAL mode and taking photos every 4s for 30s
 * 3 - switching to PHOTO_SINGLE mode and taking photos every second for 30s
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
  // Nothing special to do here !
}

/**
 * Arduino's loop function, called in loop (incredible, isn't it ?)
 */
void
loop() // run over and over
{
  unsigned long startTimeMillis;

  // Recording for 5 seconds
  fcoev2.toggleAction();
  delay(5000);
  fcoev2.toggleAction();

  delay(1000);

  // Switching to Serial Photo Mode
  fcoev2.switchToNextMode();

  // Taking photo every 4 seconds for 30s
  fcoev2.toggleAction();
  startTimeMillis = millis();
  while (1)
    {
      delay(1000);
      if (((millis() - startTimeMillis) / 1000) > 30)
        break;
    }
  fcoev2.toggleAction();

  // Switching to Serial Photo Mode
  fcoev2.switchToNextMode();
  // Taking photo every second for 30s
  for (int i = 0; i < 30; i++)
    {
      delay(1000);
      fcoev2.toggleAction();
    }
  // Switching to Serial Photo Mode
  fcoev2.switchToNextMode();
}
