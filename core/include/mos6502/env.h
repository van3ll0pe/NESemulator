#ifndef MOS6502_LINUX_ENV_H
#define MOS6502_LINUX_ENV_H

#include "api.h"
#include "loader.h"

#if defined(__cplusplus)
    extern  "C" {
#endif


/* module name: env */

#define MOS6502_ENV_STATE
#define MOS6502_ENV_INIT(s)
#define MOS6502_ENV_DESTROY(s)


/* system initialization (used internally during platform and state initialization) */
void mos6502_stack_fill_env(mos6502_loader_t *loader, mos6502_platform_t *platform,  mos6502_env_t *env);
void mos6502_registers_fill_env(mos6502_env_t *env, mos6502_state_t *state);
void mos6502_set_brk(mos6502_platform_t *pf, mos6502_address_t address);

#if defined(__cplusplus)
}
#endif

#endif /* MOS6502_LINUX_ENV_H */
