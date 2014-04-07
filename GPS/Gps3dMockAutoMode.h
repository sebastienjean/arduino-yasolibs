/*
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
#ifndef GPS3DMOCKAUTOMODE_H_
#define GPS3DMOCKAUTOMODE_H_
#include "IGps3d.h"
#include "Gps3dMockDef.h"
#include <IFlightPhasePanelControl.h>
#include <PhaseReadyToTakeOff.h>
#include <PhaseAscending.h>
#include <PhaseDescending.h>
#include <PhaseLanded.h>

class Gps3dMockRunningContext;

/**
 * A NMEA GPS mock, simulating automatically a system flight
 */
class Gps3dMockAutoMode:public IGps3d,public IFlightPhasePanelControl {

private :
	// running context
	Gps3dMockRunningContext *const m_runningContext;

	// flight state
	Gps3dMockFlightPhase *m_currentPhase;

	// flight phases definition
	PhaseReadyToTakeOff m_readyToTakeOff;
	PhaseAscending m_ascendingPhase;
	PhaseDescending m_descendingPhase;
	PhaseLanded m_landedPhase;

public:

	  /**
	   * Creates a Gps mock.
	   * @param runningContext: define all flight parameters
	   */
	Gps3dMockAutoMode(Gps3dMockRunningContext *const runningContext);
	virtual ~Gps3dMockAutoMode();

	  /* Getter for Fix status
	   * @return fix status
	   */
	  inline virtual boolean getFix(void) const
	  {return true;} ;


	  /**
	   * Getter for altitude (in m)
	   * @return altitude, as mm.m
	   */
	  virtual double getAltitude(void) const;

	  /**
	   * Reads required sentences from input stream (optionally writing valid ones on output stream),
	   * and extracting positioning data.
	   */
	  virtual GPS_status_enum
	  readPositioningData(char *nmeaRmcSentenceBuffer, char *nmeaGgaSentenceBuffer);


	  /**
	   * Change the flight phase --> mock state.
	   * @param newPhase: new flight phase
	   */
	  virtual void ChangeFlightPhase(FlightPhases newPhase);

};

#endif /* GPS3DMOCKAUTOMODE_H_ */
