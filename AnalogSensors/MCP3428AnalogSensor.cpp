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

#include <MCP3428.h>
#include <MCP3428AnalogSensor.h>

MCP3428AnalogSensor::MCP3428AnalogSensor(MCP3428 *mcp3428, int channel)
{
  this->mcp3428 = mcp3428;
  this-> channel = channel;
}

int
MCP3428AnalogSensor::read(void)
{
  return this->mcp3428->read(this->channel);
}
