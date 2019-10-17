// This is a finite state machine!

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <limits.h>
#include <stdio.h>

struct state_data_inner;

typedef void (*state)(struct state_data_inner*);

typedef struct state_data_inner {
	state next_state;
	int return_code;
	#ifdef STATEMACHINE_PARAMS
	STATEMACHINE_PARAMS
	#endif
} state_data;


// functions
void state_machine(state_data * data);
void panic_builtin(state_data * data);

// ==========================================================================
// OS DEPENDENT
// ==========================================================================
#if defined(_WIN32) || defined (_WIN64) // windows
	#define _STATE_CLEAR system("cls")
#elif defined (__linux__)
	// TODO: change this to something more platform independent.
	#define _STATE_CLEAR printf("\033[H\033[J")
#elif defined (OS_OVERRIDE)

#else
	#error Unrecognized OS. Please find out how to define for this system.
#endif

#define _STATE_PAUSE printf("Press enter to continue."); for (int c; (c =getchar()) != '\n' && c != EOF;)

#endif