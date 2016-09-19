//-----------------------------------------------------------------------------------
// Assignment : Phase One
// Date       : 09/22/2016
//
// Author     : Holly Davies davieshf@dukes.jmu.edu, Justin Hux huxdr@dukes.jmu.edu
//
// File Name  : system.c
// ---------------------------------------------------------------------------------- 

#include "system.h"
#include <stdio.h>

// This file contains all  effects on the transitions (all the functions that will be used
// during transitions or entry/exit) 

// Attempts
void resetAttempts(attempts value){
	value = 0;
}

void incrementAttempts(attempts value){
	value++;
}

// Get order size
void getOrderSize() {
	printf("Getting Order Size");
}
// Payment processing
void getPymntMethod() {
	printf("Getting Payment Method");
}

void chargeClient() {
	printf("Client has been charged");
}

void paymentRejected() {
	printf("Payment Rejected");
}

void refund() {
	printf("Client has been refunded");
}

// Manufactoring
void dispatchFactoryLines() {
	printf("Dispatching Factory Lines");
}

void shutDownFactoryLines() {
	printf("Shutting Down Factory Lines");
}

// Shipping
void getAddress() {
	printf("Getting Ship-To Address");
}

void startWarranty() {
	printf("Warranty has started");
}

// Update status
void updateStats(status value) {
	if		  (value == FAIL) printf("Updating Statistics with order FAIL.");
	else if (value == LOST) printf("Updating Statistics with order LOST.");
	else if (value == DONE) printf("Updating Statistics with order DONE.");
}

	
