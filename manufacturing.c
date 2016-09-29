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

extern int order_size;
extern int args_t;

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

// Set the action when entering the manufacturing state
// Create five threads to represent manufacturing lines
static void entry_to_manufacturing()
{
	//dispatchFactoryLines();
	pthread_t thread;

	int i, lines;
	lines = 5;

	for(i = 0; i < lines; i++)
	{
	 	x = malloc(sizeof (args_t));
		pthread_create(&thread, NULL, dispatchFactoryLines, (void *) x);
	free(x);
	printf("Order Size = %d\n", order_size);
}

// Set the action when exiting the manufacturing state
static void exit_from_manufacturing()
{
	shutDownFactoryLines();
}
	
		
