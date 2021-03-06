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

#include <mock/Gps3dMockRunningContext.h>
#include <mock/PhaseReadyToTakeOff.h>

PhaseReadyToTakeOff::PhaseReadyToTakeOff(IFlightPhasePanelControl *const parent):Gps3dMockFlightPhase(parent) {
	// TODO Auto-generated constructor stub

}

PhaseReadyToTakeOff::~PhaseReadyToTakeOff() {
	// TODO Auto-generated destructor stub
}

void PhaseReadyToTakeOff::Run(Gps3dMockRunningContext *const context)
{
	if(context->IsTakeOffOccurs()==true)
		ChangeFlightPhase(Ascending);
}

double PhaseReadyToTakeOff::GetAltitude(Gps3dMockRunningContext *const context)
{
	Run(context); //update to check a flight phase change
	return 0;
}
