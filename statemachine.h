// This is a finite state machine!

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "klib.h"

struct state_data;

// casting from a regular void pointer (a data pointer) to a function pointer is undefined behaviour.
// therefore i've created a junk function pointer type to use as a sort of "void function pointer"
/// also this is necessary because i can't make the typedef return its own type; C doesn't allow recursive typedefs :(
typedef void* (*state_inner)(void);
typedef state_inner(*state)(struct state_data*);

#ifdef STATEMACHINE_PARAMS
typedef struct state_data {
	STATEMACHINE_PARAMS
} state_data;
#else
typedef struct state_data state_data;
#endif


// functions
void state_machine(state_data * data);

// the user will define this function in a compilation unit of their choosing.
state init(state_data* data);

#endif