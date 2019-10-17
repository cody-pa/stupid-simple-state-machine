#include "statemachine.h"

void state_machine(state_data* data) {
	while (data->next_state) data->next_state(data);
}