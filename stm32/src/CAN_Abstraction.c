#include "CAN_Abstraction.h"
#include <string.h>

void can_Init (int* ids, unsigned int size) { //ids with standard format

  CAN_setup ();                                   /* setup CAN Controller     */
  int i=0;
	for(i=0;i<size;i++){
		CAN_wrFilter (ids[i], STANDARD_FORMAT);             /* Enable reception of msgs */
	}
	
  /* ! COMMENT LINE BELOW TO ENABLE DEVICE TO PARTICIPATE IN CAN NETWORK !    */
  //CAN_testmode(CAN_BTR_SILM | CAN_BTR_LBKM);      // Loopback, Silent Mode (self-test)

  CAN_start ();                                   /* start CAN Controller   */

  CAN_waitReady ();                               /* wait til tx mbx is empty */
}

CAN_msg createPaquet(can_paquet paquet)
{
	CAN_msg message;
	message.id = paquet.id;                 // 29 bit identifier
	memcpy(message.data,paquet.data.stringMessage,8);
  message.len = 8;                // Length of data field in bytes
  message.format = STANDARD_FORMAT;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  message.type = DATA_FRAME;

	return message;
}

can_paquet decode(CAN_msg message)
{
	can_paquet paquet;
	paquet.id = message.id;
	memcpy(paquet.data.stringMessage, message.data,8);
	//paquet.data.stringMessage = message.data;
	
	return paquet;
}

void sendMessage(int16_t id, data_paquet data)
{
	can_paquet paquet;
	paquet.id=id;
	paquet.data=data;
	
	if (CAN_TxRdy) {                              /* tx msg on CAN Ctrl       */
		CAN_TxRdy = 0;
		
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg (&message);                     /* transmit message         */
	}
}

void sendMessageFloat(int16_t id, float data1, float data2)
{
	data_paquet data;
	data.floatMessage[0] = data1;
	data.floatMessage[1] = data2;
	
	can_paquet paquet;
	paquet.id=id;
	paquet.data=data;
	
	if (CAN_TxRdy) {                              /* tx msg on CAN Ctrl       */
		CAN_TxRdy = 0;
		
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg (&message);                     /* transmit message         */
	}
}

void sendMessageChar(int16_t id, char dataChar)
{
	data_paquet data;
	data.stringMessage[0] = dataChar;
	
	can_paquet paquet;
	paquet.id=id;
	paquet.data=data;
	
	if (CAN_TxRdy) 
	{                              /* tx msg on CAN Ctrl       */
		CAN_TxRdy = 0;
		CAN_msg message = createPaquet(paquet);
		CAN_wrMsg(&message);                     /* transmit message         */
	}
}

int receiveMessage(can_paquet* received)
{
	if(CAN_RxRdy)
	{                  
    CAN_RxRdy = 0;     /* rx msg on CAN Ctrl       */
		CAN_msg can_msg = CAN_RxMsg;
		*received = decode(can_msg);
		return 0;
	}
	else
		received = NULL;
	
	return -1;

}

