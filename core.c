/*
*****************************************************************************
                             Project 1
Full Name  : Kashish Insan
Full Name  : Lakshay Arora
Full Name  : Monilkumar Kishorbhai Patel

*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("\n< Press [ENTER] key to continue >");
    clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//Get a valid integer from the keyboard.
int inputInt(void)
{
    char newLine = 'x';
    int value;

    do {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }

    } while (newLine != '\n');

    return value;
}

//Get a valid integer from the keyboard within a valid range.
int inputIntRange(int lowerLimit, int upperLimit)
{
    int value;
    value = inputInt();

    while (value < lowerLimit || value > upperLimit)
    {
        printf("ERROR! Value must be between %d and %d inclusive: ", lowerLimit, upperLimit);
        value = inputInt();
    }

    return value;
}