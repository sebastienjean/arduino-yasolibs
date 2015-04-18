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

#ifndef GPSSIMULATIONSEQUENCE1_H_
#define GPSSIMULATIONSEQUENCE1_H_

#include <mock/GpsSimulationData.h>
#include <mock/GpsSimulationSequence.h>

/**
 * first testing sequence
 * starts from 0 m, goes up until 22.000 m before to goes down
 */
class GpsSimulationSequence1:public GpsSimulationSequence {
private :

	 static int const SequenceSize=18;
	 static GpsSimulationData const * SimulationSequence[SequenceSize];

	 static GpsSimulationData  Level0;
	 static GpsSimulationData  Level1000;
	 static GpsSimulationData  Level2000;
	 static GpsSimulationData  Level3000;
	 static GpsSimulationData  Level3800;
	 static GpsSimulationData  Level3900;
	 static GpsSimulationData  Level4000;
	 static GpsSimulationData  Level4800;
	 static GpsSimulationData  Level4900;
	 static GpsSimulationData  Level5000;
	 static GpsSimulationData  Level6000;
	 static GpsSimulationData  Level9000;
	 static GpsSimulationData  Level10000;
	 static GpsSimulationData  Level14000;
	 static GpsSimulationData  Level15000;
	 static GpsSimulationData  Level19000;
	 static GpsSimulationData  Level20000;
	 static GpsSimulationData  Level22000;


public:
	GpsSimulationSequence1();
	virtual ~GpsSimulationSequence1();

};

#endif /* GPSSIMULATIONSEQUENCE1_H_ */
