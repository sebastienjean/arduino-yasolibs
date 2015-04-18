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

#ifndef GPS_h
#define GPS_h

#include <inttypes.h>
#include <Stream.h>
#include <core/GpsUtil.h>
/**
 * A NMEA GPS, reading sentences from an input stream (with timeouts), optionally writing
 * valid sentences to an output stream. This class in an abstract class, defining commons
 * functions for 2D and 3D positioning.
 */
class GPS
{
private:
  // per object data
  /**
   * NMEA sentences input stream
   */
  Stream *m_in;

  /**
   * Reading timeout in milliseconds
   */
  uint16_t m_millisecondsTimeout;

  /**
   * Reading timeout in chars
   */
  uint16_t m_charsTimeout;

  /**
   * NMEA sentences output stream
   */
  Stream *m_out;

public:

  // public methods

  /**
   * Creates a new GPS instance, reading sentences from <tt>in</tt> with timeouts set to
   * default values.
   * @param in the input stream where to read sentences
   */
  GPS(Stream *in);

  /**
   * Creates a new GPS instance, reading sentences from <tt>in</tt> with timeouts set to
   * default values, and writing valid sentences to <tt>out</tt>.
   * @param in the input stream from which sentences are read
   * @param out the output stream where valid sentences are written
   */
  GPS(Stream *in, Stream *out);

  /**
   * Creates a new GPS instance, reading sentences from <tt>in</tt> with timeouts set to
   * given values, and writing valid sentences to <tt>out</tt>.
   * @param in the input stream where to read data
   * @param millisecondsTimeout reading timeout in milliseconds
   * @param charsTimeout reading timeout in chars
   * @param out the output stream where to forward read data, if needed
   */
  GPS(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout,
      Stream *out);

  /**
   * Reads an NMEA sentence.
   * <tt>m_nmeaSentenceBuffer</tt> is supposed to be preloaded with the beginning of
   * the sentence to be read (e.g. "$GPRMC").
   *
   * @param nmeaSentenceBuffer external buffer used to store NMEA sentence
   * bytes once read. This buffer is expected to have a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
   * @return NMEA sentence reading status code
   */
  GPS_status_enum
  readNMEA(char *nmeaSentenceBuffer);

  /**
   * Finds the offset where a given NMEA sentence field starts (searching for field separator)
   * <tt>m_nmeaSentenceBuffer</tt> is supposed to contain the sentence where to search for field.
   *
   * @param nmeaSentenceBuffer external internal buffer expected to contain a previously read NMEA sentence.
   * @param fieldNumber the number of the field to locate (numbering starts at 1, 0 corresponding to
   * sentence name and not being expected to be searched.
   * @return offset where the field starts if found, -1 else
   */
  int
  findStartOfFieldOffset(char *nmeaSentenceBuffer, int fieldNumber);
};
#endif
