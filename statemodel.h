//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : statemodel.h 
// ---------------------------------------------------------------------------------- 

#ifndef statemodel_h
#define statemodel_h

#include <stdlib.h>
#include "state.h"
#include "system.h"

// Declare all of the states used in the state model.
// They are extern because they are defined (i.e., the  memory is 
// actually allocated) elsewhere (i.e., in the .c files for the 
// individual states).

extern state_t accepting;
extern state_t processing;
extern state_t manufacturing;
extern state_t shipping;


// Declare all of the functions.

void handle_event( event current_event );

void printStateName(void);

#endif
