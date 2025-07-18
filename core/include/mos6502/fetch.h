/* Generated by gep (125/05/23 10:52:00) copyright (c) 2008 IRIT - UPS */

#ifndef GLISS_MOS6502_INCLUDE_MOS6502_FETCH_H
#define GLISS_MOS6502_INCLUDE_MOS6502_FETCH_H


#if defined(__cplusplus)
extern  "C"
{
#endif

#include "api.h"
#include "config.h"

#define MOS6502_FETCH_STATE
#define MOS6502_FETCH_INIT(s)
#define MOS6502_FETCH_DESTROY(s)

/* fetch structure */
struct mos6502_fetch_t
{
	/* the memory which we are supposed to fetch from, useful on Harvard architectures where we deal with several memories */
	mos6502_memory_t *mem;
};

#if defined(__cplusplus)
}
#endif

#endif /* GLISS_MOS6502_INCLUDE_MOS6502_FETCH_H */
