/*
*****************************************************************************
                             Project 1
Full Name  : Kashish Insan
Full Name  : Lakshay Arora
Full Name  : Monilkumar Kishorbhai Patel

*****************************************************************************
*/

#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//Get a valid integer from the keyboard.
int inputInt(void);

//Get a valid integer from the keyboard within a valid range.
int inputIntRange(int lowerLimit, int upperLimit);

#endif

