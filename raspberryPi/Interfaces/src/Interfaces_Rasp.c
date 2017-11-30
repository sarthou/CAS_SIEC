#include "Interfaces_Rasp.h"

data_paquet_t posSteeringWheel;
data_paquet_t posWheelsLR;
data_paquet_t USFrontBack;
data_paquet_t USLeft;
data_paquet_t USRight;
data_paquet_t motorsOrder;
data_paquet_t steeringWheelOrder;
data_paquet_t battery;

data_paquet_t* linkPosSteeringWheel(){
	return &posSteeringWheel;
}

data_paquet_t* linkPosWheelsLR(){
	return &posWheelsLR;
}

data_paquet_t* linkUSFrontBack(){
	return &USFrontBack;
}

data_paquet_t* linkUSLeft(){
	return &USLeft;
}

data_paquet_t* linkUSRight(){
	return &USRight;
}

data_paquet_t* linkMotorsOrder(){
	return &motorsOrder;
}

data_paquet_t* linkSteeringWheelOrder(){
	return &steeringWheelOrder;
}
data_paquet_t* linkBattery(){
	return &battery;
}
