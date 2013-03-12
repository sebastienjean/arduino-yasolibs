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
#include <GPS.h>

GPS::GPS(Stream *in)
{
    m_in = in;
    m_out = NULL;
	m_millisecondsTimeout = DEFAULT_READING_TIMEOUT_VALUE_IN_MILLIS;
	m_charsTimeout = DEFAULT_READING_TIMEOUT_VALUE_IN_CHARS;
}

GPS::GPS(Stream *in, Stream *out)
{
    m_in = in;
    m_out = out;
	m_millisecondsTimeout = DEFAULT_READING_TIMEOUT_VALUE_IN_MILLIS;
	m_charsTimeout = DEFAULT_READING_TIMEOUT_VALUE_IN_CHARS;
}

GPS::GPS(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout, Stream *out)
{
    m_in = in;
    m_out = out;
	m_millisecondsTimeout = millisecondsTimeout;
	m_charsTimeout = charsTimeout;
}

GPS_status_enum GPS::readNMEA()
{
    unsigned char offset = 0;
    unsigned char state = 0;
    
	char c;
    unsigned int num = 0;
	unsigned long time = millis();

    while (1)
    {
		if (millis() - time > m_millisecondsTimeout) return GPS_TIMEOUT;
        		
        if (!(m_in->available())) continue;
				
		c = m_in->read();

		if (num++ >= m_charsTimeout) return GPS_NOT_NMEA;
		
        if (c == '$')
        {
            state = 1;
            continue;
        }
		
        if (state == 0)
        {
            offset = 0;
            continue;
        }
		
        if (state <= 5)
        {
            if (c != m_nmeaSentenceBuffer[state])
            {
                state = 0;
            }
            else
            {
                offset = ++state;
            }
            continue;
        }
		
        if (state == 6)
        {
			
            if ((c == 0x0D) || (c == 0x0A))
            {
                break;
            }
			
            if (offset < MAX_NMEA_SENTENCE_LENGTH - 1)
            {
            	m_nmeaSentenceBuffer[offset++] = c;
            }
            else
            {
                state = 0;
            }
        }
        continue;
    }
	
    m_nmeaSentenceBuffer[offset++] = '\r';
    m_nmeaSentenceBuffer[offset++] = '\n';
    m_nmeaSentenceBuffer[offset] = '\0';

    if (m_out != NULL) m_out->print(m_nmeaSentenceBuffer);
    return GPS_OK;
}

int GPS::findStartOfFieldOffset(int fieldNumber)
{
	if ((fieldNumber<1)||(fieldNumber>9)) return -1;

	for (int i=0;i<MAX_NMEA_SENTENCE_LENGTH;i++)
	{
		if (m_nmeaSentenceBuffer[i] == '\0') return -1;

		if (m_nmeaSentenceBuffer[i] == ',') fieldNumber -= 1;

		if (fieldNumber == 0) return i+1;
	}
	return -1;
}

