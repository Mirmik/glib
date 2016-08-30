#ifndef HAL_IPL_H_
#define HAL_IPL_H_

#include <asm/hal/ipl.h>

extern void ipl_init(void);

#define ipl_enable()  ipl_init()
#define ipl_disable() ((void) ipl_save())

extern ipl_t ipl_save(void);
extern void ipl_restore(ipl_t ipl);

#endif /* HAL_IPL_H_ */
