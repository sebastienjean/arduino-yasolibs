/*
 * IDigitalIO.h
 *
 *  Created on: 23 mars 2014
 *      Author: Christian
 */

#ifndef IDIGITALOUTPUT_H_
#define IDIGITALOUTPUT_H_

// interface with the hardware
class IDigitalOutput {
protected :
	IDigitalOutput();

public:
	virtual ~IDigitalOutput();
	virtual void SetOn()=0;
	virtual void SetOff()=0;
	virtual void SetOn(unsigned long timeInMs)=0;
	virtual void SetOff(unsigned long timeInMs)=0;
};

#endif /* IDIGITALIO_H_ */
