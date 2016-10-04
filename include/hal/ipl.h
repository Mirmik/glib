#ifndef HAL_IPL_H_
#define HAL_IPL_H_

#include <asm/hal/ipl.h>

#define ipl_enable()  ipl_init()
#define ipl_disable() ((void) ipl_save())

#endif /* HAL_IPL_H_ */
