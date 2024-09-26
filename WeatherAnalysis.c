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

#include "weather.h"
#include "core.h"

// start program
int main()
{
    int maxRecs = 0;
    FILE* fp = NULL;
    struct WeatherRecord data[MAX_RECORDS];

    fp = fopen("weatherdata.txt", "r"); // open the weatherdata.txt file

    // If the file is opened, save the items from the array
    if (fp != NULL)
    {
        maxRecs = importWeatherDataFile(fp, data, MAX_RECORDS); // read weather records from file

        // Closes the file
        fclose(fp);
        fp = NULL;

        weatherAnalysisOptions(data, maxRecs);
    }
    else
    {
        puts("ERROR: FAILED to open file!");
    }

    return 0;
}