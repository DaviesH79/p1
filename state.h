//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : state.h
// ---------------------------------------------------------------------------------- 

#ifndef state_h
#define state_h

// Add an alias for a type to the global name space.
typedef struct state state_t; 

// Add an alias for event handlers.
typedef state_t * event_handler(void);
 
// Add an alias for actions.
typedef void action(void);

// Define format of state struct.
struct state {
  event_handler* ORDER_RECEIVED;
  event_handler* VALID_PAYMENT;
  event_handler* INVALID_PAYMENT;
  event_handler* MANUFACTURE_COMPLETED;
  event_handler* MANUFACTURE_FAILED;
  event_handler* SHIPMENT_ARRIVED; 
  event_handler* SHIPMENT_LOST;
  action*        entry_to;
  action*        exit_from;
};

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();

#endif


