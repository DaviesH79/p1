//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : system.h
// ---------------------------------------------------------------------------------- 

#ifndef system_h
#define system_h

// Events.
typedef enum
	{
		ORDER_RECEIVED,
		VALID_PAYMENT,
		MANUFACTURE_COMPLETED,
		SHIPMENT_ARRIVED,
		INVALID_PAYMENT,
		MANUFACTURE_FAILED,
		SHIPMENT_LOST
	} event;

// Order status
typedef enum
	{
		FAIL,
		LOST,
		DONE
	} status;

// Payment attempts
typedef enum
	{
		ATTEMPTS,
	} attempts;
#define INVALID_EVENT		-1

// Function for order received
void resetAttempts(attempts value);

// Get order size
void getOrderSize();

// Functions for processing and payment
void getPymntMethod();

void chargeClient();

void paymentRejected();

void incrementAttempts(attempts value); 

void refund();

// Functions for manufactoring lines
void dispatchFactoryLines();

void shutDownFactoryLines();

// Functions for shipping
void getAddress();

void startWarranty();

// Functions for stats
void updateStats(status value);

#endif
