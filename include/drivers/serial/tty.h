#ifndef GENOS_TTY_DRIVER_H
#define GENOS_TTY_DRIVER_H

#include <defines/off_t.h>
#include <kernel/fs/chardev.h>
#include <gxx/ByteRing.h>
#include <drivers/serial/uart.h>

class Teletype : public Kernel::CharDev {

	Uart* uart;

	gxx::ByteRing tx_ring;
	gxx::ByteRing rx_ring;

public:
	int open();	
	int close();

	int write(const char* str, int len, uint8_t opt);
	int read(char* str, int len, uint8_t opt);

	off_t seek(off_t offset, int whence);

	void tx_handler();
	void rx_handler();

	size_t avail();

	void init() {
		uart->setTXHandler(Kernel::IRQHandler(&Teletype::tx_handler, this));
		uart->setRXHandler(Kernel::IRQHandler(&Teletype::rx_handler, this));
	}

	Teletype(Uart* _uart) : uart(_uart) {
		//type = ftype_tty;
	}

};

#endif