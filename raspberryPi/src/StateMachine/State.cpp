#include "StateMachine/State.h"

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
	 server->sendMsg("[DBG]"+name+"\n"); //TODO change with new rules
	 if(executedFunction!=NULL)
   {
		executedFunction();
	 }
 }
