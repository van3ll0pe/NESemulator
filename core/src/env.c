#include <mos6502/env.h>
#include <mos6502/config.h>
#include <mos6502/loader.h>



/* generic (nearly void) stack and system initialization,
   does the strict minimum */


/* !!WARNING!! could be an invalid address for a stack pointer on some archi */
#define STACKADDR_DESCENDING_DEFAULT 0xF0000000
/* no size advised, to my knowledge */
#define STACKSIZE_DEFAULT 0x1000000



/**
 * initialize the stack pointer with the default value,
 * checking code and data may not overlap with the forecast stack size.
 * @param	loader	Loader containing code and data size informations.
 * @return		the initial stack pointer value, 0 if there's an error (overlapping)
 */
static mos6502_address_t mos6502_stack_pointer_init(mos6502_loader_t *loader)
{
	/*if (loader == 0)
		return 0;

	uint32_t data_max = loader->Data.size + loader->Data.address;
	uint32_t code_max = loader->Text.size + loader->Text.address;
	uint32_t addr_max = (data_max > code_max) ? data_max : code_max;
*/
	/* check if code/data and stack don't overlap */
/*	if (addr_max >= STACKADDR_DESCENDING_DEFAULT - STACKSIZE_DEFAULT)
		return 0;*/

	return STACKADDR_DESCENDING_DEFAULT;
}



/**
 * system initialization of the stack, program arguments, environment and auxilliar
 * vectors are written in the stack. some key addresses are stored for later register initialization.
 * @param	loader	informations about code and data size.
 * @param	platform	platform whose memory contains the stack to initialize.
 * @param	env	contains the data to write in the stack, the addresses of written data are stored in it by the function.
 *
 */
void mos6502_stack_fill_env(mos6502_loader_t *loader, mos6502_platform_t *platform, mos6502_env_t *env)
{
}



/**
 * Initialize a state's registers with systems value collected during stack initialization
 * @param	env	structure containing the values to put in specific registers
 * @param	state	the state whose registers will be initialized
 */
void mos6502_registers_fill_env(mos6502_env_t *env, mos6502_state_t *state)
{
}


/**
 * Fix the position of the brk base (top address of memory).
 * @param pf            Platform to work with.
 * @param address       New address of the brk base.
 */
void mos6502_set_brk(mos6502_platform_t *pf, mos6502_address_t address) {
	/* do nothing */
}
