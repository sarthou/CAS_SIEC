#include "Interface/PosVoitInterface.h"



positionVoiture PosVoit;

void initCarPosition(){
	PosVoit.side = -1;
	PosVoit.dist = -1;
	PosVoit.percentageSide = -1.0;

}

positionVoiture* linkPositionVoiture(){
	return &PosVoit;
}



