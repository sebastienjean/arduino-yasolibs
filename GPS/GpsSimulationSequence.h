/*
 * GpsSimulationSequence.h
 *
 *  Created on: 29 mars 2014
 *      Author: Christian
 */

#ifndef GPSSIMULATIONSEQUENCE_H_
#define GPSSIMULATIONSEQUENCE_H_
#include<GpsSimulationData.h>

/*
 * Copyright (c) 2013-2014 Sebastien Jean.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser Public License v3.0
 * which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-3.0.html
 * Contributors:
 *     Khrisp
 */

/**
 * Gps simulation data sequence.
 * It used to simulate a gps data flow
 */
class GpsSimulationSequence {
private :
	unsigned short m_sequenceSize;
	// gps simulation data sequence
	GpsSimulationData  const** m_datas;
	// current data selected in the sequence
	unsigned int m_currentIndex;

public:
	virtual ~GpsSimulationSequence();

protected:
	/**
	 * Constructor
     * @param datas : list of gps simulation data instances
     * @param arraySize : size of the list
 	 */
	GpsSimulationSequence(GpsSimulationData const *  datas[], unsigned short arraySize);
private:
	GpsSimulationSequence();

public :
	/**
	 * Get the current active data.
	 * Once created, the first item of the list is selected
  	 */
	inline GpsSimulationData const *GetCurrentData() const
	{
		return m_datas[m_currentIndex];
	}

	/**
	 * Activate the next item of the list
	 * the index is stopped automatically at the end of the list
  	 */
	inline void NextData()
	{
		if(m_currentIndex<(m_sequenceSize-1))
			m_currentIndex++;
	}

};

#endif /* GPSSIMULATIONSEQUENCE_H_ */
