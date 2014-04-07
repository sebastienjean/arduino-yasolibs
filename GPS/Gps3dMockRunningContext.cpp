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

#include <Gps3dMockRunningContext.h>
#include "Arduino.h"
Gps3dMockRunningContext::Gps3dMockRunningContext(unsigned short ascendingSpeed,unsigned short descendingSpeed,
		unsigned short maxAltitude,int pinNumber):m_ascendingSpeed(ascendingSpeed),m_descendingSpeed(descendingSpeed),
		m_maxAltitude(maxAltitude),m_pinNumber(pinNumber),m_timeMemory(0)
{
	// TODO Auto-generated constructor stub
	pinMode(m_pinNumber,INPUT);

}

Gps3dMockRunningContext::~Gps3dMockRunningContext() {
	// TODO Auto-generated destructor stub
}

