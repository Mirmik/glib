#include <hal/procdelay.h>
#include "genos_configure.h"

#include <util/delay.h>


void processor_delay_ms(uint16_t m) {
	_delay_ms(m);
}