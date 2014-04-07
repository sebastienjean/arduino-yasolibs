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
#include <Gps3dMockRunningContext.h>
#include <Gps3dMockAutoMode.h>



Gps3dMockAutoMode::Gps3dMockAutoMode(Gps3dMockRunningContext *const runningContext):m_runningContext(runningContext),m_readyToTakeOff(this),
m_ascendingPhase(this),m_descendingPhase(this),m_landedPhase(this),m_currentPhase(&m_readyToTakeOff)
{
	// TODO Auto-generated constructor stub

}

Gps3dMockAutoMode::~Gps3dMockAutoMode() {
	// TODO Auto-generated destructor stub
}

double Gps3dMockAutoMode::getAltitude(void) const
{
	return m_currentPhase->GetAltitude(m_runningContext);
}

GPS_status_enum Gps3dMockAutoMode::readPositioningData(
		char* nmeaRmcSentenceBuffer, char* nmeaGgaSentenceBuffer)
{
	strcpy(nmeaRmcSentenceBuffer,"constant rmc frame");
	strcpy(nmeaGgaSentenceBuffer,"constant gga frame");
	m_currentPhase->Run(m_runningContext);
	return GPS_OK;

}

void Gps3dMockAutoMode::ChangeFlightPhase(FlightPhases newPhase)
{
	  {
		  bool phaseHasChanged=true;
		  switch(newPhase)
		  {
			  case Ascending:
				  m_currentPhase=&m_ascendingPhase;
				  break;
			  case Descending:
				  m_currentPhase=&m_descendingPhase;
				  break;
			  case Landed:
				  m_currentPhase=&m_landedPhase;
				  break;
			  default:
				  phaseHasChanged=false;
				  break;
		  }
		  if(phaseHasChanged==true)
			  m_currentPhase->OnEntry(m_runningContext);
	  }

}
