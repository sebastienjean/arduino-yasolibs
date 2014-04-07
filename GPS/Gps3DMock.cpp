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

#include <Gps3DMock.h>
#include <Arduino.h>

Gps3DMock::Gps3DMock(GpsSimulationSequence * const sequence,int pinNumber):m_sequence(sequence),m_pinNumber(pinNumber),m_inputSet(false) {
	// TODO Auto-generated constructor stub

}

Gps3DMock::~Gps3DMock() {
	// TODO Auto-generated destructor stub
	pinMode(m_pinNumber,INPUT);
}

GPS_status_enum
Gps3DMock::readPositioningData(char *nmeaRmcSentenceBuffer, char *nmeaGgaSentenceBuffer)
{
	if(digitalRead(m_pinNumber)==HIGH)
	{
		m_sequence->NextData();
	}
	strcpy(nmeaRmcSentenceBuffer,m_sequence->GetCurrentData()->GetFrameRmc());
	strcpy(nmeaGgaSentenceBuffer,m_sequence->GetCurrentData()->GetFramGGa());
	return GPS_OK;
}

