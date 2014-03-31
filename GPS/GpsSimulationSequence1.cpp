/*
 * GpsSimulationSequence1.cpp
 *
 *  Created on: 30 mars 2014
 *      Author: Christian
 */

#include <GpsSimulationSequence1.h>



GpsSimulationSequence1::GpsSimulationSequence1():
GpsSimulationSequence(SimulationSequence,SequenceSize)
{
	// TODO Auto-generated constructor stub

}

GpsSimulationSequence1::~GpsSimulationSequence1() {
	// TODO Auto-generated destructor stub
}

GpsSimulationData GpsSimulationSequence1::Level0("frameRmcLevel0","frameGgaLevel0",1000,2000,0,true);
GpsSimulationData GpsSimulationSequence1::Level1000("frameRmcLevel1000","frameGgaLevel1000",1000,2000,1000,true);
GpsSimulationData GpsSimulationSequence1::Level3000("frameRmcLevel3000","frameGgaLevel3000",1000,2000,3000,true);
GpsSimulationData GpsSimulationSequence1::Level6000("frameRmcLevel6000","frameGgaLevel6000",1000,2000,6000,true);
GpsSimulationData GpsSimulationSequence1::Level10000("frameRmcLevel10000","frameGgaLevel10000",1000,2000,10000,true);
GpsSimulationData GpsSimulationSequence1::Level15000("frameRmcLevel15000","frameGgaLevel15000",1000,2000,15000,true);
GpsSimulationData GpsSimulationSequence1::Level20000("frameRmcLevel20000","frameGgaLevel20000",1000,2000,20000,true);
GpsSimulationData GpsSimulationSequence1::Level22000("frameRmcLevel22000","frameGgaLevel22000",1000,2000,22000,true);
GpsSimulationData GpsSimulationSequence1::Level19000("frameRmcLevel19000","frameGgaLevel19000",1000,2000,19000,true);
GpsSimulationData GpsSimulationSequence1::Level14000("frameRmcLevel14000","frameGgaLevel14000",1000,2000,14000,true);
GpsSimulationData GpsSimulationSequence1::Level5000("frameRmcLevel5000","frameGgaLevel5000",1000,2000,5000,true);
GpsSimulationData GpsSimulationSequence1::Level4000("frameRmcLevel4000","frameGgaLevel4000",1000,2000,4000,true);
GpsSimulationData GpsSimulationSequence1::Level3900("frameRmcLevel3900","frameGgaLevel3900",1000,2000,3900,true);
GpsSimulationData GpsSimulationSequence1::Level3800("frameRmcLevel3800","frameGgaLevel3800",1000,2000,3800,true);
GpsSimulationData GpsSimulationSequence1::Level4900("frameRmcLevel4900","frameGgaLevel4900",1000,2000,4900,true);
GpsSimulationData GpsSimulationSequence1::Level4800("frameRmcLevel4800","frameGgaLevel4800",1000,2000,4800,true);
GpsSimulationData GpsSimulationSequence1::Level2000("frameRmcLevel2000","frameGgaLevel2000",1000,2000,2000,true);
GpsSimulationData GpsSimulationSequence1::Level9000("frameRmcLevel9000","frameGgaLevel9000",1000,2000,9000,true);


GpsSimulationData const * GpsSimulationSequence1::SimulationSequence[GpsSimulationSequence1::SequenceSize]=
{
		&Level0,&Level1000,&Level3000,&Level6000,&Level10000,&Level15000,&Level20000,&Level22000,
		&Level19000,&Level14000,&Level9000,&Level5000,&Level4900,&Level4800,&Level4000,&Level2000,
		&Level1000,&Level0
};
