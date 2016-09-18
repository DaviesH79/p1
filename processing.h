//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : processing.h
// ---------------------------------------------------------------------------------- 

#ifndef processing_h
#define processing_h

#include "state.h"


// Declare all the functions thta can be performed
// when in the processing state

static state_t* valid_payment();
static state_t* invalid_payment();
static void entry_to_processing();

#endif
