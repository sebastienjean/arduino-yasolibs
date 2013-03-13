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

#ifndef FSKMod_h
#define FSKMod_h

#include <inttypes.h>
#include <Stream.h>

/**
 * Duration of the 900Hz tone half-period, in microseconds
 */
#define FSK600Baud_900HZ_HALF_PERIOD_US 550 /// 555 theorically

/**
 * Duration of the 1500Hz tone half-period, in microseconds

 */
#define FSK600Baud_1500HZ_HALF_PERIOD_US 326 // 333 theorically

/**
 * Number of 900 Hz half-periods observed at 600 Baud
 */
#define FSK600Baud_900HZ_HALF_PERIOD_US_LOOPS 3

/**
 * Number of 1500 Hz half-periods observed at 600 Baud
 */
#define FSK600Baud_1500HZ_HALF_PERIOD_US_LOOPS 5

/**
 * An output stream, sending bytes using 600 Baud FSK modulation, using 900Hz/1500Hz as tone frequencies
 */
class FSK600BaudTA900TB1500Mod : public Stream
{
private:
	// per object data

	/**
	 * Last end of bit state (LOW/HIGH)
	 */
    bool lastState;

    /**
     * Pin used as output
     */
	uint8_t transmitPin;
	
	// private methods
		
public:
	// public methods
	/**
	 * Opens a FSK output stream, using a specified pin
	 * @param outPin the pin to use for output
	 */
	FSK600BaudTA900TB1500Mod(uint8_t outPin);
	
	/**
	 * Turns modulation off
	 */
	void off();
	
	/**
	 * Generates tone for a single bit
	 * @param bit the bit to transmit
	 */
	void generateTone(bool bit);
	
	/**
	 * Modulates an array of bytes
	 * @param bytes the array containing bytes to modulate
	 * @param length the number of bytes to modulate (starting at bytes[0])
	 */
	void modulateBytes(char *bytes, int length);

	virtual size_t write(uint8_t byte);
	virtual int read();
	virtual int peek();
	virtual int available();
	virtual void flush();


};
#endif
