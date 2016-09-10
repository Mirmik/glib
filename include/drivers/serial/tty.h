#ifndef GENOS_TTY_DRIVER_H
#define GENOS_TTY_DRIVER_H

#include <drivers/serial/uart.h>
#include <genos/datastruct/ring_head.h>
#include <kernel/fs/fs.h>

struct ring_tty_s;

struct ring_tty_s {
	struct uart_dev* dev;
	
	struct ring_head rx_ring;
	char* rx_buffer;
	
	struct ring_head tx_ring;
	char* tx_buffer;
};

struct tty_driver_operations {
	void (*newrecv) (void* tty, char c);
	void (*contsend) (void* tty);
};

int 	ring_tty_open	(struct file *filep);
int     ring_tty_close	(struct file *filep);
ssize_t ring_tty_read	(struct file *filep, char *buffer, size_t buflen);
ssize_t ring_tty_write	(struct file *filep, const char *buffer, size_t buflen);
off_t   ring_tty_seek	(struct file *filep, off_t offset, int whence);
int     ring_tty_ioctl	(struct file *filep, int cmd, unsigned long arg);

static const struct file_operations ring_tty_operations = {
	ring_tty_open, 	/*open*/
	ring_tty_close, /*close*/
	ring_tty_read, 	/*read*/
	ring_tty_write, /*write*/
	ring_tty_seek, 	/*seek*/
	ring_tty_ioctl, /*ioctl*/
};

void ring_tty_newrecv(void* ttyptr, char c);
void ring_tty_contsend(void* ttyptr);

static const struct tty_driver_operations ring_tty_driver_operations = {
	ring_tty_newrecv,
	ring_tty_contsend,
};

void ring_tty_register(struct uart_dev* dev, const char* path);

#endif