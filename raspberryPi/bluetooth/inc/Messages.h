#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

class Messages {
	private :
		char level;
		/*	0x0=>cmd
			0x1=>dbg
			0x2=>warning
			0x3=>error
		*/
		char complementaryID;
		/*
			0x0=> sensor & commands
			0x1=> Unassigned for the moment
			0x2=> Unassigned for the moment
			0x3=> Unassigned for the moment
		*/
		char id;
		/*
			From Pc Application to Raspberry Pi : 
			WHEN complementaryID equals 0x0
			0x08 => Front
			0x04 => Back
			0x02 => Left
			0x01 => Right

			From Raspberry Pi to Pc Application :
			When complementaryID equals 0x0 :
			0x00=> Direction
			0x01=> Wheels LR
			0x02=> Speed
			0x03=> US FB
			0x04=> US Left
			0x05=> US Right
			0x06=> Battery
			0x07=> Unassigned for the moment
		*/
		
		int value; 
		int value2;
		
		/*
		Used for the reception
		*/
		
		public : 
		Messages(char l, char cid, char main_id, int val, int val2);
		
		~Messages();
		
		static Messages decode(std::string receivedBytes);
		
		static std::string encode(Messages msg);
		
		void display();
		
		//Getters
		char getLevel(){
			return level;
		}
		
		char getComplementaryID(){
			return complementaryID;
		}
		
		char getId(){
			return id;
		}
		
		int getValue(){
			return value;
		}
		
		int getValue2(){
			return value;
		}
};
#endif