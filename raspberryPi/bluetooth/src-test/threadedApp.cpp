#include "bluetooth_communication.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <stdlib.h>
#include "CAN_Abstraction.h"
#include "Interfaces_Rasp.h"
#include "CAN_Application.h"

std::mutex mtx;

void reception(BluetoothServer *bt)
{
  while (bt->isConnected()){
    std::string receivedMsg;
    receivedMsg = bt->receiveMsg();
    //std::cout << "Message received: " << receivedMsg  << std::endl;
    //On rajoute en fin de file
    bt->receptionBuffer.push_back(receivedMsg);
  }
  }

void envoi(BluetoothServer *bt)
{
  while (bt->isConnected()){
	 sleep(1);
  std::string msg = "[DBG][POS STEERING WHEEL]" + std::to_string(linkPosSteeringWheel()->byteMessage[0])+"\n";
    bt->sendMsg(msg);
	std::string msg2 = "[DBG][POS WHEELS LR]" + std::to_string(linkPosWheelsLR()->intMessage[0])+std::to_string(linkPosWheelsLR()->intMessage[1])+"\n";
    bt->sendMsg(msg2);
	
  }

}

void handler(BluetoothServer *bt){
	while(bt->isConnected()){
	  if (!bt->receptionBuffer.empty()){
		std::string msg = bt->receptionBuffer.front();
		std::cout<<msg<<std::endl;
		bt->receptionBuffer.pop_front();
		if (msg.compare("left") == 0){
			//std::cout << "Left => shared variable\n";
		  linkSteeringWheelOrder()->byteMessage[0] = -100;
		} else if (msg.compare("right") == 0){
			//std::cout << "Right => shared variable\n";
			linkSteeringWheelOrder()->byteMessage[0]= 100;
			
		}else if(msg.substr(0,5).compare("front") ==0){
			//std::cout<<"Front => shared variable\n";
			msg.pop_back();
			int speed = stoi(msg.substr(6));
			//std::cout<<msg.substr(6)<<std::endl;
			linkMotorsOrder()->intMessage[0]= speed*10;
			//std::cout<<speed<<std::endl;
			linkMotorsOrder()->intMessage[1]= speed*10;
			//std::cout<<speed<<std::endl;
		}else if(msg.substr(0,4).compare("back") ==0){
			//std::cout<<"Back => shared variable\n";
			msg.pop_back();
			int speed = stoi(msg.substr(5));
			//std::cout<<msg.substr(5)<<std::endl;
			linkMotorsOrder()->intMessage[0]= speed*10;
			//std::cout<<speed<<std::endl;
			linkMotorsOrder()->intMessage[1]= speed*10;
			//std::cout<<speed<<std::endl;
		}else if (msg.substr(0,6).compare("center")==0){
			msg.pop_back();
			linkSteeringWheelOrder()->byteMessage[0]=0;
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

 // std::cout << "Bluetooth threads are running\n";
  
  launchCANServices();
  
 // std::cout << "CAN services are running\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();              // pauses until second finishes
  third.join();

  std::cout << "foo and bar completed.\n";

  return 0;
}
