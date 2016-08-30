#ifndef GENOS_UART_BASIC_H
#define GENOS_UART_BASIC_H

#include <genos/sigslot/sigslot.h>

namespace genos {
	enum UartParity {
		UartParityNone,
		UartParityEven,
		UartParityOdd,
	};
};

struct UartParametr {
	uint32_t 			baudRate;
	genos::UartParity 	parity;
	uint8_t 			stopBits;
	uint8_t 			dataBits;
};

class Uart {
	virtual void putc(char c) = 0;
	virtual char getc() = 0;
	
	virtual bool hasrx() = 0;
	virtual bool maytx() = 0;
	
	virtual void txEnable(bool) = 0;
	virtual void rxEnable(bool) = 0;

	virtual int setup(const UartParametr& param) = 0;
};

#endif 