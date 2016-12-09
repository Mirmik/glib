#ifndef GENOS_CHARDEV_H
#define GENOS_CHARDEV_H

#include <kernel/irq.h>

class UartHardwareDriver {
public:
	virtual int putc(char c);
	virtual int getc();

	virtual bool availToGet();
	virtual bool readyToPut();
	
	virtual void setRXHandler(Kernel::IRQHandler handler);
	virtual void setTXHandler(Kernel::IRQHandler handler);

	virtual void enableRXInt(bool b);
	virtual void enableTXInt(bool b);

	virtual void enableRX(bool b);
	virtual void enableTX(bool b);
};

#include <genos/sigslot/delegate.h>

class UartTestDriver {
public:
	char tx_symbol;
	bool m_avail;
	bool m_txIRQenabled;

	delegate<void,char> putcSignal;
	int putc(char c) {
		putcSignal(c);
		return 1;
	}

	void simulateTXSymbol(char c) {
		tx_symbol = c;
		m_avail = true;
	};
	
	int getc() {
		m_avail = false;
		return tx_symbol;
	};

	bool availToGet() {return m_avail;};
	bool readyToPut() {return m_txIRQenabled;};
	
	//Kernel::IRQHandler rx_handler;
	//Kernel::IRQHandler tx_handler;

	void setRXHandler(Kernel::IRQHandler handler) {}
	void setTXHandler(Kernel::IRQHandler handler) {}

	void enableRXInt(bool b) {}
	void enableTXInt(bool b) { m_txIRQenabled = b; }

	void enableRX(bool b) {}
	void enableTX(bool b) {}	
};

#endif