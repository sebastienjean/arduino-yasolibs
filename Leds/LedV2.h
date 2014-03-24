/*
 * LedV2.h
 *
 *  Created on: 24 mars 2014
 *      Author: Christian
 */

#ifndef LEDV2_H_
#define LEDV2_H_
#include <IDigitalOutput.h>
class LedV2 {
private :
	static const unsigned long OutputStateHoldingTime=100; // in ms
	bool m_isOn;
	IDigitalOutput *m_output;

public:
	LedV2(IDigitalOutput &output);
	virtual ~LedV2();
	void SetOn();
	void SetOff();
	void Set(bool toHighLevel);
	virtual void BlinkSeveralTimes(int times);
};

#endif /* LEDV2_H_ */
