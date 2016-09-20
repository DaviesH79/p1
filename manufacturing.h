//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 3
// File Name  : manufacturing.h
// ---------------------------------------------------------------------------------- 

#ifndef manufacturing_h
#define manufacturing_h

#include "state.h"


// Declare all the functions that can be performed
// when in the manufacturing state

static state_t* manufacture_completed();
static state_t* manufacture_failed();
static void entry_to_manufacturing();
static void exit_from_manufacturing();

#endif
