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

#ifndef GPS3D_h
#define GPS3D_h
#include <GPS2D.h>

#define GGA_SATS_IN_USE_FIELD_NUMBER 7

#define GGA_HDOP_FIELD_NUMBER 8

#define GGA_ALTITUDE_FIELD_NUMBER 9

/**
 * A NMEA GPS, reading sentences from an input stream (with timeouts), optionally writing
 * valid sentences to an output stream, allowing to get 3D positioning data
 * (using RMC and GGA sentences)
 */
class GPS3D : public GPS2D {
private:
	// per object data

	/**
	 * Number of satellites in use
	 */
	int m_satellitesInUse; // GGA field 7

	/**
	 * Horizontal dilution of precision
	 */
	double m_hdop; // GGA field 8

	/**
	 * Altitude (in meters)
	 */
	double m_altitude; // GGA field 9

	// private methods


	/**
	 * Reads an NMEA GGA sentence.
	 *
	 * @param nmeaSentenceBuffer external buffer used to store NMEA GGA sentence
	 * bytes once read. This buffer is expected to have a length of at least
	 * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
	 * @return NMEA sentence reading status code
	 */
	GPS_status_enum readGGA(char *nmeaSentenceBuffer);

protected:

	// protected methods
	/**
	 * Internal method used for fields initialisation.
	 */
	virtual void initData(void);

	/**
	 * Reads and parses an NMEA GGA sentence, extracting 3D positioning and additional data
	 *
	 * @param nmeaSentenceBuffer external buffer used to store NMEA sentence
	 * bytes once read. This buffer is expected to have a length of at least
	 * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes and to contain a previously read
	 * GGA sentence.
	 * @return NMEA sentence reading status code
	 */
	GPS_status_enum parseGGA(char *nmeaSentenceBuffer);

public:
	// public methods
	/**
		 * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
		 * default values.
		 * @param in the input stream where to read sentences
		 */
		GPS3D(Stream *in);

		/**
		 * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
		 * default values, and writing valid sentences to <tt>out</tt>.
		 * @param in the input stream from which sentences are read
		 * @param out the output stream where valid sentences are written
		 */
		GPS3D(Stream *in, Stream *out);

		/**
		 * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
		 * given values, and writing valid sentences to <tt>out</tt>.
		 * @param in the input stream where to read data
		 * @param millisecondsTimeout reading timeout in milliseconds
		 * @param charsTimeout reading timeout in chars
		 * @param out the output stream where to forward read data, if needed
		 */
		GPS3D(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout, Stream *out);

		/**
		 * Reads required sentences from input stream (optionally writing valid ones on output stream),
		 * and extracting positioning data.
		 */
		GPS_status_enum readPositioningData(char *nmeaRmcSentenceBuffer, char *nmeaGgaSentenceBuffer);

		/**
		 * Getter for number of satellites in use
		 * @return number of satellites in use
		 */
		int getSatellitesInUse(void);

		/**
		 * Getter for HDOP
		 * @return HDOP
		 */
		double getHDOP(void);

		/**
		 * Getter for altitude (in m)
		 * @return altitude, as mm.m
		 */
		double getAltitude(void);
};
#endif
