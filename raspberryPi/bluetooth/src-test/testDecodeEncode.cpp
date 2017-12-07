#include "bluetooth_communication.h"
#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <stdlib.h>
#include "CAN_Abstraction.h"
#include "Interfaces_Rasp.h"
#include "CAN_Application.h"
#include "Messages.h"

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
	int32_t value = (int)linkPosSteeringWheel()->byteMessage[0];
	Messages msg_steering_wheel = Messages(0x00, 0x00, 0x07, value,0);
	bt->sendMsg(Messages::encode(msg_steering_wheel));
	/*
	for(int i =0; i < Messages::encode(msg_steering_wheel).size(); i++)
	{
		std::cout << ((int)Messages::encode(msg_steering_wheel)[i]) << std::endl;
	}*/
	std::cout<<linkUSFrontBack()->floatMessage[0]<<" / "<<linkUSFrontBack()->floatMessage[1]<<std::endl;
	
	int32_t USB_offset = (int32_t)((linkUSFrontBack()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkUSFrontBack()->intMessage[0]&0x0000FFFF);
	int32_t USF_offset = (int32_t)((linkUSFrontBack()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkUSFrontBack()->intMessage[2]&0x0000FFFF);
	
	Messages msg_us_front_back = Messages(0x00, 0x00, 0x03, USF_offset,USB_offset);
	bt->sendMsg(Messages::encode(msg_us_front_back));
	
	//std::cout<<"SEND=> " <<Messages::encode(msg_us_front_back)<<" / "<<Messages::encode(msg_steering_wheel).size()<<std::endl;
	
	/*for(int i =0; i < Messages::encode(msg_us_front_back).size(); i++)
	{
		std::cout << ((int)Messages::encode(msg_us_front_back)[i]) << std::endl;
	}*/
	
  }
}


void handler_OLD(BluetoothServer *bt){ //OLD version
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

void handler(BluetoothServer *bt){
	while(bt->isConnected()){
	  if (!bt->receptionBuffer.empty()){
		std::string msg = bt->receptionBuffer.front();
		bt->receptionBuffer.pop_front();
		Messages decoded_msg=Messages::decode(msg);
		//decoded_msg.display();
		
		if(decoded_msg.getLevel()==0x00 && decoded_msg.getComplementaryID()==0x00){
			
			switch(decoded_msg.getId()){
			case 0x08 :
				std::cout<<"front"<<std::endl;
				
			break;
			case 0x04 :
				std::cout<<"back"<<std::endl;
				
			break;
			case 0x02 :
				std::cout<<"left"<<std::endl;
				
			break;
			case 0x01 :
				std::cout<<"right"<<std::endl;
				
			break;
			default :
			break;
			}
			msg.pop_back();
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
