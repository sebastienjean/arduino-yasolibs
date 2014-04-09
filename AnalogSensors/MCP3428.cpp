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
#include <Wire.h>
#include <Arduino.h>

MCP3428::MCP3428(boolean addressBit0, boolean addressBit1)
{
  this->address = MCP3428_BASE_ADDRESS;
  if (addressBit0) this->address = (this->address & 0b00000100);
  if (addressBit1) this->address = (this->address & 0b00000010);

  Wire.begin();
}

int
MCP3428::read(int channel)
{
   //uint16_t result = 0;
   return 0;
   // TODO to be completed
}
