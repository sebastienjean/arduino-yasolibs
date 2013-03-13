/*
* Copyright (c) 2012-2013 Sebastien Jean.
* 
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the GNU Lesser Public License v3.0
* which accompanies this distribution, and is available at
* http://www.gnu.org/licenses/lgpl-3.0.html
* 
* Contributors:
*     Sebastien Jean - initial API and implementation
*/

#include <Arduino.h> 
#include <GPS2D.h>

void GPS2D::initData()
{
	m_fixStatus = false;
	strcpy(m_timeOfFix,"000000");
	m_latitude = 0.0;
	m_longitude = 0.0;
	m_speedOverGround = 0.0;
	m_courseOverGround = 0.0;
}

GPS2D::GPS2D(Stream *in) : GPS::GPS(in)
{
	GPS2D::initData();
}

GPS2D::GPS2D(Stream *in, Stream *out) : GPS::GPS(in, out)
{
	GPS2D::initData();
}

GPS2D::GPS2D(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout, Stream *out) : GPS::GPS(in, millisecondsTimeout, charsTimeout, out)
{
	GPS2D::initData();
}

GPS_status_enum GPS2D::readRMC()
{
	m_nmeaSentenceBuffer[0] = '$';
	m_nmeaSentenceBuffer[1] = 'G';
	m_nmeaSentenceBuffer[2] = 'P';
	m_nmeaSentenceBuffer[3] = 'R';
	m_nmeaSentenceBuffer[4] = 'M';
	m_nmeaSentenceBuffer[5] = 'C';

	return readNMEA();
}

GPS_status_enum GPS2D::parseRMC()
{
	int startOfFieldOffset = 0;
	int endOfFieldOffset = 0;

	GPS_status_enum status = readRMC();

	if (status == GPS_OK)
	{
		// Time of Fix extraction
		startOfFieldOffset = findStartOfFieldOffset(RMC_TIME_OF_FIX_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		// Some GPS give time with decimal of seconds, so length of field should be more than 6
		strncpy(m_timeOfFix, m_nmeaSentenceBuffer+startOfFieldOffset, sizeof(m_timeOfFix)-1);
		for (int i=0;i<sizeof(m_timeOfFix)-1; i++)
		{
			if ((m_timeOfFix[i] < '0')||(m_timeOfFix[i] > '9'))
			{
				strcpy(m_timeOfFix, "000000");
				break;
			}
		}

		// Fix extraction
		startOfFieldOffset = findStartOfFieldOffset(RMC_FIX_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		if (m_nmeaSentenceBuffer[startOfFieldOffset] == 'A') m_fixStatus = true;

		// Latitude extraction
		startOfFieldOffset = findStartOfFieldOffset(RMC_LATITUDE_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(RMC_LATITUDE_INDICATOR_FIELD_NUMBER) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_latitude = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';
		if (m_nmeaSentenceBuffer[endOfFieldOffset+1] == 'S')
			m_latitude = -m_latitude;

		// Longitude extraction
		startOfFieldOffset = endOfFieldOffset+3;
		endOfFieldOffset = findStartOfFieldOffset(RMC_LONGITUDE_INDICATOR_FIELD_NUMBER) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_longitude = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';
		if (m_nmeaSentenceBuffer[endOfFieldOffset+1] == 'W')
			m_longitude = -m_longitude;

		// Speed over ground extraction
		startOfFieldOffset = findStartOfFieldOffset(RMC_SPEED_OVER_GROUND_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(RMC_SPEED_OVER_GROUND_FIELD_NUMBER+1) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_speedOverGround = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';

		// Course over ground extraction
		startOfFieldOffset = findStartOfFieldOffset(RMC_COURSE_OVER_GROUND_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(RMC_COURSE_OVER_GROUND_FIELD_NUMBER+1) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_courseOverGround = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';
	}
	return status;
}

GPS_status_enum GPS2D::readPositioningData()
{
	GPS2D::initData();
	return parseRMC();
}

boolean GPS2D::getFix()
{
	return m_fixStatus;
}


char* GPS2D::getTimeOfFix()
{
	return m_timeOfFix;
}

double GPS2D::getLatitude()
{
	return m_latitude;
}

double GPS2D::getLongitude()
{
	return m_longitude;
}

double GPS2D::getSpeedOverGround()
{
	return m_speedOverGround;
}

double GPS2D::getCourseOverGround()
{
	return m_courseOverGround;
}
