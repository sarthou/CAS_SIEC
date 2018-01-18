#include <iostream>

#include "CarBehavior.h"
#include "Interface/CanInterface.h"
#include "Interface/ImageInterface.h"
#include "CAN/CAN_Abstraction.h"

int Tag_Far=0;
int Tag_Left=0;
int Tag_Front=0;
int Tag_Right=0;

int getCarSide(){
	return linkPositionVoiture()->side;
}

int getCarDistance(){
	//int res = linkPositionVoiture()->dist;
	//std::cout << "getCarDistance : " << res << endl ;
 	return linkPositionVoiture()->dist;
}

float getCarPercentage(){
	return linkPositionVoiture()->percentageSide;
}

int isLeft(){
	return ((getCarDistance()>0) && (getCarSide()==0) && (getCarPercentage()>25.0));
}

int isRight(){
	return ((getCarDistance()>0) && (getCarSide()==1) && (getCarPercentage()>25.0));
}

int isMiddle(){
	return ((getCarDistance()>0) && (getCarPercentage()<=25.0));
}




float u1(){
	return linkUSLeft()->floatMessage[0];
}

float u2(){
	return linkUSRight()->floatMessage[1];
}

float u3(){
	return linkUSFrontBack()->floatMessage[0];
}

float u4(){
	return linkUSFrontBack()->floatMessage[1];
}

float u5(){
	return linkUSLeft()->floatMessage[1];
}

float u6(){
	return linkUSRight()->floatMessage[0];
}

int t5_8Function(){
	int res=0;
	if(u3()<60.0||u4()<60.0||u5()<60.0){
		res=1;
	}
	return res;
}

int t5_7Function(){
	int res=0;
	if(u6()<50.0){
		res=1;
	}
	return res;
}

int t8_9Function(){
	int res=0;
	if(u3()<50.0){
		res=1;
	}
	return res;
}

int t8_10Function(){
	int res=0;
	if(u4()<50.0){
		res=1;
	}
	return res;
}

int t8_12Function(){
	int res=0;
	if(u5()<50.0){
		res=1;
	}
	return res;
}

int t9_11Function(){
	int res=0;
	if(u3()<40.0 && u4()>40.0){
		res=1;
	}
	return res;
}

int t9_10Function(){
	int res=0;
	if(u4()<40.0 && u3()>=40.0){
		res=1;
	}
	return res;
}

int t10_13Function(){
	int res=0;
	if(u4()<20.0 && u5()>20.0){
		res=1;
	}
	return res;
}

int t10_12Function(){
	int res=0;
	if(u4()>=30.0&&u5()<30.0){
		res=1;
	}
	return res;
}

int t12_15Function(){
	int res=0;
	if(u5()<20.0 && u6()>40.0){
		res=1;
	}
	return res;
}

int t12_14Function(){
	int res=0;
	if(u6()<=40.0){
		res=1;
	}
	return res;
}

int t15_18Function(){
	int res=0;
	if(u5()<20.0 && u4()<30.0){
		res=1;
	}
	return res;
}

int t15_17Function(){
	int res=0;
	if(u5()>=20.0 && u4()>=30.0){
		res=1;
	}
	return res;
}

int t17_16Function(){
	int res=0;
	if(u6()<=30.0){
		res=1;
	}
	return res;
}

int t0_1Function(){
	int res=0;
	if(getCarDistance() > 0){
		res=1;
	}
	return res;
}

int t20Function(){
	int res=0;
	if(isLeft()){
		res=1;
	}
	return res;
}

int t2_3Function(){
	int res=0;
	if(isMiddle()){
		res=1;
	}
	return res;
}

int t3_2Function(){
	int res=0;
	if(isLeft()){
		res=1;
	}
	return res;
}

int t23Function(){
	int res=0;
	if(isRight()){
		res=1;
	}
	return res;
}

int t4_3Function(){
	int res=0;
	if(isMiddle()){
		res=1;
	}
	return res;
}

int t25Function(){
	int res=0;
	if(isMiddle()){
		res=1;
	}
	return res;
}

int t3_4Function(){
	int res=0;
	if(isRight()){
		res=1;
	}
	return res;
}

int t4_6Function(){
	int res=0;
	if(getCarDistance()<150 && getCarDistance()>0){
		res=1;
	}
	return res;
}

int t2_5Function(){
	int res=0;
	if(getCarDistance()<150 && getCarDistance()>0){
		res=1;
	}
	return res;
}

int t3_5Function(){
	int res=0;
	if(getCarDistance()<150 && getCarDistance()>0){
		res=1;
	}
	return res;
}

int trueFunction(){
	return 1;
}

int falseFunction(){
	return 0;
}

//State functions
int reduceSpeed(){
	*(linkCameraSpeedLimit()) = 60;
	return 0;
}

int limitSpeed(){
	*(linkCameraSpeedLimit()) = 11;
	return 0;
}

int stopCar(){
	*(linkCameraSpeedLimit()) = 0;
	return 0;
}

Machine CarBehavior::createCarBehaviorStateMachine(BluetoothServer * btServer){
	Machine process = Machine(0);


	//State machine Camera
	process.addState(State("00",btServer,NULL));//17
	process.addState(State("01",btServer,reduceSpeed));//18
	process.addState(State("02",btServer,NULL));//19
	process.addState(State("03",btServer,NULL));//20
	process.addState(State("04",btServer,NULL));//21
	process.addState(State("05",btServer,limitSpeed));//0
	process.addState(State("06",btServer,stopCar));//22
	process.addState(State("07",btServer,NULL));//4
	process.addState(State("08",btServer,NULL));//3
	process.addState(State("09",btServer,NULL));//5
	process.addState(State("10",btServer,NULL));//9
	process.addState(State("11",btServer,stopCar));//8
	process.addState(State("12",btServer,NULL));//11
	process.addState(State("13",btServer,stopCar));//10
	process.addState(State("14",btServer,NULL));//13
	process.addState(State("15",btServer,NULL));//12
	process.addState(State("16",btServer,NULL));//16
	process.addState(State("17",btServer,NULL));//15
	process.addState(State("18",btServer,stopCar));//14

	process.addTransition(Transition(0,1,t0_1Function));
	process.addTransition(Transition(1,3,trueFunction));
	process.addTransition(Transition(2,3,t2_3Function));
	process.addTransition(Transition(3,2,t3_2Function));
	process.addTransition(Transition(3,4,t3_4Function));
	process.addTransition(Transition(4,3,t4_3Function));
	process.addTransition(Transition(4,6,t4_6Function));
	process.addTransition(Transition(2,5,t2_5Function));
	process.addTransition(Transition(3,5,t3_5Function));
	//US
	process.addTransition(Transition(5,7,t5_7Function));
	process.addTransition(Transition(5,8,t5_8Function));
	process.addTransition(Transition(8,9,t8_9Function));
	process.addTransition(Transition(8,10,t8_10Function));
	process.addTransition(Transition(8,12,t8_12Function));

	process.addTransition(Transition(9,11,t9_11Function));
	process.addTransition(Transition(9,10,t9_10Function));

	process.addTransition(Transition(10,13,t10_13Function));
	process.addTransition(Transition(10,12,t10_12Function));

	process.addTransition(Transition(12,14,t12_14Function));
	process.addTransition(Transition(12,15,t12_15Function));

	process.addTransition(Transition(15,17,t15_17Function));
	process.addTransition(Transition(15,18,t15_18Function));

	process.addTransition(Transition(17,16,t17_16Function));




	/*
	process.addTransition(Transition(0,1,falseFunction));
	process.addTransition(Transition(0,2,t2Function));
	process.addTransition(Transition(0,3,t3Function));
	process.addTransition(Transition(0,4,t4Function));
	process.addTransition(Transition(3,5,t8Function));
	process.addTransition(Transition(3,9,t9Function));
	process.addTransition(Transition(3,11,t10Function));
	process.addTransition(Transition(5,8,t11Function));
	process.addTransition(Transition(5,9,t12Function));
	process.addTransition(Transition(9,10,t13Function));
	process.addTransition(Transition(9,11,t14Function));
	process.addTransition(Transition(11,12,t15Function));
	process.addTransition(Transition(11,13,t16Function));
	//process.addTransition(Transition(6,9,trueFunction));
	//process.addTransition(Transition(7,11,trueFunction));
	process.addTransition(Transition(12,14,t17Function));
	process.addTransition(Transition(12,15,t18Function));
	process.addTransition(Transition(15,16,t16Function));

	process.addTransition(Transition(0,1,t19Function)); //
	process.addTransition(Transition(18,19,t20Function));
	process.addTransition(Transition(18,20,t21Function));
	process.addTransition(Transition(18,21,t22Function));
	process.addTransition(Transition(20,21,t23Function));
	process.addTransition(Transition(21,20,t24Function));
	process.addTransition(Transition(19,20,t25Function));
	process.addTransition(Transition(20,19,t26Function));
	process.addTransition(Transition(19,22,t27Function));
	process.addTransition(Transition(20,0,t27Function));
	process.addTransition(Transition(21,0,t27Function));
	*/
	return process;
}


/*
void CarBehavior::task2()
{
	while(1)
	{
		usleep(200000);
		int nb=-1;
		std::cin>>nb;
		switch(nb)
		{
		case 0 :
			if(Tag_Far==0)
				Tag_Far=1;
			break;

		case 1 :
			if(Tag_Left==0)
			{
				Tag_Left=1;
				Tag_Right=0;
				Tag_Front=0;
				Tag_Far=0;
			}
			break;

		case 3 :
			if(Tag_Right==0)
			{
				Tag_Left=0;
				Tag_Right=1;
				Tag_Front=0;
				Tag_Far=0;
			}
			break;

		case 2 :
			if(Tag_Front==0)
			{
				Tag_Left=0;
				Tag_Right=0;
				Tag_Front=1;
				Tag_Far=0;
			}
			break;

		default :
			break;
		}
	}
}
*/
