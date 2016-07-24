#ifndef STREAM_MESSANGER_H
#define STREAM_MESSANGER_H

#include "inttypes.h"

class Messanger {
	/*	
		send - Передать сообщение.
		@buf : буффер-источник
		@len : длина сообщения
		@flag : опции
		@return : код возврата. Отрицательный в случае ошибки. 
	*/
	virtual int send(const void* buf, int len, uint8_t flag = 0) = 0;
	
	/*	
		recv - Принять сообщение.
		@buf : буффер-приёмник
		@max : максимальная длина принимаемого сообщения
		@flag : опции
		@return : код возврата. Отрицательный в случае ошибки. 
	*/
	virtual int recv(const void* buf, int max, uint8_t flag = 0) = 0;
};

#endif