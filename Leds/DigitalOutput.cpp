/*
 * DigitalIOBoard.cpp
 *
 *  Created on: 23 mars 2014
 *      Author: Christian
 */

#include <DigitalOutput.h>
#include <Arduino.h>

DigitalOutput::DigitalOutput(unsigned char pinNumber):m_pinNumber(pinNumber) {
	// TODO Auto-generated constructor stub
	pinMode(m_pinNumber, OUTPUT);

}

DigitalOutput::~DigitalOutput() {
	// TODO Auto-generated destructor stub
}

void DigitalOutput::SetOn(unsigned long timeInMs)
{
	SetOn();
	delay(timeInMs);
}

void DigitalOutput::SetOff(unsigned long timeInMs)
{
	SetOff();
	delay(timeInMs);
}

void DigitalOutput::SetOn()
{
	digitalWrite(m_pinNumber,HIGH);
}

void DigitalOutput::SetOff()
{
	digitalWrite(m_pinNumber,LOW);
}
