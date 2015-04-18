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

#include <mock/GpsSimulationData.h>

GpsSimulationData::GpsSimulationData(const char* const frameRmc,const char* const frameGga, double latitude, double longitude,
									double altitude, bool isValid):m_latitude(latitude),m_longitude(longitude),m_altitude(altitude),m_isValidData(isValid)
{
	strncpy(m_frameRmc,frameRmc,sizeof(m_frameRmc));
	strncpy(m_frameGga,frameGga,sizeof(m_frameGga));
}

GpsSimulationData::~GpsSimulationData() {
	// TODO Auto-generated destructor stub
}

