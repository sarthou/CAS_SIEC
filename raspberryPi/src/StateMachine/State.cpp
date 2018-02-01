#include "StateMachine/State.h"
#include "Bluetooth/Messages.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int State::counter_id=0;

State::State(std::string n,BluetoothServer* serv,int(*f)())
{
  id=counter_id;
  counter_id++;
  name=n;
  server=serv;
  executedFunction=f;
}

State::~State(){}

int State::getId()
{
    return id;
}

 std::string State::getName()
 {
    return name;
 }

 void State::run()
 {

	 //int32_t limit = *linkCameraSpeedLimit();
	 //Messages msg_speed_limit = Messages(0x00, 0x02, 0x03, limit, 0);
	 //bt->sendMsg(Messages::encode(msg_speed_limit));
	 int32_t value1 = name[0];
	 int32_t value2 = name[1];

	 std::cout << value1 << " " << value2 << std::endl;
	 Messages msg_state = Messages(0x00, 0x01, 0x00, value1, value2);
	 server->sendMsg(Messages::encode(msg_state));
	 std::cout << "Etat numero :" << name << std::endl;
	 //server->sendMsg("[DBG]"+name+"\n"); //TODO change with new rules

	 if(executedFunction!=NULL)
   {
		executedFunction();
	 }
 }
