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
#include <mock/PhaseDescending.h>

PhaseDescending::PhaseDescending(IFlightPhasePanelControl *const parent):Gps3dMockFlightPhase(parent) {
	// TODO Auto-generated constructor stub

}

PhaseDescending::~PhaseDescending() {
	// TODO Auto-generated destructor stub
}

void PhaseDescending::Run(Gps3dMockRunningContext* const context)
{
	GetAltitude(context);
}

double PhaseDescending::GetAltitude(Gps3dMockRunningContext* const context)
{
	unsigned short altitude=ComputeAltitude(context);
	if(altitude<=0)
		ChangeFlightPhase(Landed);
	return altitude;

}

double PhaseDescending::ComputeAltitude(Gps3dMockRunningContext* const context)
{
	unsigned long deltaTime=context->GetMiliseconds()-context->GetTimeMemory();
	if(deltaTime<=0)
		return 0;
	double altitude=(double)(context->GetMaxAltitude())-(double)(context->GetDescendingSpeed())*deltaTime/3600;
	if(altitude<0)
		return 0;
	return altitude;
}
