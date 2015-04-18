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

#include <Counter.h>
#include <EEPROM.h>

Counter::Counter(int baseAddress)
{
  this->baseAddress = baseAddress;
}

unsigned int
Counter::read(void)
{
  unsigned int reste = EEPROM.read(this->baseAddress);
  unsigned int quotient = EEPROM.read(this->baseAddress+1);
  return (quotient*256+reste);
}

void
Counter::set(unsigned int value)
{
  unsigned int quotient = value/256;
  unsigned int reste = value%256;
  EEPROM.write(this->baseAddress, reste);
  EEPROM.write(this->baseAddress + 1, quotient);
}

void
Counter::reset()
{
  this->set(0);
}

void
Counter::increment(unsigned int value)
{
  this->set(this->read() + value);
}
