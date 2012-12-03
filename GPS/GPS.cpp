/*
* Copyright (c) 2012 Sebastien Jean.
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

GPS::GPS(Stream *in, uint16_t millisecondsTimeout, uint16_t charsTimeout)
{
    this->in = in;
	this->millisecondsTimeout = millisecondsTimeout;
	this->charsTimeout = charsTimeout;
}

GPS_status_enum GPS::readNMEA(char *nmeaString)
{
    unsigned char offset = 0;
    unsigned char state = 0;
    
	char c;
    unsigned int num = 0;
	unsigned long time = millis();

    while (1)
    {
		if (millis() - time > this->millisecondsTimeout) return GPS_TIMEOUT;
        		
        if (!(this->in->available())) continue;
				
		c = this->in->read();

		if (num++ >= this->charsTimeout) return GPS_NOT_NMEA;
		
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
            if (c != nmeaString[state])
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
                nmeaString[offset++] = c;
            }
            else
            {
                state = 0;
            }
        }
        continue;
    }
	
	nmeaString[offset++] = '\r';
	nmeaString[offset++] = '\n';
    nmeaString[offset] = '\0';
    return GPS_OK;
}

GPS_status_enum GPS::readRMC(char *result)
{
    result[0] = '$';
    result[1] = 'G';
    result[2] = 'P';
    result[3] = 'R';
    result[4] = 'M';
    result[5] = 'C';
    return this->readNMEA(result);
}

GPS_status_enum  GPS::readGGA(char *result)
{
    result[0] = '$';
    result[1] = 'G';
    result[2] = 'P';
    result[3] = 'G';
    result[4] = 'G';
    result[5] = 'A';
    return this->readNMEA(result);
}
