#ifndef GENOS_TIMER_COUNTER_H
#define GENOS_TIMER_COUNTER_H

#include <inttypes.h>
#include <compiler.h>

__BEGIN_DECLS

uint32_t tc_counter_value(uint8_t channel);
uint64_t tc_hr_counter_value(uint8_t channel);

void tc_start(uint8_t channel);
void tc_stop(uint8_t channel);

void tc_set_divider(uint8_t channel, uint32_t divider);
void tc_set_limit(uint8_t channel, uint32_t limit);

void tc_ovf_interrupt_enable(uint8_t channel, void (*handler)());
void tc_ovf_interrupt_disable(uint8_t channel);

void tc_debug_info(uint8_t channel);

__END_DECLS

#endif