#include "bluetooth_communication.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include "CAN_Abstraction.h"
#include "Interfaces_Rasp.h"
#include "CAN_Application.h"

std::mutex mtx;

void reception(BluetoothServer *bt)
{
  while (bt->isConnected()){
    std::string receivedMsg;
    receivedMsg = bt->receiveMsg();
    std::cout << "Message received: " << receivedMsg  << std::endl;
    //On rajoute en fin de file
    bt->receptionBuffer.push_back(receivedMsg);
  }
  }

void envoi(BluetoothServer *bt)
{
  while (bt->isConnected()){
    std::string msg;
    std::cin >> msg;
    bt->sendMsg(msg);
  }

}

void handler(BluetoothServer *bt){
	while(bt->isConnected()){
	  if (!bt->receptionBuffer.empty()){
		std::string msg = bt->receptionBuffer.front();
		bt->receptionBuffer.pop_front();
		if (msg.compare("left") != 0){
			std::cout << "Left => shared variable\n";
		  linkMotorsOrder()->intMessage[0] = 1000;
		  linkMotorsOrder()->intMessage[1] = 0;
		} else if (msg.compare("right") != 0){
			std::cout << "Right => shared variable\n";
		  linkMotorsOrder()->intMessage[1] = 1000;
		  linkMotorsOrder()->intMessage[0] = 0;

		}
	  }
	}
}

int main()
{
  //data_paquet_t *transMotorOrder;
  BluetoothServer btServer;
  std::cout << "The bluetooth server has been declared" << std::endl;
  btServer.acceptConnection();

  std::cout << "The connection has been accepted" << std::endl;

  std::thread first (reception, &btServer);     // spawn new thread that calls foo()
  std::thread second (envoi, &btServer);  // spawn new thread that calls bar(0)
  std::thread third (handler, &btServer); 

  std::cout << "Bluetooth threads are running\n";
  
  launchCANServices();
  
  std::cout << "CAN services are running\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();              // pauses until second finishes
  third.join();

  std::cout << "foo and bar completed.\n";

  return 0;
}
