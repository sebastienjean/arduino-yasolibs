/*
 * Copyright (c) 2013-2014 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 * Contributors:
 *     Khrisp
 */

#ifndef GPSUTIL_H_
#define GPSUTIL_H_

/**
 * Maximum length of NMEA sentences (NMEA 0183 defines maximum as 82)
 */
#define MAX_NMEA_SENTENCE_LENGTH 85 // NMEA 0183 maximum is 82

/**
 * Default timeout for each sentence reading, in milliseconds
 */
#define DEFAULT_READING_TIMEOUT_VALUE_IN_MILLIS 2000;

/**
 * Default timeout for each sentence reading, in characters
 */
#define DEFAULT_READING_TIMEOUT_VALUE_IN_CHARS 2000;

/**
 * Status codes for GPS readings
 */
typedef enum
{
  GPS_OK = 0,     	   //!< GPS_OK reading is successful
  GPS_TIMEOUT = 1,     //!< GPS_TIMEOUT timeout occurred while reading
  GPS_NOT_NMEA = 2     //!< GPS_NOT_NMEA chars limit reached while reading
} GPS_status_enum;

#endif /* GPSUTIL_H_ */
