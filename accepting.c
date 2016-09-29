//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : accepting.c
// ---------------------------------------------------------------------------------- 

#include "accepting.h"
#include "system.h"
#include "state.h"
#include "statemodel.h" // For the other states

int order_size;

// Create the object of the accepting state
state_t accepting = {
		order_received,					// order_received
		default_event_handler,  // valid_payment
		default_event_handler,  // invalid_payement
		default_event_handler,  // manufacture_completed
		default_event_handler,  // manufacture_failed
		default_event_handler,  // shipment_arrived
		default_event_handler,  // shipment_lost
		entry_to_accepting			// entry_to
};

// call the order received handler, exit from opening,
// and return address of processing state

state_t* order_received()
{
	getOrderSize();
	resetAttempts(0);
	return &processing;
}

static void entry_to_accepting()
{
}
	 	 
void getOrderSize() {
	order_size = random() % (2000 + 1 - 1000) + 1000;
}


