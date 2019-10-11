#ifndef STATEMACHINE_H
#define STATEMACHINE_H

struct state_data;

// casting from a regular void pointer (a data pointer) to a function pointer is undefined behaviour.
// therefore i've created a junk function pointer type to use as a sort of "void function pointer"
/// also this is necessary because i can't make the typedef return its own type; C doesn't allow recursive typedefs :(
typedef void* (*state_inner)(void);
typedef state_inner(*state)(struct state_data*);

#ifndef STATEMACHINE_PARAMS
#define STATEMACHINE_PARAMS
#endif

// The data structure for the states. Define params before including this file to 
// set the user fields.
typedef struct state_data {
	state next_state;
	int return_code;
	STATEMACHINE_PARAMS
} state_data;


// The function that runs the state machine.
// Call this in your own code and pass it a state_data struct
int state_machine(state_data* data);

// define this function in your own compilation unit. It's the initial state that
// is run.
state init(state_data* data);

#endif