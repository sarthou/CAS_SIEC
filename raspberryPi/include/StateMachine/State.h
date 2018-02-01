#ifndef STATE_H
#define STATE_H

#include <string>
#include "Bluetooth/BluetoothCommunication.h"

class State
{
public :
  State(std::string n, BluetoothServer* serv,int(*f)());
  ~State();

  int(*executedFunction)(void);

  int getId();
  std::string getName();

  void run();

  static int counter_id;

private :
  int id;
  std::string name;
  BluetoothServer * server;
};

#endif // STATE_H
