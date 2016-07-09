#ifndef GENOS_UTIL_BITS_H
#define GENOS_UTIL_BITS_H
	
#define bits_set_all(a) {a = -1;}
#define bits_clr_all(a) {a = 0;}

#define bits_set(a, b) {a |= (b);}
#define bits_clr(a, b) {a &= ~(b);}
#define bits_rev(a) {a = ~(a);}

#define bits_mask(a,m) ((a) & (m))
#define bits_invmask(a,m) ((a) & (~(m)))

#define bits_mask_rev(a,m) {a ^= (m);}
#define bits_mask_eq(a,m,b) (((a) & (m)) == (b))

#define bits_mask_assign(a,m,b) (a = bits_invmask(a,m) | bits_mask(b,m))

#endif