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

#ifndef PHASELANDED_H_
#define PHASELANDED_H_

#include <Gps3dMockFlightPhase.h>

class Gps3dMockRunningContext;

/**
 * Define a system that landed
  */
class PhaseLanded: public Gps3dMockFlightPhase {
public:
	  /**
	   * Creates a landed phase.
	   * @param parent: states parent
	   */
	PhaseLanded(IFlightPhasePanelControl *const parent);
	virtual ~PhaseLanded();

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
	inline virtual void Run(Gps3dMockRunningContext *const context)
	{}
	/* compute the current altitude
	   * @param context : flight running context
	   * @return : current alitude in m
	   */
	virtual double GetAltitude(Gps3dMockRunningContext *const context)
	{return 0;}


};

#endif /* PHASELANDED_H_ */
