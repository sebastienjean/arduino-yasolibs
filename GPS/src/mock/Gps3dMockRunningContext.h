/*
 * Copyright (c) 2013-2014 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 *
 * Contributors:
 *     Khrisp
 */

#ifndef GPS3DMOCKRUNNINGCONTEXT_H_
#define GPS3DMOCKRUNNINGCONTEXT_H_

#include  <Arduino.h>

/**
 * A NMEA GPS mock running context
 */
class Gps3dMockRunningContext {
private:
	// system ascending speed in km/h
	unsigned short m_ascendingSpeed;
	// system descending speed in km/h
	unsigned short m_descendingSpeed;//in m/s
	// altitude to reach before descending
	unsigned short m_maxAltitude;// in m
	// intermediary time memory
	unsigned long m_timeMemory;
	// simulation start input pin number
	int m_pinNumber;

public:
  /**
   * Creates a Gps mock running context. It defines the simulation parameters
   * @param ascendingSpeed: system ascending speed in km/h
   * @param descendingSpeed: system descending speed in km/h
   * @param maxAltitude: altitude in m to reach before to start the descending phase
   * @param pinNumber: pin number to start the simulation
   */
	Gps3dMockRunningContext(unsigned short ascendingSpeed,unsigned short descendingSpeed,
							unsigned short maxAltitude,int pinNumber);
	virtual ~Gps3dMockRunningContext();


  /**
   * Get time since the program start
   * @return time in ms
   */
	inline unsigned long GetMiliseconds()const
	{ return millis();}

  /**
   * Indicate if the flight has started.
   * @return true if the flight has started, false otherwise
   */
	inline bool IsTakeOffOccurs() const
	{ return digitalRead(m_pinNumber)==HIGH;}

  /**
   * Get the system Ascending speed
   * @return speed in km/h
   */
	inline unsigned short GetAscendingSpeed() const
	{ return m_ascendingSpeed;}

  /**
   * Get the system descending speed
   * @return speed in km/h
   */
	inline unsigned short GetDescendingSpeed() const
	{ return m_descendingSpeed;}

  /**
   * Get the altitude to reach before to start the descending phase
   * @return altitude in m
   */
	inline unsigned short GetMaxAltitude() const
	{ return m_maxAltitude;}

  /**
   * Get time recorded
   */
	inline unsigned long GetTimeMemory() const
	{ return m_timeMemory;}

  /**
   * record a time value
   */
	inline void MemorizeTime(unsigned long value)
	{ m_timeMemory=value;}

};

#endif /* GPS3DMOCKRUNNINGCONTEXT_H_ */
