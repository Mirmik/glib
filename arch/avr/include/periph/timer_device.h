#ifndef GENOS_AVR_TIMER_DEVICE_H
#define GENOS_AVR_TIMER_DEVICE_H

#include <periph/regs/timer.h>
#include <drivers/timer_counter.h>
#include <kernel/irq.h>

struct timer_irqs {
	uint8_t ovfno;
};

class TimerDevice_8bit : public TimerDevice<uint8_t> {
	timer_8bit_regs* regs;
	timer_irqs irqs;
	volatile reg_t* timsk;

public:

	TimerDevice_8bit(timer_8bit_regs* _regs, timer_irqs _irqs, volatile reg_t* _timsk) 
		: regs(_regs), irqs(_irqs), timsk(_timsk) {};

	uint8_t value();

	void start();
	void stop();

	void setLimit(uint8_t limit);
	void setDivider(uint16_t limit);

	void setHandlerOverflow(Kernel::IRQHandler handler);
	void interruptEnableOverflow(bool b);
};

class TimerDevice_16bit : public TimerDevice<uint16_t> {
	timer_16bit_regs* regs;
	timer_irqs irqs;
	volatile reg_t* timsk;

public:

	TimerDevice_16bit(timer_16bit_regs* _regs, timer_irqs _irqs, volatile reg_t* _timsk) 
		: regs(_regs), irqs(_irqs), timsk(_timsk) {};

	uint16_t value();

	void start();
	void stop();

	void setLimit(uint16_t limit);
	void setDivider(uint16_t divider);

	void setHandlerOverflow(Kernel::IRQHandler handler);
	void interruptEnableOverflow(bool b);
};

namespace periph {
	extern TimerDevice_8bit timer0;
	extern TimerDevice_8bit timer2;
	extern TimerDevice_16bit timer1;
	extern TimerDevice_16bit timer3;
	extern TimerDevice_16bit timer4;
	extern TimerDevice_16bit timer5;
};

#endif