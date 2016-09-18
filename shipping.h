//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : shipping.h
// ---------------------------------------------------------------------------------- 

#ifndef shipping_h
#define shipping_h

#include "state.h"


// Declare all the functions that can be performed
// when in the shipping state

static state_t* shipment_arrived();
static state_t* shipment_lost();
static void entry_to_shipping();

#endif
