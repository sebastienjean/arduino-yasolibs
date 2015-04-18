/*
 * DigitalOutputInverted2.cpp
 *
 *  Created on: 24 mars 2014
 *      Author: Christian
 */

#include <ext/DigitalOutputInverted.h>
#include <Arduino.h>

DigitalOutputInverted::DigitalOutputInverted(unsigned char pinNumber):DigitalOutput(pinNumber) {
	// TODO Auto-generated constructor stub

}

DigitalOutputInverted::~DigitalOutputInverted() {
	// TODO Auto-generated destructor stub
}

void DigitalOutputInverted::SetOn()
{
	digitalWrite(GetPinNumber(),LOW);
}

void DigitalOutputInverted::SetOff()
{
	digitalWrite(GetPinNumber(),HIGH);
}
