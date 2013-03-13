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

#include <Arduino.h> 
#include <FSK600BaudTA900TB1500Mod.h>

FSK600BaudTA900TB1500Mod::FSK600BaudTA900TB1500Mod(uint8_t outPin)
{
    this->transmitPin = outPin;
	pinMode(this->transmitPin, OUTPUT);

	// Setting initial last state at LOW
	this->lastState = LOW;
	digitalWrite(this->transmitPin, LOW);
}

void FSK600BaudTA900TB1500Mod::generateTone(bool bit)
{
	uint16_t halfPeriodUs;
	uint8_t halfPeriodLoops;

	int counter = 0;
	
	// when HIGH, a bit is transmitted generating 1500 Hz tone during 1/600th of a second
	if (bit)
	{ 
		halfPeriodUs = FSK600Baud_1500HZ_HALF_PERIOD_US;
		halfPeriodLoops =  FSK600Baud_1500HZ_HALF_PERIOD_US_LOOPS;
	}
	// when LOW, a bit is transmitted generating 900 Hz tone during 1/600th of a second
	else
	{
		halfPeriodUs = FSK600Baud_900HZ_HALF_PERIOD_US;
		halfPeriodLoops =  FSK600Baud_900HZ_HALF_PERIOD_US_LOOPS;
	}

	for (counter=0;counter<halfPeriodLoops; counter++)
	{
		this->lastState = !this->lastState;
		digitalWrite(this->transmitPin, this->lastState);
		delayMicroseconds(halfPeriodUs);
	}
}


void FSK600BaudTA900TB1500Mod::off()
{
	digitalWrite(this->transmitPin, LOW);
}

/**
 * Writes a byte, using 8N1 serial transmission semantics
 * @param c the byte to be written
 * @return
 */
size_t FSK600BaudTA900TB1500Mod::write(uint8_t c)
{
	int loopByte;

	// save settings and turn off interrupts for a clean txmit
	uint8_t oldSREG = SREG;
	cli();

	// idle state
	generateTone(HIGH);
	generateTone(HIGH);
	
	// start bit    
	generateTone(LOW);
		
	// char bits, starting with LSB
	for (loopByte=0;loopByte<8;loopByte++)
	{
		generateTone(c % 2);
		c = c /2 ;
	}

	//stop bit
    generateTone(HIGH);
	
    // Restore old interrupts settings
	SREG = oldSREG;
}

/**
 * Modulates an array of bytes
 * @param bytes the array containing bytes to modulate
 * @param length the number of bytes to modulate (starting at bytes[0])
 */
void FSK600BaudTA900TB1500Mod::modulateBytes(char *bytes, int length)
{
  for (int cpt = 0; cpt < length; cpt++)
    this->write(bytes[cpt]);
  this->off();
}

int FSK600BaudTA900TB1500Mod::read() {return -1;}
int FSK600BaudTA900TB1500Mod::available() {return 0;}
void FSK600BaudTA900TB1500Mod::flush() {};
int FSK600BaudTA900TB1500Mod::peek() {return -1;}
