#include "bluetooth_communication.h"
#include <iostream>

int main(){
	BluetoothServer bt;
	bt.acceptConnection();
	int i = 0;
	while (i< 30){
		std::cout << "Reception Number :" << i+1 << std::endl;
		std::cout << bt.receiveMsg() << std::endl;
		bt.sendMsg("This message has been received");
		i++;
	}
}
