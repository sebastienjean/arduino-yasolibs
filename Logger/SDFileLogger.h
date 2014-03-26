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

#ifndef SDFILE_LOGGER_h
#define SDFILE_LOGGER_h

#include <SD.h>

/**
 * This class allows to log raw bytes or text lines on a given file stored on a FAT32 formatted SD card.
 * This class has no constructor but a singleton instance called LOGGER.
 */
class SDFileLogger
{
private:

  /**
   * Destination file path
   */
  char *filePath;

  /**
   * SD used to log messages
   */
  SDClass *sd;

public:

  /**
   * Creates a new logger, for given SD and destination file path
   *
   * @param path destination file path
   */

  SDFileLogger(SDClass *sd, char *path);

  /**
   * Logs a message, with or without appending new line.
   *
   * @param message the string to be logged
   * @param newLine line termination characters appending (if true)
   * @return logging success status
   */
  boolean
  logMessage(char *message, boolean newLine);

  /**
   * Erases log file content.
   * @return log file deletion status
   */
  boolean
  clear(void);
};

#endif

