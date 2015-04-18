/*
 * DigitalIOBoard.h
 *
 *  Created on: 23 mars 2014
 *      Author: Christian
 */

#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

#include <ext/IDigitalOutput.h>

class DigitalOutput:public IDigitalOutput {
private :
	unsigned char m_pinNumber;
protected :

public:
	DigitalOutput(unsigned char pinNumber);
	virtual ~DigitalOutput();
	virtual void SetOn();
	virtual void SetOff();
    virtual void SetOn(unsigned long timeInMs);
    virtual void SetOff(unsigned long timeInMs);
protected:
	inline int GetPinNumber()
	{
		return m_pinNumber;
	}


};

#endif /* DIGITALIOBOARD_H_ */
