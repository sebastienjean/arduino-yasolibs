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

#ifndef GPS2D_h
#define GPS2D_h

#include <core/GPS.h>

#define RMC_TIME_OF_FIX_FIELD_NUMBER 1

#define RMC_FIX_FIELD_NUMBER 2

#define RMC_LATITUDE_FIELD_NUMBER 3

#define RMC_LATITUDE_INDICATOR_FIELD_NUMBER 4

#define RMC_LONGITUDE_FIELD_NUMBER 5

#define RMC_LONGITUDE_INDICATOR_FIELD_NUMBER 6

#define RMC_SPEED_OVER_GROUND_FIELD_NUMBER 7

#define RMC_COURSE_OVER_GROUND_FIELD_NUMBER 8

/**
 * A NMEA GPS, reading sentences from an input stream (with timeouts), optionally writing
 * valid sentences to an output stream, allowing to get 2D positioning data
 * (using only RMC sentence)
 */
class GPS2D : public GPS
{
private:
  // per object data

  /**
   * Time of fix (UTC time as HHMMSS)
   */
  char m_timeOfFix[7]; // RMC field 1

  /**
   * GPS fix status
   */
  boolean m_fixStatus; // RMC field 2

  /**
   * Latitude in (-/+ddmm.m)
   */
  double m_latitude; // RMC fields 3 and 4

  /**
   * Longitude in (-/+ddmm.m)
   */
  double m_longitude; // RMC fields 5 and 6

  /**
   * Speed over ground (in knots)
   */
  double m_speedOverGround; // RMC field 7

  /**
   * Course over ground (angle relative to magnetic North).
   */
  double m_courseOverGround; // RMC field 8

  /**
   * Reads an NMEA RMC sentence.
   *
   * @param nmeaSentenceBuffer external buffer used to store NMEA RMC sentence
   * bytes once read. This buffer is expected to have a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
   * @return NMEA sentence reading status code
   */
  GPS_status_enum
  readRMC(char *nmeaSentenceBuffer);

protected:

  // protected methods

  /**
   * Internal method used for fields initialisation.
   */
  virtual void
  initData(void);

  /**
   * Reads and parses an NMEA RMC sentence, extracting 2D positioning data
   *
   * @param nmeaSentenceBuffer external buffer used to store NMEA sentence
   * bytes once read. This buffer is expected to have a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes and to contain a previously read
   * RMC sentence.
   * @return NMEA sentence reading status code
   */
  GPS_status_enum
  parseRMC(char *nmeaSentenceBuffer);

public:

  // public methods
  /**
   * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
   * default values.
   * @param in the input stream where to read sentences
   */
  GPS2D(Stream *in);

  /**
   * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
   * default values, and writing valid sentences to <tt>out</tt>.
   * @param in the input stream from which sentences are read
   * @param out the output stream where valid sentences are written
   */
  GPS2D(Stream *in, Stream *out);

  /**
   * Creates a new GPS2D instance, reading sentences from <tt>in</tt> with timeouts set to
   * given values, and writing valid sentences to <tt>out</tt>.
   * @param in the input stream where to read data
   * @param millisecondsTimeout reading timeout in milliseconds
   * @param charsTimeout reading timeout in chars
   * @param out the output stream where to forward read data, if needed
   */
  GPS2D(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout,
      Stream *out);

  /**
   * Reads required sentences from input stream (optionally writing valid ones on output stream),
   * and extracting 2D positioning data.
   *
   * @param nmeaSentenceBuffer external buffer used to store NMEA RMC sentence
   * bytes once read. This buffer is expected to have a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
   * @return NMEA sentence reading status code
   */
  GPS_status_enum
  readPositioningData(char *nmeaRmcSentenceBuffer);

  /**
   * Getter for Fix status
   * @return fix status
   */
  virtual boolean
  getFix(void) const;

  /**
   * Getter for UTC time of fix, as a valid C string
   * @return time of fix, as HHMMSS
   */
  char*
  getTimeOfFix(void);

  /**
   * Getter for latitude
   * @return latitude, as (+/-)ddmm.m
   */
  double
  getLatitude(void);

  /**
   * Getter for longitude
   * @return longitude, as (+/-)ddmm.m
   */
  double
  getLongitude(void);

  /**
   * Getter for speed over ground (in knots)
   * @return speed over ground
   */
  double
  getSpeedOverGround(void);

  /**
   * Getter for course over ground (in relative degree angle to North)
   * @return course over ground, as dd.d (in [0..360])
   */
  double
  getCourseOverGround(void);
};
#endif
