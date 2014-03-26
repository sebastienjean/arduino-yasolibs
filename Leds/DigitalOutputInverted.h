/*
 * DigitalOutputInverted2.h
 *
 *  Created on: 24 mars 2014
 *      Author: Christian
 */

#ifndef DIGITALOUTPUTINVERTED_H_
#define DIGITALOUTPUTINVERTED_H_

#include <DigitalOutput.h>

class DigitalOutputInverted: public DigitalOutput {
public:
	DigitalOutputInverted(unsigned char pinNumber);
	virtual ~DigitalOutputInverted();
	virtual void SetOn();
	virtual void SetOff();
};


#endif /* DIGITALOUTPUTINVERTED_H_ */
