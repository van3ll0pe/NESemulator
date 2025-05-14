#ifndef AVR_LINUX_ENV_H
#define AVR_LINUX_ENV_H

#include "api.h"
#include "loader.h"

#if defined(__cplusplus)
    extern  "C" {
#endif


/* module name: env */

#define AVR_ENV_STATE
#define AVR_ENV_INIT(s)
#define AVR_ENV_DESTROY(s)


/* system initialization (used internally during platform and state initialization) */
void avr_stack_fill_env(avr_loader_t *loader, avr_platform_t *platform,  avr_env_t *env);
void avr_registers_fill_env(avr_env_t *env, avr_state_t *state);
void avr_set_brk(avr_platform_t *pf, avr_address_t address);

#if defined(__cplusplus)
}
#endif

#endif /* AVR_LINUX_ENV_H */
