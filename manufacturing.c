//-----------------------------------------------------------------------------------
// Assignment : Phase Two: Threads
// Date       : 10/07/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 4
// File Name  : manufacturing.c
// ---------------------------------------------------------------------------------- 

#include "manufacturing.h"
#include "system.h"			// For transition and entry/exit functions
#include "state.h"			// For the event handlers
#include "statemodel.h" // For the other states
#include <stdio.h>
#include <pthread.h>

extern int order_size;

typedef struct {
	int capacity, 
			duration;
} args_t;

args_t * x;

//***************never declare a variable in a header or include a .c in header of .c file
// Create an object of the manufacturing state
state_t manufacturing = {
		default_event_handler,  // order_received
		default_event_handler, 	// valid_payment
		default_event_handler,	// invalid_payment
		manufacture_completed,  // manufacture_completed
		manufacture_failed,     // manufacture_failed
		default_event_handler,  // shipment_arrived
		default_event_handler,  // shipment_lost
		entry_to_manufacturing, // entry_to
		exit_from_manufacturing,// exit_from
};

// Call the manufacture completed handler, exit from,
// return address of shipping
state_t* manufacture_completed()
{
	exit_from_manufacturing();
	chargeClient();
	return &shipping;
}

// Call the manufacture failed handler, exit from, and update the status
//TODO this function is returning to the manufacturing state... why?
state_t* manufacture_failed()
{
	exit_from_manufacturing();
	updateStats(FAIL);
	return &accepting;
}
// need a sema
// Set the action when entering the manufacturing state
// Create five threads to represent manufacturing lines
static void entry_to_manufacturing()
{
	// need a sema here create mutex set to init sem (x=1) ****
	//dispatchFactoryLines();
	pthread_t threads;
	int i, lines;
	lines = 5;
  
	// create thread for each man line
	for(i = 0; i < lines; i++)
	{
	 	x = malloc(sizeof (args_t));
	  x->capacity = random() % (50 + 1 - 10) + 10;
	  x->duration = random() % (5 + 1 - 1) + 1;
		pthread_create(&threads, NULL, dispatchFactoryLines, (void *) x);
	printf("Order Size = %d\n", order_size);
	}
}

// Set the action when exiting the manufacturing state
static void exit_from_manufacturing()
{
	shutDownFactoryLines();
}
	
void * dispatchFactoryLines(void * p) {
	printf("Dispatching Factory Lines\n");
	args_t * x = (args_t *) p;
	free(x);
	int c = x->capacity;
	int d = x->duration;
}

// each thread will look at how many items reaning to be made it end else it continues
// while loop while(more2make() > 0 {
// more2make function returns how mnay you will make, either your capacity or whatever is left, get capactiy as agr, and check how many are left to make
// decrement number of items left to be made 
// 2bmade, myCap, myTask <- before 
// after return 2Bmade to zero is no tasks left
// ^^^^ more to make function needs to be protected by a mutex
// mutex inside loop or not inside the more2makefunc? grab mutex closer to critical point, need var iter and made for while loop
// sleep (duration);
// ++ iters;
// made += y;
// }
// print made / iterations   ... i think this is happeining in dispatch factory lines
// pthread_exit( retval/made/iters) pass a return value on exit (look at lab that does that)
/*
shutdownfl()
{
 join 5 threads (in order)
 destroy semaphores
 free pointer that had return
*/

















