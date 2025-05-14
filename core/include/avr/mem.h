/*
 *	$Id: fast_mem.h,v 1.4 2009/01/21 07:30:54 casse Exp $
 *	fast_mem module interface
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2008, IRIT UPS.
 *
 *	GLISS is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	GLISS is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with OTAWA; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef AVR_VFAST_MEM_H
#define AVR_VFAST_MEM_H

#include <stdint.h>
#include <stddef.h>
#include "config.h"

#if defined(__cplusplus)
    extern  "C" {
#endif

#define AVR_MEM_STATE
#define AVR_MEM_INIT(s)
#define AVR_MEM_DESTROY(s)

#define AVR_VFAST_MEM
#ifdef AVR_NO_PAGE_INIT
#	define AVR_NOBITS_INIT
#endif

typedef uint32_t avr_address_t;
typedef uint32_t avr_size_t;
typedef struct avr_memory_t avr_memory_t;

/* creation function */
avr_memory_t *avr_mem_new(void);
void avr_mem_delete(avr_memory_t *memory);
avr_memory_t *avr_mem_copy(avr_memory_t *memory);

/* read functions */
uint8_t avr_mem_read8(avr_memory_t *, avr_address_t);
uint16_t avr_mem_read16(avr_memory_t *, avr_address_t);
uint32_t avr_mem_read32(avr_memory_t *, avr_address_t);
uint64_t avr_mem_read64(avr_memory_t *, avr_address_t);
float avr_mem_readf(avr_memory_t *, avr_address_t);
double avr_mem_readd(avr_memory_t *, avr_address_t);
long double avr_mem_readld(avr_memory_t *, avr_address_t);
void avr_mem_read(avr_memory_t *memory, avr_address_t, void *buf, size_t size);


/* write functions */
void avr_mem_write8(avr_memory_t *, avr_address_t, uint8_t);
void avr_mem_write16(avr_memory_t *, avr_address_t, uint16_t);
void avr_mem_write32(avr_memory_t *, avr_address_t, uint32_t);
void avr_mem_write64(avr_memory_t *, avr_address_t, uint64_t);
void avr_mem_writef(avr_memory_t *, avr_address_t, float);
void avr_mem_writed(avr_memory_t *, avr_address_t, double);
void avr_mem_writeld(avr_memory_t *, avr_address_t, long double);
void avr_mem_write(avr_memory_t *memory, avr_address_t, void *buf, size_t size);

#ifdef AVR_MEM_SPY
typedef enum { avr_access_read, avr_access_write } avr_access_t;
typedef void (*avr_mem_spy_t)(avr_memory_t *mem, avr_address_t addr, avr_size_t size, avr_access_t access, void *data);
void avr_mem_set_spy(avr_memory_t *mem, avr_mem_spy_t fun, void *data);
#endif

#if defined(__cplusplus)
}
#endif

#endif	/* AVR_VFAST_MEM_H */
