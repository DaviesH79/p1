//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : driver.c
// ---------------------------------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "statemodel.h"

int 
main()
{

	printStateName();		// to print initial state
	event new_event;		// event type variable to hold new event
	char key;						// variable to hold input

	// continually get key from input, switch on key, call appropriate event handler
	while ((key = getchar()) != 'X') {
				new_event = INVALID_EVENT;
				switch(key)
				{
					case 'O':
						new_event = ORDER_RECEIVED;
						break;
					case 'V':
						new_event = VALID_PAYMENT;
						break;
					case 'I':
						new_event = INVALID_PAYMENT;
						break;
					case 'F':
						new_event = MANUFACTURE_FAILED;
						break;
					case 'C':
						new_event = MANUFACTURE_COMPLETED;
						break;
					case 'R':
						new_event = SHIPMENT_ARRIVED;
						break;
					case 'L':
						new_event = SHIPMENT_LOST;
						break;
				}
				if (new_event != INVALID_EVENT) {
							handle_event(new_event);
				}
		}
	exit(0);
}
					
