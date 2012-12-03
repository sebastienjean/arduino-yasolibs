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
 * Test application for GPS library
 *
 * Reads RMC NMEA sentences through a software serial link at 4800 Baud, with a
 * timeout set to 2s or 1000 chars (more than 10 sentences), and prints them to
 * serial debug port at 9600 Baud
 * @author S.jean
 * @date dec. 2012
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <GPS.h>

/**
 * NMEA GPS baud rate
 */
#define GPS_BAUD_RATE 4800

/**
 * Serial debug baud rate
 */
#define DEBUG_BAUD_RATE 4800


/**
 * Software serial with Rx on pin2 and Tx on pin 3
 */
SoftwareSerial gpsSerial(2, 3);

/**
 * NMEA GPS using software serial port, with 2s and 1000 chars timeout
 */
GPS gps(&gpsSerial, 2000, 1000);

/**
 * Array where to store NMEA sentences while reading
 */

char sentence[MAX_NMEA_SENTENCE_LENGTH];

/**
 * Arduino's setup function, called once at startup, after init
 */
void setup() {

	gpsSerial.begin(GPS_BAUD_RATE);
	Serial.begin(DEBUG_BAUD_RATE);
}

/**
 * Arduino's loop function, called in loop (incredible, isn't it ?)
 */
void loop() // run over and over
{
	GPS_status_enum result = gps.readRMC(sentence);
	Serial.println(result);
	Serial.println(sentence);
	sentence[0] = '\0';
}

/**
 * Application's main (what else to say?)
 * @return (never)
 */
int main(void) {
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
