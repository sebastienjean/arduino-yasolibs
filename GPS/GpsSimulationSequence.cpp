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

#include <GpsSimulationSequence.h>

GpsSimulationSequence::GpsSimulationSequence()
//m_datas(NULL),m_sequenceSize(0),m_currentIndex(0)
{
	// TODO Auto-generated destructor stub

}
GpsSimulationSequence::GpsSimulationSequence(GpsSimulationData const * data[], unsigned short arraySize):
m_datas(data),m_sequenceSize(arraySize),m_currentIndex(0)
{
	// TODO Auto-generated destructor stub
}

GpsSimulationSequence::~GpsSimulationSequence() {
	// TODO Auto-generated constructor stub

}

