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
#include <Gps3dMockRunningContext.h>
#include <PhaseAscending.h>

PhaseAscending::PhaseAscending(IFlightPhasePanelControl *const parent):Gps3dMockFlightPhase(parent) {
	// TODO Auto-generated constructor stub

}

PhaseAscending::~PhaseAscending() {
	// TODO Auto-generated destructor stub
}

void PhaseAscending::Run(Gps3dMockRunningContext* const context)
{
	GetAltitude(context);
}

double PhaseAscending::GetAltitude(Gps3dMockRunningContext* const context)
{
	unsigned short altitude=ComputeAltitude(context);
	if(altitude>context->GetMaxAltitude())
		ChangeFlightPhase(Descending);
	return altitude;
}

double PhaseAscending::ComputeAltitude(Gps3dMockRunningContext* const context)
{
	unsigned long deltaTime=context->GetMiliseconds()-context->GetTimeMemory();
	if(deltaTime<=0)
		return 0;
	return ((double)(context->GetAscendingSpeed())*deltaTime/3600);
}
