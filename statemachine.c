#include "statemachine.h"

void state_machine(state_data* data) {
	while (data->next_state) {
		state current_state = data->next_state;
		data->next_state = panic_builtin;
		current_state(data);
	}
}

void panic_builtin(state_data * data) {
	_STATE_CLEAR;
	printf("Error: previous state did not specify next state!\n\n");
	_STATE_PAUSE;
	data->next_state = NULL;
	data->return_code = INT_MAX;
}

#undef _STATE_CLEAR
#undef _STATE_PAUSE