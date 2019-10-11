# stupid-simple-state-machine
A barebones state machine framework for C.
Want to make a state machine but don't want to think about setup? Just use this library and start writing those states!

## How to use
This state machine is based on function pointers that return pointers
to other functions. Each one is passed a single argument, a pointer
to a state_data structure. 

### The data
First, define STATEMACHINE_PARAMS with struct fields for your states to use.

For example: 

```c
#define STATEMACHINE_PARAMS int num_players; int current_player; int dice[6]; char* message;
```
Inside your state functions, you will access a struct pointer to use these fields, like this: `data->FIELD_NAME`.

**Make sure you define STATEMACHINE_PARAMS *before* you include the library!**

### The states
You create states by creating functions with this header: `state STATE_NAME(state_data* data)`.

Example:
```c
state init(state_data* data)
{
 . . .
 return <insert next state function here>;
}
```
Each state function returns a pointer to the next state to be executed. 
Your final state should return `NULL` when the statemachine is ready to end.

### Using it
Create a `state_data` struct and pass its address to the `state_machine`, along with the pointer to your first state function.
```c
int main(void)
{	
 state_data data;
 state_machine(&data, init);
 return 0;
}
```
The state_machine function will run until it hits a NULL state address, at which point it will finally quit.
