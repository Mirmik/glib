#ifndef GENOS_PROTOCOL_GCOM_H
#define GENOS_PROTOCOL_GCOM_H

#include <stream/msgsend.h>
#include <gQ/gQByteArray.h>
//#include <gxx/hashtable.h>

//cs 			2
//system 		1
//code			1
//datalength	2
//data 			var

class gCom {
	Messanger* m_sender;

public:
	gCom(Messanger* sender) : m_sender(sender) {};

	void send(uint8_t sys, uint8_t code, uint16_t datasize, void* data);
		
};

#endif