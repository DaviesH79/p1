//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : processing.c
// ---------------------------------------------------------------------------------- 

#include "processing.h"
#include "system.h"			// For transition and entry/exit functions
#include "state.h"			// For the event handlers
#include "statemodel.h" // For the other states
#include <stdio.h>

// Create an object of the processing state
state_t processing = {
		default_event_handler,  // order_received
		valid_payment, 					// valid_payment
		invalid_payment,				// invalid_payment
		default_event_handler,  // manufacture_completed
		default_event_handler,  // manufacture_failed
		default_event_handler,  // shipment_arrived
		default_event_handler,  // shipment_lost
		entry_to_processing,		// entry_to
};
	

// Call the valid payment handler, return address of manufacturing
state_t* valid_payment()
{
	resetAttempts(0);
 	return &manufacturing;
} 

// Call the invalid payment handler
// TODO implement logic for incrementAttempts and paymentRejection	
state_t* invalid_payment()
{
	static int value = 0;		// default attempts
		if (value > 2) 
		{
 			paymentRejected();
			return &accepting;
		} else {
			value++;
			return &processing;
		}
}
// Set the action when entering the processing state
static void entry_to_processing()
{
	getPymntMethod();
}	

