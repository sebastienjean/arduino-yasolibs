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
#include <GPS3D.h>
#include <GPS2D.h>

void GPS3D::initData()
{
	GPS2D::initData();
	m_satellitesInUse = 0;
	m_hdop = 0.0;
	m_altitude = 0.0;
}

GPS3D::GPS3D(Stream *in) : GPS2D::GPS2D(in)
{
	GPS3D::initData();
}

GPS3D::GPS3D(Stream *in, Stream *out) : GPS2D::GPS2D(in, out)
{
	GPS3D::initData();
}

GPS3D::GPS3D(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout, Stream *out) : GPS2D::GPS2D(in, millisecondsTimeout, charsTimeout, out)
{
	GPS3D::initData();
}

GPS_status_enum GPS3D::readGGA()
{
	m_nmeaSentenceBuffer[0] = '$';
	m_nmeaSentenceBuffer[1] = 'G';
	m_nmeaSentenceBuffer[2] = 'P';
	m_nmeaSentenceBuffer[3] = 'G';
	m_nmeaSentenceBuffer[4] = 'G';
	m_nmeaSentenceBuffer[5] = 'A';

	return readNMEA();
}

GPS_status_enum GPS3D::parseGGA()
{
	int startOfFieldOffset = 0;
	int endOfFieldOffset = 0;

	GPS_status_enum status = readGGA();

	if (status == GPS_OK)
	{
		// Satellites in use extraction
		startOfFieldOffset = findStartOfFieldOffset(GGA_SATS_IN_USE_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(GGA_SATS_IN_USE_FIELD_NUMBER+1) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_satellitesInUse = atoi(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';

		// HDOP extraction
		startOfFieldOffset = findStartOfFieldOffset(GGA_HDOP_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(GGA_HDOP_FIELD_NUMBER+1) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_hdop = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';

		// Altitude extraction
		startOfFieldOffset = findStartOfFieldOffset(GGA_ALTITUDE_FIELD_NUMBER);
		if (startOfFieldOffset == -1) return status;
		endOfFieldOffset = findStartOfFieldOffset(GGA_ALTITUDE_FIELD_NUMBER+1) -1;
		if (endOfFieldOffset < 0) return status;
		m_nmeaSentenceBuffer[endOfFieldOffset] = '\0';
		m_altitude = atof(m_nmeaSentenceBuffer+startOfFieldOffset);
		m_nmeaSentenceBuffer[endOfFieldOffset] = ',';
	}
	return status;
}

GPS_status_enum GPS3D::readPositioningData()
{
	GPS_status_enum status = GPS2D::readPositioningData();

	if (status == GPS_OK)
		status = parseGGA();
	return status;

}

int GPS3D::getSatellitesInUse()
{
	return m_satellitesInUse;
}

double GPS3D::getHDOP()
{
	return m_hdop;
}

double GPS3D::getAltitude()
{
	return m_altitude;
}
