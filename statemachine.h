// This is a finite state machine!

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

struct state_data_inner;

typedef void (*state)(struct state_data_inner*);

#ifdef STATEMACHINE_PARAMS
typedef struct state_data_inner {
	state next_state;
	STATEMACHINE_PARAMS
} state_data;
#else
typedef struct state_data_inner {
	state next_state;
} state_data;
#endif


// functions
void state_machine(state_data * data);

#endif