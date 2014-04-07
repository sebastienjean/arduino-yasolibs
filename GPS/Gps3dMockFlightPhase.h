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

#ifndef GPS3DMOCKFLIGHTPHASE_H_
#define GPS3DMOCKFLIGHTPHASE_H_
#include "Gps3dMockDef.h"
#include <IFlightPhasePanelControl.h>

class Gps3dMockRunningContext;
/**
 * Define a system flight phase.
 * It describes a state of a Gps3dMock with an automatic simulation
 */
class Gps3dMockFlightPhase {
private :
	// link with the parent
	IFlightPhasePanelControl *m_parent;
protected:
	Gps3dMockFlightPhase(IFlightPhasePanelControl *const parent);
	void ChangeFlightPhase(FlightPhases newPhase)
	{
		m_parent->ChangeFlightPhase(newPhase);
	}
public:
	virtual ~Gps3dMockFlightPhase();
	  /* update the phase following the running context
	   * @param context : flight running context
	   */
	virtual void Run(Gps3dMockRunningContext *const context)=0;

	  /* action executed on state entry
	   * @param context : flight running context
	   */
	virtual void OnEntry(Gps3dMockRunningContext *const context)=0;

	/* compute the current altitude
	   * @param context : flight running context
	   * @return : current alitude in m
	   */
	virtual double GetAltitude(Gps3dMockRunningContext *const context)=0;

};

#endif /* GPS3DMOCKFLIGHTPHASE_H_ */
