#ifndef GENOS_TTY_DRIVER_H
#define GENOS_TTY_DRIVER_H

#include <kernel/fs/file.h>
#include <gxx/ByteRing.h>
#include <drivers/serial/uart.h>

class Teletype : public File {

	Uart* uart;

	gxx::ByteRing tx_ring;
	gxx::ByteRing rx_ring;

public:
	int open();	
	int close();

	int write(const char* str, size_t len);
	int read(char* str, size_t len);

	off_t seek(off_t offset, int whence);

	void tx_handler();
	void rx_handler();

	size_t avail();

	void init() {
		uart->setTXHandler(Kernel::IRQHandler(&Teletype::tx_handler, this));
		uart->setRXHandler(Kernel::IRQHandler(&Teletype::rx_handler, this));
	}

	Teletype(Uart* _uart) : uart(_uart) {
		type = ftype_tty;
	}

};

#endif