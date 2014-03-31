/*
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

#ifndef GPS3DMOCK_H_
#define GPS3DMOCK_H_

#include <IGps3d.h>
#include <GpsSimulationSequence.h>

/**
 * A NMEA GPS mock, to simulate a GPS3D behaviour
 */
class Gps3DMock: public IGps3d {
private :
	GpsSimulationSequence *const m_sequence;
	int m_pinNumber;
	bool m_inputSet;

public:
	Gps3DMock(GpsSimulationSequence *sequence,int pinNumber);
	virtual ~Gps3DMock();

	  /* Getter for Fix status
	   * @return fix status
	   */
	 virtual boolean getFix(void) const
	 {
		  return m_sequence->GetCurrentData()->IsvalidData()==true;
	  }


	  /**
	   * Getter for altitude (in m)
	   * @return altitude, as mm.m
	   */
	  inline virtual double getAltitude(void) const
	  {
		  return m_sequence->GetCurrentData()->GetAltitude();
	  }

	  /**
	   * Reads required sentences from input stream (optionally writing valid ones on output stream),
	   * and extracting positioning data.
	   */
	  virtual GPS_status_enum
	  readPositioningData(char *nmeaRmcSentenceBuffer, char *nmeaGgaSentenceBuffer);


};

#endif /* GPS3DMOCK_H_ */
