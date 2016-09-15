//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : statemodel.c 
// ---------------------------------------------------------------------------------- 

#include "statemodel.h"
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
    else if ( current_state == &manufactoring )
            printf( "MANUFACTORING" );
    else if ( current_state == &shipping )
            printf( "SHIPPING" );
    printf("\n");
}

void handle_event( event current_event )
{
    state_t* next_state;

    next_state = NULL;
    switch( current_event ) // exit current_state and have the approprite effect
    {
        case CLOSE_BUTTON_PRESSED:
            next_state = current_state->close_button_pressed();
            break;
        case CLOSED_DETECTED:
            next_state = current_state->closed_detected();
            break;
        case OPEN_BUTTON_PRESSED:
            next_state = current_state->open_button_pressed();
            break;
        case OPENED_DETECTED:
            next_state = current_state->opened_detected();
            break;
    }    

    if (next_state != NULL)
    {
        current_state = next_state; // Change states
        current_state->entry_to();  // enter the new state
        printStateName();
    }
}
