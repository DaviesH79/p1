//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 10/07/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
// Group			: 4
// File Name  : system.c
// ---------------------------------------------------------------------------------- 

#include "system.h"
#include <stdio.h>
#include <stdlib.h>

// This file contains all  effects on the transitions (all the functions that will be used
// during transitions or entry/exit) 

// Attempts
void resetAttempts(attempts value){
	value = 0;
}

int incrementAttempts(int value){
	return value++;
}

// Get order size
//void getOrderSize() {
//	printf("Got an order size = %d items\n", order_size);
//}

// Payment processing
void getPymntMethod() {
	printf("Getting Payment Method\n");
}

void chargeClient() {
	printf("Client has been charged\n");
}

void paymentRejected() {
	printf("Payment Rejected\n");
}

void refund() {
	printf("Client has been refunded\n");
}

// Manufactoring - there are five manufactoring lines
// Generate capacity and duration to pass as thread argument
//void * dispatchFactoryLines(void * p) {
//	printf("Dispatching Factory Lines\n");
//}

void shutDownFactoryLines() {
	printf("Shutting Down Factory Lines\n");
}

// Shipping
void getAddress() {
	printf("Getting Ship-To Address\n");
}

void startWarranty() {
	printf("Warranty has started\n");
}

// Update status
void updateStats(status value) {
	if		  (value == FAIL) printf("Updating Statistics with order FAIL.\n");
	else if (value == LOST) printf("Updating Statistics with order LOST.\n");
	else if (value == DONE) printf("Updating Statistics with order DONE.\n");
}

	
