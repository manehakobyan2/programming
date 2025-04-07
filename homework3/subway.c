#include <stdio.h>

//Defining the states that the subway entry can be in
typedef enum
{
	WAIT, //Initial state where the machine is waiting for input
	VALIDATING, //Validating the token input
	OPEN //State when the entry opens
	//Since the doors close and open instanteniously there is no need for opening or closing
	//There is also no need for closed because Wait is automatically closed
}State;

//Defining the inputs 
typedef enum
{
	INSERT,//Inserting the token
	INVALID,//writing what is the input
        VALID,
	TIME //This is for closing the gate, the open state should be changed to Wait after some time
}Input;

//This function is for converting the the state to string for printing later
const char* state_string(State state)
{
	//checks the case and returns coresponding string
	switch(state)
	{
		case WAIT: return "Wait";
		case VALIDATING: return "Validating";
		case OPEN: return "Open";
		default: return "Unkown Error";
	}
}

const char* input_string(Input input)
{
	switch(input)
	{
		case INSERT: return "Insert";
		case INVALID: return "Invalid_token";
		case VALID: return "Valid_token";
		case TIME: return "Timeout";
	}
}

//Function to change States 
State state_change(State state, Input input)
{
	//Taking state and checking the input
	switch (state)
	{
		case WAIT:
			if (input == INSERT) return VALIDATING;
			break;
		case VALIDATING:
			if(input == INVALID) return WAIT;
			if(input == VALID) return OPEN;
			break;
		case OPEN:
			if (input == TIME) return WAIT;
			break;
	}
	return state;
}

int main ()
{
	//Setting intial state to be Wait
	State state = WAIT;

	//Manually simulating inputs
	Input a[] ={INSERT, VALID,TIME,INSERT, INVALID};

	//Finding the size 
	int n = sizeof(a)/sizeof(a[0]);
	//Using the manually simulated inputs to generate states
	for (int i = 0; i<n; i++)
	{
		//Printing everything
		printf("State: %s | Input: %s-->", state_string(state), input_string(a[i]));
		//Calling the function to change state
		state = state_change(state, a[i]);
		printf("New state: %s\n", state_string(state));
	}
	return 0;
}


