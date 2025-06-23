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
#ifndef MOS6502_VFAST_MEM_H
#define MOS6502_VFAST_MEM_H

#include <stdint.h>
#include <stddef.h>
#include "config.h"

#if defined(__cplusplus)
    extern  "C" {
#endif

#define MOS6502_MEM_STATE
#define MOS6502_MEM_INIT(s)
#define MOS6502_MEM_DESTROY(s)

#define MOS6502_VFAST_MEM
#ifdef MOS6502_NO_PAGE_INIT
#	define MOS6502_NOBITS_INIT
#endif

typedef uint32_t mos6502_address_t;
typedef uint32_t mos6502_size_t;
typedef struct mos6502_memory_t mos6502_memory_t;

/* creation function */
mos6502_memory_t *mos6502_mem_new(void);
void mos6502_mem_delete(mos6502_memory_t *memory);
mos6502_memory_t *mos6502_mem_copy(mos6502_memory_t *memory);

/* read functions */
uint8_t mos6502_mem_read8(mos6502_memory_t *, mos6502_address_t);
uint16_t mos6502_mem_read16(mos6502_memory_t *, mos6502_address_t);
uint32_t mos6502_mem_read32(mos6502_memory_t *, mos6502_address_t);
uint64_t mos6502_mem_read64(mos6502_memory_t *, mos6502_address_t);
float mos6502_mem_readf(mos6502_memory_t *, mos6502_address_t);
double mos6502_mem_readd(mos6502_memory_t *, mos6502_address_t);
long double mos6502_mem_readld(mos6502_memory_t *, mos6502_address_t);
void mos6502_mem_read(mos6502_memory_t *memory, mos6502_address_t, void *buf, size_t size);


/* write functions */
void mos6502_mem_write8(mos6502_memory_t *, mos6502_address_t, uint8_t);
void mos6502_mem_write16(mos6502_memory_t *, mos6502_address_t, uint16_t);
void mos6502_mem_write32(mos6502_memory_t *, mos6502_address_t, uint32_t);
void mos6502_mem_write64(mos6502_memory_t *, mos6502_address_t, uint64_t);
void mos6502_mem_writef(mos6502_memory_t *, mos6502_address_t, float);
void mos6502_mem_writed(mos6502_memory_t *, mos6502_address_t, double);
void mos6502_mem_writeld(mos6502_memory_t *, mos6502_address_t, long double);
void mos6502_mem_write(mos6502_memory_t *memory, mos6502_address_t, void *buf, size_t size);

#ifdef MOS6502_MEM_SPY
typedef enum { mos6502_access_read, mos6502_access_write } mos6502_access_t;
typedef void (*mos6502_mem_spy_t)(mos6502_memory_t *mem, mos6502_address_t addr, mos6502_size_t size, mos6502_access_t access, void *data);
void mos6502_mem_set_spy(mos6502_memory_t *mem, mos6502_mem_spy_t fun, void *data);
#endif

#if defined(__cplusplus)
}
#endif

#endif	/* MOS6502_VFAST_MEM_H */
