#include "statemachine.h"

void state_machine(state_data* data, state initial_state) {
	state next_state = initial_state;
	while (next_state = next_state(data));
}