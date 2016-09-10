#include <drivers/serial/tty.h>

#include "genos_configure.h"

#include <stdlib.h>
#include <assert.h>
#include <kernel/panic.h>
#include <hal/ipl.h>

#define DEFAULT_RING_TTY_RX_BUFLEN 128
#define DEFAULT_RING_TTY_TX_BUFLEN 128

int ring_tty_open (struct file *filep) {
	struct ring_tty_s* tty = filep->f_priv;

	assert(tty->tx_buffer == 0);
	assert(tty->rx_buffer == 0);

	tty->tx_buffer = sysalloc(DEFAULT_RING_TTY_TX_BUFLEN);
	tty->rx_buffer = sysalloc(DEFAULT_RING_TTY_RX_BUFLEN);
}

int ring_tty_close (struct file *filep) {
	struct ring_tty_s* tty = filep->f_priv;

	assert(tty->tx_buffer != 0);
	assert(tty->rx_buffer != 0);
	
	sysfree(tty->tx_buffer);
	sysfree(tty->rx_buffer);
}

ssize_t ring_tty_read (struct file *filep, char *buffer, size_t buflen) {
	panic("notsuported");
}

ssize_t ring_tty_write (struct file *filep, const char *buffer, size_t buflen) {
	struct ring_tty_s* tty = filep->f_priv;
	struct uart_dev* dev = tty->dev;
	char* end = buffer + buflen;
	size_t sended = 0; 
	
	if (buflen == 0) return 0;

	ipl_t save = ipl_save();

	uint8_t empty = ring_is_empty(&tty->tx_ring);
	uint8_t ready = uart_txready(dev);

	if (empty && ready) {
		uart_putc(dev, *buffer++);
		sended++;
	};

	while(buffer != end) {
		sended += ring_putc(&tty->tx_ring, tty->tx_buffer, *(buffer++));
	};

	ipl_restore(save);
	return sended;
}

off_t ring_tty_seek (struct file *filep, off_t offset, int whence) {
	panic("notsuported");
}

int ring_tty_ioctl (struct file *filep, int cmd, unsigned long arg) {
	panic("notsuported");
}

void ring_tty_newrecv(void* ttyptr, char c) {
	struct ring_tty_s* tty = ttyptr;
	ring_putc(&tty->rx_ring, tty->rx_buffer, c);
}

void ring_tty_contsend(void* ttyptr) {
	struct ring_tty_s* tty = ttyptr;
	struct uart_dev* dev = tty->dev;
	
	if (!uart_txready(dev) || ring_is_empty(&tty->tx_ring)) return;

	uart_putc(dev, ring_getc(&tty->tx_ring, tty->tx_buffer));
}

void ring_tty_register(struct uart_dev* dev, const char* path) {
	struct ring_tty_s* tty = sysalloc(sizeof(struct ring_tty_s));

	ring_init(&tty->tx_ring, DEFAULT_RING_TTY_TX_BUFLEN);
	ring_init(&tty->rx_ring, DEFAULT_RING_TTY_RX_BUFLEN);

	tty->tx_buffer = 0; sysalloc(DEFAULT_RING_TTY_TX_BUFLEN);
	tty->rx_buffer = 0; sysalloc(DEFAULT_RING_TTY_RX_BUFLEN);
}