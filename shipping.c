//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : shipping.c
// ---------------------------------------------------------------------------------- 

#include "shipping.h"
#include "system.h"			// For transition and entry/exit functions
#include "state.h"			// For the event handlers
#include "statemodel.h" // For the other states

// Create an object of the shipping state
state_t manufacturing = {
		default_event_handler,  // order_received
		default_event_handler, 	// valid_payment
		default_event_handler,	// invalid_payment
		default_event_handler,  // manufacture_completed
		default_event_handler,  // manufacture_failed
		shipment_arrived,       // shipment_arrived
		shipment_lost,          // shipment_lost
		entry_to_shipping,      // entry_to
};

// Call shipment arrived handler, start the warranty, update
// status, return address of accepting state
state_t* shipment_arrived()
{
	startWarranty();
	updateStats(DONE);
	return &accepting;
}

// Call shipment failed handler, refund, update status,
// return address of accepting state
state_t* shipment_lost()
{
	refund();
	updateStats(LOST);
 	return &accepting;
}

// Set the action when entering the shipping state
static void entry_to_shipping()
{
	getAddress();
}
