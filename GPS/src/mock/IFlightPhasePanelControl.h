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

#ifndef IFLIGHTPHASEPANELCONTROL_H_
#define IFLIGHTPHASEPANELCONTROL_H_
#include <mock/Gps3dMockDef.h>

/**
 * interface defining a flight phase parent
 */
class IFlightPhasePanelControl {
protected :
	IFlightPhasePanelControl();

public:
	virtual ~IFlightPhasePanelControl();

	/**
	   * Change the flight phase
	   * @param newPhase: new flight phase
	   */
	virtual void ChangeFlightPhase(FlightPhases newPhase)=0;

};

#endif /* IFLIGHTPHASEPANELCONTROL_H_ */
