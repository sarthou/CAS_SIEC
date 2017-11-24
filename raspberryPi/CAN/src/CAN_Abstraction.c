#include "CAN_Abstraction.h"

#include <linux/can/bcm.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

//Internal variables
int can_ids_[10];
data_paquet_t* can_data_[10];
unsigned int can_size_ = 0;
int s ;

void canSubscribe(int id, data_paquet_t* data)
{
	can_ids_[can_size_] = id;
	can_data_[can_size_] = data;
	can_size_ = can_size_ +1;
}

void canInit(void) 
{ 

	//Socket declaration
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    struct sockaddr_can addr;
    struct ifreq ifr;
	
	//Address configuration
    strcpy(ifr.ifr_name, "can0");
    ioctl(s, SIOCGIFINDEX, &ifr);
	addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
	
	//Binding
    if(bind(s, (struct sockaddr *)&addr, sizeof(addr))!=0){
		printf("Error binding\n");
	}
}

struct can_frame createPaquet(can_paquet_t paquet)
{
	/*
	canid_tbit 0-28 => CAN identifier
	bit 29 => error message frame (0 = data frame, 1 = error message)
	bit 30 => remote transmission  request flag (1 = rtr frame)
	bit 31 => frame format flag (0=standard, 1 = extended)
	*/
	/*struct can_frame {
		canid_t can_id;      /* 32 bit CAN_ID + EFF/RTR flags 
		__u8    can_dlc;     /* data length code: 0 .. 8 
		__u8    data[8] __attribute__ ((aligned(8)));
	};*/
	
	struct can_frame frame;
	frame.can_id=paquet.id;
	frame.can_dlc=8; //Default value
	int i=0;
	for(i=0;i<8;i++){
		frame.data[i]=paquet.data.stringMessage[i];
	}
	return frame;
}

can_paquet_t decode(struct can_frame frame)
{	
	can_paquet_t paquet;
	paquet.id = frame.can_id;
	
	int count=0;
	while(count<frame.can_dlc||count<8){
		paquet.data.stringMessage[count]=frame.data[count];
		count=count+1;
	}

	return paquet;
}

int sendMessage(int16_t id, data_paquet_t data)
{
	can_paquet_t paquet;
	paquet.id=id;
	paquet.data=data;
	
	struct timeval timer_usec;
	long long int timestamp_usec;
	if(!gettimeofday(&timer_usec,NULL)){
		timestamp_usec=((long long int) timer_usec.tv_sec)*1000000ll + (long long int)timer_usec.tv_usec;
	}
	
	switch(paquet.id){
		
		case 0x010 : 
			printf("[%lld][SENDING][MOTORS ORDER] %d %d\n",timestamp_usec,paquet.data.intMessage[0],paquet.data.intMessage[1]);
			break;
		case 0x011 : 
			printf("[%lld][SENDING][STEERING WHEEL ORDER] %d\n",timestamp_usec,paquet.data.byteMessage[0]);
			break;
	}
	/*
	//Socket declaration
    int s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    struct sockaddr_can addr;
    struct ifreq ifr;
	struct can_frame frame;
	
	//Address configuration
    strcpy(ifr.ifr_name, "can0");
    ioctl(s, SIOCGIFINDEX, &ifr);
	addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
	
	//Binding
    if(bind(s, (struct sockaddr *)&addr, sizeof(addr))!=0){
		printf("Error binding\n");
	}
	*/
	struct can_frame frame;
	frame=createPaquet(paquet);
	
	int nbytes = write(s, &frame, sizeof(struct can_frame));
	
	if(nbytes>=0){
		return 0;
	}
	
	return -1;
}

//Find index of the id given in parameter
//Can be viewed as a Map
int findIndexOfId(int id)
{
	int i = 0;
	for(i = 0; i < can_size_; i = i + 1)
	{
		if(id == can_ids_[i])
			return i;
	}
	return -1;
}

int receiveMessage(void)
{
	/*
	//Socket declaration
    int s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    struct sockaddr_can addr;
    struct ifreq ifr;
	struct can_frame frame;
	
	//Address configuration
    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, "can0");
    ioctl(s, SIOCGIFINDEX, &ifr);
    addr.can_ifindex = ifr.ifr_ifindex;
	
    //Binding
    bind(s, (struct sockaddr *)&addr, sizeof(addr));
	*/
	struct can_frame frame;
	int nbytes = read(s, &frame, sizeof(struct can_frame));
	if(nbytes>=0){
	can_paquet_t received = decode(frame);
	int index = findIndexOfId(received.id);
	if(index >= 0) //if index is negative, the id is unknown
		*can_data_[index] = received.data;
		
		//printf("R%d\n",received.id);
	struct timeval timer_usec;
	long long int timestamp_usec;
	if(!gettimeofday(&timer_usec,NULL)){
		timestamp_usec=((long long int) timer_usec.tv_sec)*1000000ll + (long long int)timer_usec.tv_usec;
	}
		
		switch (received.id){
			case 0x101 :
				printf("[%lld][REICEIVING][POS STEERING WHEEL] %d\n",timestamp_usec,received.data.byteMessage[0]);
				break;
			case 0x100 :
				printf("[%lld][REICEIVING][POS WHEELS LR] %f %f\n", timestamp_usec,received.data.floatMessage[0],received.data.floatMessage[1]);
				break;
			case 0x000 : 
				printf("[%lld][REICEIVING][US FRONT BACK] %f %f\n",timestamp_usec, received.data.floatMessage[0],received.data.floatMessage[1]);
				break;
			case 0x001 :
				printf("[%lld][REICEIVING][US LEFT] %f %f\n",timestamp_usec, received.data.floatMessage[0],received.data.floatMessage[1]);
				break;
			case 0x002 :
				printf("[%lld][REICEIVING][US RIGHT] %f %f\n", timestamp_usec,received.data.floatMessage[0],received.data.floatMessage[1]);
				break;
			case 0x200 : 
				printf("[%lld][REICEIVING][BATTERY] %d\n",timestamp_usec, received.data.intMessage[0]);
				break;
		}
		return 0;
	}
	
	return -1;

}