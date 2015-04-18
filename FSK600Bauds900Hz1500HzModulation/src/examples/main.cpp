/*
* Copyright (c) 2012 Sebastien Jean.
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
 * Test application for FSK600BaudTA900TB1500Mod library
 *
 * Transmits endlessly "ABCDEFGHIJKLMNOPQRSTUVWXYZ", every 2s
 * @author S.jean
 * @date dec. 2012
 */
#include <Arduino.h>
#include <FSK600BaudTA900TB1500Mod.h>

/**
 *  FSK modulator TX PIN
 */
#define FSK_MOD_TX 6

/**
 * FSK modulator instance
 */
FSK600BaudTA900TB1500Mod fskMod(FSK_MOD_TX);

/**
 * Message to be transmitted
 */
char message[27];

/**
 * Arduino's setup function, called once at startup, after init
 */
void setup()  
{
 strcpy (message, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"); 
}

/**
 * Arduino's loop function, called in loop (incredible, isn't it ?)
 */
void loop() // run over and over
{
  while (true)
  {
  	for (int cpt=0; cpt<26; cpt++)
    	fskMod.write(message[cpt]);
    	
    	delay (2000);
  }
}

/**
 * Application's main (what else to say?)
 * @return (never)
 */
int main(void)
{
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
