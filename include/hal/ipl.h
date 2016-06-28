#ifndef HAL_IPL_H_
#define HAL_IPL_H_

//#include <util/lang.h>
#include <asm/hal/ipl.h>

extern void ipl_init(void);

#define ipl_enable()  ipl_init()
#define ipl_disable() ((void) ipl_save())

extern ipl_t ipl_save(void);
extern void ipl_restore(ipl_t ipl);

//#define IPL_SAFE_DO(expr) \
//	__lang_surround(expr, ipl_t __ipl = ipl_save(), ipl_restore(__ipl))

#endif /* HAL_IPL_H_ */
