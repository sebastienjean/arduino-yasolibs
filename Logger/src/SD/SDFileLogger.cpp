/*
 Copyright (C) 2012 Sebastien Jean <baz dot jean at gmail dot com>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the version 3 GNU General Public License as
 published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <Arduino.h>
#include <SD.h>

#include <core/Logger.h>
#include <SD/SDFileLogger.h>

SDFileLogger::SDFileLogger(SDClass *sd, char * filePath)
{
  this->sd = sd;
  this->filePath = filePath;
  this->millis = 0;
}

SDFileLogger::SDFileLogger(SDClass *sd, char * filePath, uint16_t millis)
{
  this->sd = sd;
  this->filePath = filePath;
  this->millis = millis;
}

boolean
SDFileLogger::logMessage(char *message, boolean newLine)
{
  File logFile = this->sd->open(this->filePath, FILE_WRITE);
  if (logFile)
    {
      if (newLine)
        logFile.println(message);
      else
        logFile.print(message);
      logFile.close();
      if (this->millis > 0) delay(this->millis);
      return true;
    }
  return false;
}

boolean
SDFileLogger::logMessage(byte messageBytes[], uint16_t amount)
{
  File logFile = this->sd->open(this->filePath, FILE_WRITE);
  if (logFile)
    {
      logFile.write((byte *) messageBytes, amount);
      if (this->millis > 0) delay(this->millis);
      return true;
    }
  return false;
}

boolean
SDFileLogger::clear(void)
{
  return this->sd->remove(this->filePath);
}
