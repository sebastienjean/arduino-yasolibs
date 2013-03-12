/*
* Copyright (c) 2012-2013 Sebastien Jean.
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
 * This example assumes that the transmit pin of a GPS is connected to hardware serial RX pin.
 *
 * This application endlessly reads RMC/GGA NMEA sentences through hardware serial at
 * 4800 Baud (with a timeout set to 2s or 2000 chars ), outputs valid sentences through
 * hardware serial, as well as 3D positioning decoded data.
 * N.B. because this application uses the same hardware serial for GPS and debug, and since
 * GPS receivers can use 3.3V TTL signals, it is better to open debug connection on PC-side
 * prior to connect GPS receiver to avoid issues.
 * @author S.Jean
 */

#include <Arduino.h>
#include <GPS3D.h>

/**
 * NMEA GPS baud rate
 */
#define GPS_BAUD_RATE 4800

/**
 * NMEA GPS using software serial port, with 2s and 2000 chars timeout
 */
GPS3D gps(&Serial, &Serial);

/**
 * Arduino's setup function, called once at startup, after init
 */
void setup()
{
	Serial.begin(GPS_BAUD_RATE);
}

/**
 * Arduino's loop function, called in loop (incredible, isn't it ?)
 */
void loop() // run over and over
{
	Serial.println("Reading NMEA sentences");
	GPS_status_enum result = gps.readPositioningData();
	switch (result)
	{
		case GPS_OK : Serial.println("OK"); break;
		case GPS_NOT_NMEA : Serial.println("NOT NMEA"); break;
		case GPS_TIMEOUT : Serial.println("TIMEOUT"); break;
	}
	if (gps.getFix())
		Serial.println("got Fix");
	else
		Serial.println("no Fix");
	Serial.print("UTC Time of fix: ");
	Serial.println(gps.getTimeOfFix());
	Serial.print("Latitude (+/-dd.d): ");
	Serial.println(gps.getLatitude(),4);
	Serial.print("Longitude (+/-dd.d): ");
	Serial.println(gps.getLongitude(),4);
	Serial.print("Altitude (m): ");
	Serial.println(gps.getAltitude(),1);
	Serial.print("Speed over ground (knots): ");
	Serial.println(gps.getSpeedOverGround(),1);
	Serial.print("Course over ground (dd.d): ");
	Serial.println(gps.getCourseOverGround(),1);
	Serial.print("Satellites in use: ");
	Serial.println(gps.getSatellitesInUse());
	Serial.print("HDOP: ");
	Serial.println(gps.getHDOP(),1);

	delay(2000);
}
