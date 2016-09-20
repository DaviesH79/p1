//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : statemodel.c 
// ---------------------------------------------------------------------------------- 

#include "statemodel.h"
#include "system.h"
#include <stdlib.h>
#include <stdio.h>

// Define the initial state.
static state_t* current_state = & accepting;

void printStateName(void)
{
    printf("Current State is: ");
    if ( current_state == &accepting )
        printf( "ACCEPTING" );
    else if ( current_state == &processing )
        printf( "PROCESSING" );
    else if ( current_state == &manufacturing )
            printf( "MANUFACTURING" );
    else if ( current_state == &shipping )
            printf( "SHIPPING" );
    printf("\n");
}

// set next state after event, print current state
void handle_event( event current_event )
{
    state_t* next_state;

    next_state = NULL;
    switch( current_event ) // exit current_state and have the approprite effect
    {
        case ORDER_RECEIVED:
            next_state = current_state->order_received();
            break;
        case VALID_PAYMENT:
            next_state = current_state->valid_payment();
            break;
        case MANUFACTURE_COMPLETED:
            next_state = current_state->manufacture_completed();
            break;
        case SHIPMENT_ARRIVED:
            next_state = current_state->shipment_arrived();
            break;
				case INVALID_PAYMENT:
						next_state = current_state->invalid_payment();
						break;
				case MANUFACTURE_FAILED:
						next_state = current_state->manufacture_failed();
						break;
				case SHIPMENT_LOST:
						next_state = current_state->shipment_lost();
						break;
    }    

    if (next_state != NULL)
    {
        current_state = next_state; // Change states
        current_state->entry_to();  // enter the new state
        printStateName();
    }
}
