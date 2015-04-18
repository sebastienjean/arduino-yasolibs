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

#ifndef PHASEASCENDING_H_
#define PHASEASCENDING_H_

#include <mock/Gps3dMockDef.h>
#include <mock/Gps3dMockFlightPhase.h>


class Gps3dMockRunningContext;

/**
 * Define a system ascending phase.
  */
class PhaseAscending: public Gps3dMockFlightPhase {
public:

	  /**
	   * Creates an ascending phase.
	   * @param parent: states parent
	   */
	PhaseAscending(IFlightPhasePanelControl *const parent);
	virtual ~PhaseAscending();

	  /* action executed on state entry
	   * @param context : flight running context
	   */
	inline virtual void OnEntry(Gps3dMockRunningContext *const context)
	{
		context->MemorizeTime(context->GetMiliseconds());
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
private :

	/* compute the current altitude
	   * @param context : flight running context
	   * @return : current alitude in m
	   */
	double ComputeAltitude(Gps3dMockRunningContext *const context);
};

#endif /* PHASEASCENDING_H_ */
