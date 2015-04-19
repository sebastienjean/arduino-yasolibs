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

#include <core/Logger.h>
#include <inttypes.h>
#include <SD.h>

/**
 * This class allows to log raw bytes or text lines on a given file stored on a FAT32 formatted SD card.
 */
class SDFileLogger: public Logger {
private:

	/**
	 * Destination file path
	 */
	char *filePath;

	/**
	 * SD used to log messages
	 */
	SDClass *sd;

	/**
	 * Post-write delay, in milliseconds
	 */
	uint16_t millis;

public:

	/**
	 * Creates a new logger, for given SD and destination file path
	 *
	 * @param path destination file path
	 */
	SDFileLogger(SDClass *sd, char *path);

	/**
	 * Creates a new logger, for given SD, destination file path,
	 * and specified delay in ms after writing.
	 *
	 * @param path destination file path
	 */
	SDFileLogger(SDClass *sd, char *path, uint16_t millis);

	boolean
	logMessage(char *message, boolean newLine);

	boolean
	logMessage(byte messageBytes[], uint16_t amount);

	/**
	 * Erases log file content.
	 * @return log file deletion status
	 */
	boolean
	clear(void);
};

#endif

