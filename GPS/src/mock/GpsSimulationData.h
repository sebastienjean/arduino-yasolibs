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

#ifndef GPSSIMULATIONDATA_H_
#define GPSSIMULATIONDATA_H_
#include <core/GpsUtil.h>
#include <core/GPS.h>

/**
 * data structure used to simulate the GPS functionning
 */
class GpsSimulationData {

private :
	char m_frameRmc[MAX_NMEA_SENTENCE_LENGTH];
	char m_frameGga[MAX_NMEA_SENTENCE_LENGTH];
	double m_latitude;
	double m_longitude;
	double m_altitude;
	bool m_isValidData;/* true if all data are valid, false otherwise */

public:
	/**
	 * Constructor
     * @param frameRmc external buffer used to store NMEA RMC sentence
     * This buffer is expected to have a length of at least <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
     * @param frameGga external buffer used to store NMEA GGA sentence
     * This buffer is expected to have a length of at least <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
     * @param latitude : latidue in (-/+ddmm.m)
     * @param longitude : longitude in (-/+ddmm.m)
     * @param altitude : latidue in (m)
     * @param isValid : true to indicate valid data, false otherwise
 	 */
	GpsSimulationData(char const*const frameRmc,char const*const frameGga,double latitude,double longitude,double altitude,bool isValid);
	virtual ~GpsSimulationData();
protected:
	GpsSimulationData();

public:
  /**
   * Latitude in (-/+ddmm.m)
   */
	inline double GetLatitude()const
	{return m_latitude;}

  /**
   * Longitude in (-/+ddmm.m)
   */
	inline double GetLongitude()const
	{return m_longitude;}

  /**
   * Altitude in m
   */
	inline double GetAltitude()const
	{return m_altitude;}

  /**
   * true if data are valid, false otherwise
   */
	inline bool IsvalidData()const
	{return m_isValidData;}

  /**
   * NMEA RMC sentence
   * This buffer has a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
   */
	inline char const*const GetFrameRmc()const
	{return m_frameRmc;}

  /**
   * NMEA RMC sentence
   * This buffer has a length of at least
   * <tt>MAX_NMEA_SENTENCE_LENGTH</tt> bytes.
   */
	inline char const * const GetFramGGa()const
	{return m_frameGga;}

};

#endif /* GPSSIMULATIONDATA_H_ */
