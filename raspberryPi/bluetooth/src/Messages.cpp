#include "Messages.h"

#include <iostream>

Messages::Messages(char l, char cid, char main_id,int32_t val, int32_t val2){
	level=l;
	complementaryID=cid;
	id=main_id;
	value=val;
	value2=val2;
}

Messages::~Messages(){
}

Messages Messages::decode(std::string receivedBytes){
	char level = (receivedBytes[0]&0xC0) >>6;
	
	char complementaryId = (receivedBytes[0]&0x30)>>4;
	
	char id = (receivedBytes[0]&0x0F);
	
	int32_t value = (int)(receivedBytes[1]);
	
	Messages msg = Messages(level,complementaryId,id,value,0);
	return msg;
}

std::string Messages::encode(Messages msg){
	std::string sentBytes;
	
	char level_offset = ((msg.getLevel()&0x03)<<6);
	char complementaryId_offset = ((msg.getComplementaryID()&0x03)<<4);
	char id_offset = msg.getId()&0x0F;
	char begin = level_offset|complementaryId_offset|id_offset;
	
	
	std::string sentMessage;
	
	
	switch(msg.getId()){
		case 7 :
		//sentMessage.resize(3);		
		//sentMessage[0]=begin;
		//sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		//sentMessage[2]='\0';
		sentMessage+=begin;
		sentMessage+=(char)(msg.getValue()&0x000000FF);
		break;
		
		case 6 : 
		sentMessage.resize(3);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]='\0';
		break;
		
		case 1 :
		sentMessage.resize(10);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]=(char)((msg.getValue()&0x0000FF00)>>8);
		sentMessage[3]=(char)((msg.getValue()&0x00FF0000)>>16);
		sentMessage[4]=(char)((msg.getValue()&0xFF000000)>>24);
		sentMessage[5]=(char)(msg.getValue2()&0x000000FF);
		sentMessage[6]=(char)((msg.getValue2()&0x0000FF00)>>8);
		sentMessage[7]=(char)((msg.getValue2()&0x00FF0000)>>16);
		sentMessage[8]=(char)((msg.getValue2()&0xFF000000)>>24);
		sentMessage[9]='\0';
		break;
		
		case 2 :
		sentMessage.resize(10);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]=(char)((msg.getValue()&0x0000FF00)>>8);
		sentMessage[3]=(char)((msg.getValue()&0x00FF0000)>>16);
		sentMessage[4]=(char)((msg.getValue()&0xFF000000)>>24);
		sentMessage[5]=(char)(msg.getValue2()&0x000000FF);
		sentMessage[6]=(char)((msg.getValue2()&0x0000FF00)>>8);
		sentMessage[7]=(char)((msg.getValue2()&0x00FF0000)>>16);
		sentMessage[8]=(char)((msg.getValue2()&0xFF000000)>>24);
		sentMessage[9]='\0';
		break;
		
		case 3 :
		sentMessage.resize(10);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]=(char)((msg.getValue()&0x0000FF00)>>8);
		sentMessage[3]=(char)((msg.getValue()&0x00FF0000)>>16);
		sentMessage[4]=(char)((msg.getValue()&0xFF000000)>>24);
		sentMessage[5]=(char)(msg.getValue2()&0x000000FF);
		sentMessage[6]=(char)((msg.getValue2()&0x0000FF00)>>8);
		sentMessage[7]=(char)((msg.getValue2()&0x00FF0000)>>16);
		sentMessage[8]=(char)((msg.getValue2()&0xFF000000)>>24);
		sentMessage[9]='\0';
		break;
		
		case 4 :
		sentMessage.resize(10);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]=(char)((msg.getValue()&0x0000FF00)>>8);
		sentMessage[3]=(char)((msg.getValue()&0x00FF0000)>>16);
		sentMessage[4]=(char)((msg.getValue()&0xFF000000)>>24);
		sentMessage[5]=(char)(msg.getValue2()&0x000000FF);
		sentMessage[6]=(char)((msg.getValue2()&0x0000FF00)>>8);
		sentMessage[7]=(char)((msg.getValue2()&0x00FF0000)>>16);
		sentMessage[8]=(char)((msg.getValue2()&0xFF000000)>>24);
		sentMessage[9]='\0';
		break;
		
		case 5 :
		sentMessage.resize(10);
		sentMessage[0]=begin;
		sentMessage[1]=(char)(msg.getValue()&0x000000FF);
		sentMessage[2]=(char)((msg.getValue()&0x0000FF00)>>8);
		sentMessage[3]=(char)((msg.getValue()&0x00FF0000)>>16);
		sentMessage[4]=(char)((msg.getValue()&0xFF000000)>>24);
		sentMessage[5]=(char)(msg.getValue2()&0x000000FF);
		sentMessage[6]=(char)((msg.getValue2()&0x0000FF00)>>8);
		sentMessage[7]=(char)((msg.getValue2()&0x00FF0000)>>16);
		sentMessage[8]=(char)((msg.getValue2()&0xFF000000)>>24);
		sentMessage[9]='\0';
		break;
		
		default :
		sentMessage.resize(2);
		sentMessage[0]=begin;
		sentMessage[1]='\0';
		break;
	}
	
	return sentMessage;
}

//g++ -std=c++11 -pthread -lbluetooth -fpermissive CAN_Abstraction.c CAN_Application.c CAN_Periodic.c

void Messages::display(){
	switch(level){
		case 0x00 :
			std::cout<<"cmd"<<std::endl;
			break;
		default : 
			std::cout<<"other"<<std::endl;
			break;
	}
	
	switch(complementaryID){
		case 0x00 :
			std::cout<<"UserCmd"<<std::endl;
			break;
		default : 
			std::cout<<"other"<<std::endl;
			break;
	}
	
	switch(id){
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
	}
	
	std::cout<<value<<std::endl;
}
