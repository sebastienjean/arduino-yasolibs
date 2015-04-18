/*
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

#ifndef PHASEREADYTOTAKEOFF_H_
#define PHASEREADYTOTAKEOFF_H_
#include "mock/Gps3dMockDef.h"
#include "mock/Gps3dMockFlightPhase.h"

class Gps3dMockRunningContext;

/**
 * Define a system ready to take off
  */
class PhaseReadyToTakeOff:public Gps3dMockFlightPhase {
public:
	  /**
	   * Creates the phase.
	   * @param parent: states parent
	   */
	PhaseReadyToTakeOff(IFlightPhasePanelControl *const parent);
	virtual ~PhaseReadyToTakeOff();

	  /* action executed on state entry
	   * @param context : flight running context
	   */
	inline virtual void OnEntry(Gps3dMockRunningContext *const context)
	{
	}
	  /* update the phase following the running context
	   * @param context : flight running context
	   */
	virtual void Run(Gps3dMockRunningContext *const context);
	/* compute the current altitude
	   * @param context : flight running context
	   * @return : current alitude in m
	   */
	virtual double GetAltitude(Gps3dMockRunningContext *const context);

};

#endif /* PHASEREADYTOTAKEOFF_H_ */
