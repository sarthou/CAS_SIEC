#include "bluetooth_communication.h"
#include <iostream>

BluetoothServer::BluetoothServer(void){
  mainSocket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
  loc_addr.rc_family = AF_BLUETOOTH;
  loc_addr.rc_bdaddr = *BDADDR_ANY;
  loc_addr.rc_channel = (uint8_t) 1;
  bind(mainSocket, (struct sockaddr *)&loc_addr, sizeof(loc_addr));
  //Maybe the listen should be placed into the acceptConnection()
  listen(mainSocket, 1);
}

BluetoothServer::~BluetoothServer(void){
  close(clientSocket);
  close(mainSocket);
}

int BluetoothServer::acceptConnection(){
  clientSocket=accept(mainSocket,(struct sockaddr *)&rem_addr, &opt );
  std::cout << "Connection accepted" << std::endl;
}

void BluetoothServer::sendMsg(const std::string & msg){
  int bytes_send;
  std::cout << "Message test " << std::endl << msg << std::endl << msg.c_str() << msg.size()<< std::endl;
  bytes_send = write(clientSocket, msg.c_str() , msg.size());
  std::cout << bytes_send << std::endl;
}

std::string BluetoothServer::receiveMsg(){
  int bytes_read;
  char buf[1024] = { 0 };
  //std::string msg;
  bytes_read = read(clientSocket, buf, sizeof(buf));
  return buf;
}
