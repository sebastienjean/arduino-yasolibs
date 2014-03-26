/*
 * LedV2.cpp
 *
 *  Created on: 24 mars 2014
 *      Author: Christian
 */

#include <LedV2.h>

LedV2::LedV2(IDigitalOutput &output):m_output(&output),m_isOn(false) {
	// TODO Auto-generated constructor stub

}

LedV2::~LedV2() {
	// TODO Auto-generated destructor stub
}

void LedV2::SetOn() {
	m_output->SetOn();
	m_isOn=true;
}

void LedV2::SetOff() {
	m_output->SetOff();
	m_isOn=false;
}

void LedV2::Set(bool toHighLevel) {
	if(toHighLevel) SetOn();
	else SetOff();
}

void LedV2::BlinkSeveralTimes(int times) {
	while(times-->0)
	{
		m_output->SetOn(OutputStateHoldingTime);
		m_output->SetOff(OutputStateHoldingTime);
	}
}
