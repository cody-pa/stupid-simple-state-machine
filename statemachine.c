#include "statemachine.h"

int state_machine(state_data* data) {
	data->next_state = init; 
	data->return_code = 0;
	while (data->next_state = data->next_state(&data));
	return data->return_code;
}