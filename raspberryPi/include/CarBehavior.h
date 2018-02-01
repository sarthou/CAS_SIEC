#ifndef CARBEHAVIOR_H
#define CARBEHAVIOR_H

#include "StateMachine/Machine.h"
#include "Bluetooth/BluetoothCommunication.h"

class CarBehavior{

public :
	static Machine createCarBehaviorStateMachine(BluetoothServer * btServer);

	static void task2();
};

#endif
