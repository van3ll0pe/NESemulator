/*
 *	$Id: old_elf.h,v 1.10 2009/07/21 13:17:58 barre Exp $
 *	old_elf module interface
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
#ifndef AVR_OLD_ELF_H
#define AVR_OLD_ELF_H

#include "grt.h"
#include "mem.h"
#include "api.h"

#if defined(__cplusplus)
    extern  "C" {
#endif

#define AVR_LOADER_STATE
#define AVR_LOADER_INIT(s)
#define AVR_LOADER_DESTROY(s)

/* avr_loader_t type */
typedef struct avr_loader_t avr_loader_t;


/* loader management */
avr_loader_t *avr_loader_open(const char *path);
void avr_loader_close(avr_loader_t *loader);
void avr_loader_load(avr_loader_t *loader, avr_platform_t *pf);
avr_address_t avr_loader_start(avr_loader_t *loader);


/* system initialization (used internally during platform and state initialization) */
avr_address_t avr_brk_init(avr_loader_t *loader);

/* section access */
typedef struct avr_loader_sect_t {
	const char *name;
	avr_address_t addr;
	int size;
	enum {
		AVR_LOADER_SECT_UNKNOWN = 0,
		AVR_LOADER_SECT_TEXT,
		AVR_LOADER_SECT_DATA,
		AVR_LOADER_SECT_BSS
	} type;
} avr_loader_sect_t;
int avr_loader_count_sects(avr_loader_t *loader);
void avr_loader_sect(avr_loader_t *loader, int sect, avr_loader_sect_t *data);

/* symbol access */
typedef struct {
	const char *name;
	avr_address_t value;
	int size;
	int sect;
	enum {
		AVR_LOADER_SYM_NO_TYPE,
		AVR_LOADER_SYM_DATA,
		AVR_LOADER_SYM_CODE
	} type;
	enum {
		AVR_LOADER_NO_BINDING,
		AVR_LOADER_LOCAL,
		AVR_LOADER_GLOBAL,
		AVR_LOADER_WEAK
	} bind;
} avr_loader_sym_t;
int avr_loader_count_syms(avr_loader_t *loader);
void avr_loader_sym(avr_loader_t *loader, int sym, avr_loader_sym_t *data);



#if defined(__cplusplus)
}
#endif

#endif	/* AVR_OLD_ELF_H */
