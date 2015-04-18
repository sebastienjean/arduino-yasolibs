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

#include <core/Leds.h>
#include <core/Led.h>

Leds::Leds(Led** leds, int ledsAmount)
{
  this->leds = leds;
  this->ledsAmount = ledsAmount;
}

void
Leds::on()
{
  for (int ledNumber = 0; ledNumber < this->ledsAmount; ledNumber++)
      (this->leds[ledNumber])->on();
}

void
Leds::off()
{
  for (int ledNumber = 0; ledNumber < this->ledsAmount; ledNumber++)
      (this->leds[ledNumber])->off();
}

void
Leds::quicklyMakeBlinkSeveralTimes(int times)
{
  for (int time = 0; time < times; time++)
    {
      this->on();
      delay(100);
      this->off();
      delay(100);
    }
}

