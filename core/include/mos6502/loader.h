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
#ifndef MOS6502_OLD_ELF_H
#define MOS6502_OLD_ELF_H

#include "grt.h"
#include "mem.h"
#include "api.h"

#if defined(__cplusplus)
    extern  "C" {
#endif

#define MOS6502_LOADER_STATE
#define MOS6502_LOADER_INIT(s)
#define MOS6502_LOADER_DESTROY(s)

/* mos6502_loader_t type */
typedef struct mos6502_loader_t mos6502_loader_t;


/* loader management */
mos6502_loader_t *mos6502_loader_open(const char *path);
void mos6502_loader_close(mos6502_loader_t *loader);
void mos6502_loader_load(mos6502_loader_t *loader, mos6502_platform_t *pf);
mos6502_address_t mos6502_loader_start(mos6502_loader_t *loader);


/* system initialization (used internally during platform and state initialization) */
mos6502_address_t mos6502_brk_init(mos6502_loader_t *loader);

/* section access */
typedef struct mos6502_loader_sect_t {
	const char *name;
	mos6502_address_t addr;
	int size;
	enum {
		MOS6502_LOADER_SECT_UNKNOWN = 0,
		MOS6502_LOADER_SECT_TEXT,
		MOS6502_LOADER_SECT_DATA,
		MOS6502_LOADER_SECT_BSS
	} type;
} mos6502_loader_sect_t;
int mos6502_loader_count_sects(mos6502_loader_t *loader);
void mos6502_loader_sect(mos6502_loader_t *loader, int sect, mos6502_loader_sect_t *data);

/* symbol access */
typedef struct {
	const char *name;
	mos6502_address_t value;
	int size;
	int sect;
	enum {
		MOS6502_LOADER_SYM_NO_TYPE,
		MOS6502_LOADER_SYM_DATA,
		MOS6502_LOADER_SYM_CODE
	} type;
	enum {
		MOS6502_LOADER_NO_BINDING,
		MOS6502_LOADER_LOCAL,
		MOS6502_LOADER_GLOBAL,
		MOS6502_LOADER_WEAK
	} bind;
} mos6502_loader_sym_t;
int mos6502_loader_count_syms(mos6502_loader_t *loader);
void mos6502_loader_sym(mos6502_loader_t *loader, int sym, mos6502_loader_sym_t *data);



#if defined(__cplusplus)
}
#endif

#endif	/* MOS6502_OLD_ELF_H */
