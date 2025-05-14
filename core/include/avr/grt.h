/*
 *	$Id: grt.h,v 1.3 2009/07/08 12:09:19 barre Exp $
 *	gliss declarations
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2008, IRIT UPS.
 *
 *	GLISS2 is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	GLISS2 is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with GLISS2; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef AVR_GRT_H
#define AVR_GRT_H

#include <stdint.h>

/* module */
#define AVR_GRT_STATE
#define AVR_GRT_INIT(s)
#define AVR_GRT_DESTROY(s)

/* compatibility */
#ifndef INLINE
#	if __GNUC__
#		if !__GNUC_STDC_INLINE__
#			define INLINE extern inline
#		else
#			define INLINE inline
#		endif
#	else
#		ifdef _MSC_VER
#			define INLINE __forceinline
#		else
#			define INLINE	inline
#		endif
#	endif
#endif

/* useful */
uint32_t avr_f2bits(float f);
uint64_t avr_d2bits(double f);

/* extensions */
#define avr_ext(cs, vs, v)	(((v) << (cs - vs)) >> (cs  - vs))

/*	Notations :
 * - v  : value
 * - u  : uppermost (meaning the most significant bit)
 * - l  : lowermost (meaning the least significant bit)
 * - s  : set value (the field defined by [u l] in v is set to s)
 * - n  :
 * - r  : rotate    (number of times we rotate v)
 * - bo : bit order ()
 * */

/*	Fast modulo : FMOD(A, PW2) <=> A % PW2
	PW2 must be a power two */
#define FMOD(A, PW2) ((A) & ((PW2) - 1u))

/* rotations */
#define avr_mask32(n)	((n) == 32 ? (-1Lu) : (1Lu << (n)) - 1)
#define avr_mask64(n)	((n) == 64 ? (-1LLu) : (1LLu << (n)) - 1)

/* returns the l lowest bits of v rotated by r positions,
 * result is l bit long (with leading 0s if needed) */
uint32_t avr_rotate_left32(int l, uint32_t v, int r);
uint32_t avr_rotate_left8(int l, uint32_t v, int r);
uint32_t avr_rotate_left16(int l, uint32_t v, int r);
uint64_t avr_rotate_left64(int l, uint64_t v, int r);

uint32_t avr_rotate_right32(int l, uint32_t v, int r);
uint32_t avr_rotate_right8(int l, uint32_t v, int r);
uint32_t avr_rotate_right16(int l, uint32_t v, int r);
uint64_t avr_rotate_right64(int l, uint64_t v, int r);

/* concatenation */
#define avr_concat32(v1, v2, n1, n2)  ((((uint32_t)(v1) << n2) | ((v2) & avr_mask32(n2))))
#define avr_concat8(v1, v2, n1, n2) 	((uint8_t) avr_concat32(v1, v2, n1, n2))
#define avr_concat16(v1, v2, n1, n2) 	((uint16_t)avr_concat32(v1, v2, n1, n2))
#define avr_concat64(v1, v2, n1, n2)  ((((uint64_t)(v1) << n2) | ((v2) & avr_mask64(n2))))

/* exponent */
#define avr_exp8(v1, v2) 		((int8_t)  avr_exp32(v1, v2))
#define avr_exp8u(v1, v2) 	((uint8_t) avr_exp32u(v1, v2))
#define avr_exp16(v1, v2) 	((int16_t) avr_exp32(v1, v2))
#define avr_exp16u(v1, v2) 	((uint16_t)avr_exp32u(v1, v2))
int32_t avr_exp32(int32_t v1, int32_t v2);
uint32_t avr_exp32u(uint32_t v1, uint32_t v2);
int64_t avr_exp64(int64_t v1, int64_t v2);
uint64_t avr_exp64u(uint64_t v1, uint64_t v2);


/* for the field modification or extraction functions, there are 3 family:
 *  - function name not suffixed, used when field's bounds are known (constant)
 * and in the same order as specified by the nml var bit_order (no bit inversion needed)
 *  - <name>_inverted, bounds are known and order is different from bit_order (inversion needed)
 *  - <name>_generic, bounds known or not, will call a function from 1 of the 2 previous family
 * depending on the order of the bounds and bit_order.
 * Convention for bit_order:
 *  - 0 => lowermost
 *  - !=0 => uppermost
 */

/* simple set bit field (value to modify, set value, upper bits, lower bit) */
#ifndef COMPAT
INLINE uint32_t avr_set_field32u(uint32_t v, uint32_t s, int32_t u, int32_t l) {
    uint32_t mask = avr_mask32(u - l + 1) << l;
    return (v & ~mask) | ((s << l) & mask);
}
#endif

#define avr_set_field8(  v, s, u, l) 	((int8_t)  avr_set_field32u((v), (s), (u), (l)))
#define avr_set_field8u( v, s, u, l) 	((uint8_t) avr_set_field32u((v), (s), (l), (u)))
#define avr_set_field16( v, s, u, l) 	((int16_t) avr_set_field32u((v), (s), (u), (l)))
#define avr_set_field16u(v, s, u, l) 	((uint16_t)avr_set_field32u((v), (s), (l), (u)))
#define avr_set_field32( v, s, u, l) 	((int32_t) avr_set_field32u((v), (s), (u), (l)))
float avr_set_fieldf(float v, uint32_t s, int32_t u, int32_t l);
#define avr_set_field64(v, s, u, l)	((int64_t) avr_set_field64u(v, s, u, l))
uint64_t avr_set_field64u(uint64_t v, uint64_t s, int32_t u, int32_t l);
double avr_set_fieldd(double v, uint64_t s, int32_t u, int32_t l);

/* inverted set bit field (value to modify, set value, upper bits, lower bit) */
#define avr_set_field8_inverted(v, s, u, l) 		((int8_t)avr_set_field32u_inverted(v, s, u, l))
#define avr_set_field8u_inverted(v, s, u, l) 		((uint8_t)avr_set_field32u_inverted(v, s, l, u))
#define avr_set_field16_inverted(v, s, u, l) 		((int16_t)avr_set_field32u_inverted(v, s, u, l))
#define avr_set_field16u_inverted(v, s, u, l) 	((uint16_t)avr_set_field32u_inverted(v, s, l, u))
#define avr_set_field32_inverted(v, s, u, l) 		((int32_t)avr_set_field32u_inverted(v, s, u, l))
uint32_t avr_set_field32u_inverted(uint32_t v, uint32_t s, int32_t u, int32_t l);
#define avr_set_field64_inverted(v, s, u, l) 		((int64_t)avr_set_field64u_inverted(v, s, u, l))
uint64_t avr_set_field64u_inverted(uint64_t v, uint64_t s, int32_t u, int32_t l);
float avr_set_fieldf_inverted(float v, uint32_t s, int32_t u, int32_t l);
double avr_set_fieldd_inverted(double v, uint64_t s, int32_t u, int32_t l);

/* generic set bit field (value to modify, set value, upper bits, lower bit) */
#define avr_set_field8_generic(v, s, a, b, bo) 	((int8_t)  avr_set_field32u_generic(v, s, a, b, bo))
#define avr_set_field8u_generic(v, s, a, b, bo) 	((uint8_t) avr_set_field32u_generic(v, s, a, b, bo))
#define avr_set_field16_generic(v, s, a, b, bo) 	((int16_t) avr_set_field32u_generic(v, s, a, b, bo))
#define avr_set_field16u_generic(v, s, a, b, bo)	((uint16_t)avr_set_field32u_generic(v, s, a, b, bo)
#define avr_set_field32_generic(v, s, a, b, bo) 	((int32_t) avr_set_field32u_generic(v, s, a, b, bo))
uint32_t avr_set_field32u_generic(uint32_t v, uint32_t s, int32_t a, int32_t b, int bit_order);
#define avr_set_field64_generic(v, s, a, b, bo) 	((int64_t) avr_set_field64u_generic(v, s, a, b, bo))
uint64_t avr_set_field64u_generic(uint64_t v, uint64_t s, int32_t a, int32_t b, int bit_order);
float avr_set_fieldf_generic(float v, uint32_t s, int32_t a, int32_t b, int bit_order);
double avr_set_fieldd_generic(double v, uint64_t s, int32_t a, int32_t b, int bit_order);

/* single bit field (value, but) */
#define avr_bit(v, b)		(((v) >> (b)) & 0x1)
#define avr_bit8(v, b)	avr_bit(v, b)
#define avr_bit8u(v, b)	avr_bit(v, b)
#define avr_bit16(v, b)	avr_bit(v, b)
#define avr_bit16u(v, b)	avr_bit(v, b)
#define avr_bit32(v, b)	avr_bit(v, b)
#define avr_bit32u(v, b)	avr_bit(v, b)
#define avr_bit32f(v, b)	avr_bit(avr_f2bits((v)), b)
#define avr_bit64(v, b)	avr_bit(v, b)
#define avr_bit64u(v, b)	avr_bit(v, b)
#define avr_bitf(v, b)	avr_bit32f(v, b)
#define avr_bitd(v, b)	avr_bit(avr_d2bits((v)), b)

/* simple field access (value, upper bit, lower bit) */
#define avr_field32u(v, u, l)	((uint32_t)(v & (avr_mask32(u - l + 1) << l)) >> l)
#define avr_field64u(v, u, l)	((uint64_t)(v & (avr_mask64(u - l + 1) << l)) >> l)
#define avr_field8(v, u, l)	avr_field32u((v), (u), (l))
#define avr_field8u(v, u, l)	avr_field32u((v), (u), (l))
#define avr_field16(v, u, l)	avr_field32u((v), (u), (l))
#define avr_field16u(v, u, l)	avr_field32u((v), (u), (l))
#define avr_field32(v, u, l)	avr_field32u((v), (u), (l))
#define avr_fieldf(v, u, l)	avr_field32u(avr_f2bits((v)), (u), (l))
#define avr_field64(v, u, l)	avr_field64u((v), (u), (l))
#define avr_fieldd(v, u, l)	avr_field64u(avr_d2bits((v)), (u), (l))

/* field access with inversion (value, upper bit, lower bit) */
#define avr_field8_inverted(  v, u, l)	((int8_t)  avr_field32u_inverted(v, u, l))
#define avr_field8u_inverted( v, u, l)	((uint8_t) avr_field32u_inverted(v, u, l))
#define avr_field16_inverted( v, u, l)	((int16_t) avr_field32u_inverted(v, u, l))
#define avr_field16u_inverted(v, u, l)	((uint16_t)avr_field32u_inverted(v, u, l))
#define avr_field32_inverted( v, u, l)	((int32_t) avr_field32u_inverted(v, u, l))
uint32_t avr_field32u_inverted(uint32_t v, uint32_t u, uint32_t l);
#define avr_field64_inverted(v, u, l)		((int64_t) avr_field64u_inverted(v, u, l))
uint64_t avr_field64u_inverted(uint64_t v, uint32_t u, uint32_t l);
uint32_t avr_fieldf_inverted(float v, uint32_t u, uint32_t l);
uint64_t avr_fieldd_inverted(double v, uint32_t u, uint32_t l);

/* generic field access */
#define avr_field8_generic(v, a, b, bo) 	((int8_t)  avr_field32u_generic(v, a, b, bo))
#define avr_field8u_generic(v, a, b, bo) 	((uint8_t) avr_field32u_generic(v, a, b, bo))
#define avr_field16_generic(v, a, b, bo) 	((int16_t) avr_field32u_generic(v, a, b, bo))
#define avr_field16u_generic(v, a, b, bo)	((uint16_t)avr_field32u_generic(v, a, b, bo))
#define avr_field32_generic(v, a, b, bo) 	((int32_t) avr_field32u_generic(v, a, b, bo))
uint32_t avr_field32u_generic(uint32_t v, uint32_t a, uint32_t b, int bit_order);
#define avr_field64_generic(v, a, b, bo) 	((int64_t) avr_field64u_generic(v, a, b, bo))
uint64_t avr_field64u_generic(uint64_t v, uint32_t a, uint32_t b, int bit_order);
uint32_t avr_fieldf_generic(float v, uint32_t a, uint32_t b, int bit_order);
uint64_t avr_fieldd_generic(double v, uint32_t a, uint32_t b, int bit_order);

/* enumeration */
int avr_enumerate(int val, int max);

/* coercition */
#define avr_coerce_ftoi(f) ((int32_t)(f))
#define avr_coerce_ftou(f) ((uint32_t)(f))
#define avr_coerce_dtoi(d) ((int64_t)(d))
#define avr_coerce_dtou(d) ((uint64_t)(d))
#define avr_coerce_itof(i) ((float)(i))
#define avr_coerce_utof(u) ((float)(u))
#define avr_coerce_itod(i) ((double)(i))
#define avr_coerce_utod(u) ((double)(u))

/* cast */
#define avr_cast_fto8(f)	((uint8_t)avr_cast_fto32(f))
#define avr_cast_fto16(f) ((uint16_t)avr_cast_fto32(f))
uint32_t avr_cast_fto32(float f);
#define avr_cast_fto64(f) ((uint64_t)avr_cast_fto32(f))

#define avr_cast_dto8(f)	((uint8_t)avr_cast_dto64(f))
#define avr_cast_dto16(f) ((uint16_t)avr_cast_dto64(f))
#define avr_cast_dto32(f) ((uint32_t)avr_cast_dto64(f))
uint64_t avr_cast_dto64(double f);

#define avr_cast_8tof(i)	((uint8_t)avr_cast_32tof(i))
#define avr_cast_16tof(i)	((uint8_t)avr_cast_32tof(i))
float avr_cast_32tof(uint32_t i);
#define avr_cast_64tof(i)	((uint64_t)avr_cast_32tof(i))

#define avr_cast_8tod(i)	avr_cast_64tod(i)
#define avr_cast_16tod(i) avr_cast_64tod(i)
#define avr_cast_32tod(i) avr_cast_64tod(i)
double avr_cast_64tod(uint64_t d);



/* signed/unsigned conversion */
#define __AVR_MASK32(n, e)	((n)==32 ? (e) : ((e) & ((1 << n) - 1)))
#define __AVR_MASK64(n, e)	((n)==64 ? (e) : ((e) & ((1LL << n) - 1)))
#define __AVR_CSIZE(t)		(sizeof((t)(1) + 1) * 8)
#define __AVR_EXTS(n, e)		(((e) << (n)) >> (n))
#define __AVR_EXTS8(n, e)		__AVR_EXTS(32-(n), (int32_t)(e))
#define __AVR_EXTS16(n, e)	__AVR_EXTS(32-(n), (int32_t)(e))
#define __AVR_EXTS32(n, e)	__AVR_EXTS(32-(n), (int32_t)(e))
#define __AVR_EXTS64(n, e)	__AVR_EXTS(64-(n), (int64_t)(e))

#endif /* AVR_GRT_H */
