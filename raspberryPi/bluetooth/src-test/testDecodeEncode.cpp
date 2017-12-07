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
	usleep(50000);
	
	int32_t value = (int32_t)linkPosSteeringWheel()->byteMessage[0];
	Messages msg_steering_wheel = Messages(0x00, 0x00, 0x07, value,0);
	bt->sendMsg(Messages::encode(msg_steering_wheel));
	
	int32_t USB_offset = (int32_t)((linkUSFrontBack()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkUSFrontBack()->intMessage[0]&0x0000FFFF);
	int32_t USF_offset = (int32_t)((linkUSFrontBack()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkUSFrontBack()->intMessage[2]&0x0000FFFF);
	
	Messages msg_us_front_back = Messages(0x00, 0x00, 0x03, USF_offset,USB_offset);
	bt->sendMsg(Messages::encode(msg_us_front_back));
	
	int32_t USR1_offset = (int32_t)((linkUSRight()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkUSRight()->intMessage[0]&0x0000FFFF);
	int32_t USR2_offset = (int32_t)((linkUSRight()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkUSRight()->intMessage[2]&0x0000FFFF);
	
	Messages msg_us_right = Messages(0x00, 0x00, 0x05, USR2_offset,USR1_offset);
	bt->sendMsg(Messages::encode(msg_us_right));
	
	int32_t USL1_offset = (int32_t)((linkUSLeft()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkUSLeft()->intMessage[0]&0x0000FFFF);
	int32_t USL2_offset = (int32_t)((linkUSLeft()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkUSLeft()->intMessage[2]&0x0000FFFF);
	
	Messages msg_us_left = Messages(0x00, 0x00, 0x04, USL2_offset,USL1_offset);
	bt->sendMsg(Messages::encode(msg_us_left));
	
	int32_t posWheelL = (int32_t)((linkPosWheelsLR()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkPosWheelsLR()->intMessage[0]&0x0000FFFF);
	int32_t posWheelR = (int32_t)((linkPosWheelsLR()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkPosWheelsLR()->intMessage[2]&0x0000FFFF);
	
	Messages msg_pos_wheels = Messages(0x00, 0x00, 0x01, posWheelL,posWheelR);
	bt->sendMsg(Messages::encode(msg_pos_wheels));
	
	int32_t  speedValueL = (int32_t)((linkSpeedWheelsLR()->intMessage[1]<<16)&0xFFFF0000)|((int32_t)linkSpeedWheelsLR()->intMessage[0]&0x0000FFFF);
	int32_t  speedValueR = (int32_t)((linkSpeedWheelsLR()->intMessage[3]<<16)&0xFFFF0000)|((int32_t)linkSpeedWheelsLR()->intMessage[2]&0x0000FFFF);
	Messages msg_speed = Messages(0x00,0x00, 0x02, speedValueL, speedValueR);
	bt->sendMsg(Messages::encode(msg_speed));
	
	int32_t valueBat = (int32_t)linkBattery()->byteMessage[0];
	Messages msg_battery = Messages(0x00,0x00,0x06,valueBat,0);
	bt->sendMsg(Messages::encode(msg_battery));
  }
}

void handler(BluetoothServer *bt){
	
	while(bt->isConnected()){
	  if (!bt->receptionBuffer.empty()){
		std::string msg = bt->receptionBuffer.front();
		bt->receptionBuffer.pop_front();
		Messages decoded_msg=Messages::decode(msg);
		
		if(decoded_msg.getLevel()==0x00 && decoded_msg.getComplementaryID()==0x00){
			char id = decoded_msg.getId();
			if(id==0x08){
				//std::cout<<"front"<<decoded_msg.getValue()<<std::endl;
				int32_t speedF = decoded_msg.getValue();
				linkMotorsOrder()->intMessage[0]= (int16_t)speedF*10;
				linkMotorsOrder()->intMessage[1]= (int16_t)speedF*10;
			}else if(id==0x04){
				//std::cout<<"back"<<decoded_msg.getValue()<<std::endl;
				int32_t speedB = decoded_msg.getValue();
				linkMotorsOrder()->intMessage[0]= (int16_t)speedB*-10;
				linkMotorsOrder()->intMessage[1]= (int16_t)speedB*-10;
			}else if(id==0x02){
				//std::cout<<"left"<<decoded_msg.getValue()<<std::endl;
				int32_t angleL = decoded_msg.getValue();
				linkSteeringWheelOrder()->byteMessage[0] = (int8_t)angleL;
			}else if(id==0x01){
				//std::cout<<"right"<<decoded_msg.getValue()<<std::endl;
				int32_t angleR = decoded_msg.getValue();
				linkSteeringWheelOrder()->byteMessage[0] = -1*(int8_t)angleR;
			}
			msg.pop_back();
		}
		}
	}
}

int main()
{
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

  return 0;
}
