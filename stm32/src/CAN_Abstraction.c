#include "CAN_Abstraction.h"
#include <string.h>

//Internal variables
int can_ids_[10];
data_paquet_t* can_data_[10];
unsigned int can_size_ = 0;

void canSubscribe(int id, data_paquet_t* data)
{
	can_ids_[can_size_] = id;
	can_data_[can_size_] = data;
	can_size_ = can_size_ +1;
}

void canInit(void) 
{ 
  CAN_setup ();
  int i=0;
	for(i=0;i<can_size_;i++){
		CAN_wrFilter (can_ids_[i], STANDARD_FORMAT);
	}
	
  /* ! COMMENT LINE BELOW TO ENABLE DEVICE TO PARTICIPATE IN CAN NETWORK !    */
  //CAN_testmode(CAN_BTR_SILM | CAN_BTR_LBKM);      // Loopback, Silent Mode (self-test)

  CAN_start ();
  CAN_waitReady ();                          
}

CAN_msg createPaquet(can_paquet_t paquet)
{
	CAN_msg message;
	message.id = paquet.id;
	memcpy(message.data,paquet.data.stringMessage,8);
	message.len = 8;  
	message.format = STANDARD_FORMAT;
	message.type = DATA_FRAME;

	return message;
}

can_paquet_t decode(CAN_msg message)
{
	can_paquet_t paquet;
	paquet.id = message.id;
	memcpy(paquet.data.stringMessage, message.data,8);

	return paquet;
}

int sendMessage(int16_t id, data_paquet_t data)
{
	can_paquet_t paquet;
	paquet.id=id;
	paquet.data=data;
	
	if (CAN_TxRdy) {
		CAN_TxRdy = 0; //Reset TxRdy flag
		
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg (&message);
		return 0;
	}
	return -1;
}

int sendMessageFloat(int16_t id, float data1, float data2)
{
	data_paquet_t data;
	data.floatMessage[0] = data1;
	data.floatMessage[1] = data2;
	
	can_paquet_t paquet;
	paquet.id=id;
	paquet.data=data;
	
	if (CAN_TxRdy) 
	{
		CAN_TxRdy = 0; //Reset TxRdy flag
		
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg (&message);
		return 0;
	}
	return -1;
}

int sendMessageChar(int16_t id, char dataChar)
{
	if (CAN_TxRdy) 
	{ 
		CAN_TxRdy = 0; //Reset TxRdy flag
		
		data_paquet_t data;
		data.stringMessage[0] = dataChar;

		can_paquet_t paquet;
		paquet.id=id;
		paquet.data=data;
		
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg(&message);
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
	if(CAN_RxRdy)
	{      
		CAN_RxRdy = 0; //Reset RxRdy flag
		CAN_msg can_msg = CAN_RxMsg;
		can_paquet_t received = decode(can_msg);
		int index = findIndexOfId(received.id);
		
		if(index >= 0) //if index is negative, the id is unknown
			*can_data_[index] = received.data;
		
		return 0;
	}
	
	return -1;

}

