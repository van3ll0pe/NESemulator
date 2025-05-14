/*
 *	$Id: error.h,v 1.1 2009/04/09 08:17:23 casse Exp $
 *	error module
 *
 *	This file is part of OTAWA
 *	Copyright (c) 2009, IRIT UPS.
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

#ifndef AVR_ERROR_H
#define AVR_ERROR_H

#include "api.h"

#if defined(__cplusplus)
    extern  "C" {
#endif

/* module */
#define AVR_ERROR_STATE
#define AVR_ERROR_INIT(s)
#define AVR_ERROR_DESTROY(s)

/* functions */
void avr_panic(const char *format, ...);
void avr_error(avr_state_t *state, avr_inst_t *inst, const char *format, ...);
void avr_execute_unknown(avr_state_t *state, avr_address_t address);

#if defined(__cplusplus)
}
#endif

#endif /* AVR_ERROR_H */

