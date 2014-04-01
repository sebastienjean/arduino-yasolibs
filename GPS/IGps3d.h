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

#ifndef IGPS3D_H_
#define IGPS3D_H_
#include <Arduino.h>
#include <GpsUtil.h>

/**
 * A NMEA GPS Interface, describing the GPs3D behaviour
 */
class IGps3d {
public:
	virtual ~IGps3d();
	  /* Getter for Fix status
	   * @return fix status
	   */
	  virtual boolean
	  getFix(void) const =0 ;


	  /**
	   * Getter for altitude (in m)
	   * @return altitude, as mm.m
	   */
	  virtual double getAltitude(void) const=0;

	  /**
	   * Reads required sentences from input stream (optionally writing valid ones on output stream),
	   * and extracting positioning data.
	   */
	  virtual GPS_status_enum
	  readPositioningData(char *nmeaRmcSentenceBuffer, char *nmeaGgaSentenceBuffer)=0;

protected:
	IGps3d();
};

#endif /* IGPS3D_H_ */
