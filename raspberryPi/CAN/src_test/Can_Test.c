#include "CAN_Abstraction.h"
#include <stdio.h>
#include <time.h>

int main(void){
	/*
	//TEST SEND_BCM
	data_paquet_t paquet;
	paquet.stringMessage[0]='A';
	sendMessageBcm(25, paquet);
	*/
	/*
	//TEST SEND
	data_paquet_t paquet;
	paquet.stringMessage[0]='A';
	paquet.stringMessage[1]='C';
	paquet.stringMessage[2]='C';
	paquet.stringMessage[3]='0';
	paquet.stringMessage[4]='\0';
	sendMessage(25, paquet);
	
	data_paquet_t paquet2;
	paquet2.intMessage[0]=21566;
	sendMessage(42,paquet2);
	*/
	//TEST RECEIVE
	data_paquet_t rcv_var;
	data_paquet_t rcv_var2;
	canSubscribe(37, &rcv_var);
	canSubscribe(38,&rcv_var2);
	int count=0;
	while(1){
		receiveMessage();
		
		if(count%2==0){
			printf("%s \n",rcv_var.stringMessage);
		}else{
			printf("%s \n",rcv_var2.stringMessage);
		}
		count++;
	}
	return 0;	
}