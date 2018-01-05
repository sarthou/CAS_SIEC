#include <iostream>

#include "CarBehavior.h"
#include "Interface/CanInterface.h"
#include "CAN/CAN_Abstraction.h"

int Tag_Far=0;
int Tag_Left=0;
int Tag_Front=0;
int Tag_Right=0;

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

float dist=50.0;

int t1Function(){
	int res=0;
	if(u1()<dist){
		res=1;
	}
	return res;
}

int t2Function(){
	int res=0;
	if(u2()<40.0){
		res=1;
	}
	return res;
}

int t3Function(){
	int res=0;
	if(u3()<50.0||u4()<50.0||u5()<50.0){
		res=1;
	}
	return res;
}

int t4Function(){
	int res=0;
	if(u6()<dist){
		res=1;
	}
	return res;
}

int t8Function(){
	int res=0;
	if(u3()<40.0){
		res=1;
	}
	return res;
}

int t9Function(){
	int res=0;
	if(u4()<40.0){
		res=1;
	}
	return res;
}

int t10Function(){
	int res=0;
	if(u5()<40.0){
		res=1;
	}
	return res;
}

int t11Function(){
	int res=0;
	if(u3()<30.0&&u4()>30.0){
		res=1;
	}
	return res;
}

int t12Function(){
	int res=0;
	if(u4()<30.0&&u3()>=30.0){
		res=1;
	}
	return res;
}

int t13Function(){
	int res=0;
	if(u4()<20.0&&u5()>20.0){
		res=1;
	}
	return res;
}

int t14Function(){
	int res=0;
	if(u4()>=20.0&&u5()<20.0){
		res=1;
	}
	return res;
}

Machine CarBehavior::createCarBehaviorStateMachine(BluetoothServer * btServer){
	Machine process = Machine(0);

	process.addState(State("0",btServer,NULL));//0
	process.addState(State("1",btServer,NULL));//1
	process.addState(State("2",btServer,NULL));//2
	process.addState(State("3",btServer,NULL));//3
	process.addState(State("4",btServer,NULL));//4
	process.addState(State("8",btServer,NULL));//5
	process.addState(State("9",btServer,NULL));//6
	process.addState(State("10",btServer,NULL));//7
	process.addState(State("11",btServer,NULL));//8
	process.addState(State("12",btServer,NULL));//9
	process.addState(State("13",btServer,NULL));//10
	process.addState(State("14",btServer,NULL));//11

	process.addTransition(Transition(0,1,t1Function));
	process.addTransition(Transition(0,2,t2Function));
	process.addTransition(Transition(0,3,t3Function));
	process.addTransition(Transition(0,4,t4Function));
	process.addTransition(Transition(3,5,t8Function));
	process.addTransition(Transition(3,6,t9Function));
	process.addTransition(Transition(3,7,t10Function));
	process.addTransition(Transition(5,8,t11Function));
	process.addTransition(Transition(5,9,t12Function));
	process.addTransition(Transition(9,10,t13Function));
	process.addTransition(Transition(9,11,t14Function));

	return process;
}

void CarBehavior::task2()
{
	while(1)
	{
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
