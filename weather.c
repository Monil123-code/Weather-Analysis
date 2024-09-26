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

// include the user library "weather" and "core" to use functions
#include "weather.h"
#include "core.h"

//////////////////////////////////////
// SERVICE SELECTION FUNCTION
//////////////////////////////////////

// Options: Weather Analysis
void weatherAnalysisOptions(struct WeatherRecord* data, int maxRecs)
{
    int selection = 0;

    do // continue looping until 0 is entered
    {
        printf("=======================================================\n"
            "         Ontario Weather Analysis Service\n"
            "                  Year: 2021\n"
            "=======================================================\n"
            "1. View all data\n"
            "2. View by region (sorted DESCENDING by precip.)\n"
            "3. View by month (sorted ASCENDING by precip.)\n"
            "4. View by location name (sorted DESCENDING by precip.)\n"
            "-------------------------------------------------------\n"
            "0. Exit\n"
            "-------------------------------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Application Terminated!");
            break;
        case 1:
            viewAllData(data, maxRecs);
            break;
        case 2:
            viewDataByRegion(data, maxRecs);
            break;
        case 3:
            viewDataByMonth(data, maxRecs);
            break;
        case 4:
            viewDataByLocationName(data, maxRecs);
            break;
        }
        putchar('\n');
    } while (selection != 0);
}

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// display all weather records
void viewAllData(struct WeatherRecord* data, int maxRecs)
{
    int i;

    printf("Year Month Precip.Amt Unit Region Name\n"
        "---- ----- ---------- ---- ------ ---------------\n");

    for (i = 0; i < maxRecs; i++)
    {
        if (i % 15 == 0 && i > 0)
        {
            suspend();
        }

        printf("%4d    %02d %10.1f %4c %6d %s\n",
            data[i].date.year, data[i].date.month,
            data[i].precipAmt, data[i].unit,
            data[i].location.regionCode,
            data[i].location.name);
    }

}

// display weather records by region (descending order by precip.)
void viewDataByRegion(struct WeatherRecord* data, int maxRecs)
{
    int i, j, regionValue, tempRegion;
    double total = 0.0;
    double tempPrecip = 0.0;
    int region[MAX_REGION] = { 10, 20, 30, 40 };
    double precip[MAX_REGION] = { 0 };

    // get total records for each region
    for (i = 0; i < maxRecs; i++)
    {
        regionValue = data[i].location.regionCode;

        switch (regionValue)
        {
        case 10:
            if (data[i].unit == 'c')
            {
                precip[0] = data[i].precipAmt * 10 + precip[0];
            }
            else if (data[i].unit == 'm')
            {
                precip[0] = data[i].precipAmt + precip[0];
            }
            break;
        case 20:
            if (data[i].unit == 'c')
            {
                precip[1] = data[i].precipAmt * 10 + precip[1];
            }
            else if (data[i].unit == 'm')
            {
                precip[1] = data[i].precipAmt + precip[1];
            }
            break;
        case 30:
            if (data[i].unit == 'c')
            {
                precip[2] = data[i].precipAmt * 10 + precip[2];
            }
            else if (data[i].unit == 'm')
            {
                precip[2] = data[i].precipAmt + precip[2];
            }
            break;
        case 40:
            if (data[i].unit == 'c')
            {
                precip[3] = data[i].precipAmt * 10 + precip[3];
            }
            else if (data[i].unit == 'm')
            {
                precip[3] = data[i].precipAmt + precip[3];
            }
            break;
        }

    }

    // Sort data in descending order
    for (i = 0; i < MAX_REGION - 1; i++) // iterate from last record
    {
        for (j = 0; j < MAX_REGION - i - 1; j++) //iterate from 2nd last record
        {
            if (precip[j] < precip[j + 1]) // compare two records
            {
                // swap records
                tempPrecip = precip[j]; // transfer precip to "tempPrecip"
                precip[j] = precip[j + 1];
                precip[j + 1] = tempPrecip;

                tempRegion = region[j]; // transfer region to "tempRegion"
                region[j] = region[j + 1];
                region[j + 1] = tempRegion;
            }
        }
    }

    // display records header
    printf("Region Name     Precip(mm)\n"
        "------ -------- ----------\n");

    // display records for each region
    for (i = 0; i < MAX_REGION; i++)
    {
        total = precip[i] + total;

        if (region[i] == 10)
        {
            printf("%6d %-8s %10.0lf\n", region[i], "Western", precip[i]);
        }

        if (region[i] == 20)
        {
            printf("%6d %-8s %10.0lf\n", region[i], "Northern", precip[i]);
        }

        if (region[i] == 30)
        {
            printf("%6d %-8s %10.0lf\n", region[i], "Eastern", precip[i]);
        }

        if (region[i] == 40)
        {
            printf("%6d %-8s %10.0lf\n", region[i], "Central", precip[i]);
        }

    }
    printf("------ -------- ----------\n");
    printf("         Total: %10.0lf\n", total);
    printf("       Average: %10.2lf\n", total / MAX_REGION);
}

// display weather records by month (ascending order by precip.)
void viewDataByMonth(struct WeatherRecord* data, int maxRecs)
{
    int i, j, tempMonth, monthValues;
    double total = 0;
    double tempPrecip = 0;
    int month[MAX_MONTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    double precip[MAX_MONTH] = { 0 };

    // get total records for each month
    for (i = 0; i < maxRecs; i++)
    {
        if (data[i].unit == 'c')
        {
            precip[data[i].date.month - 1] = data[i].precipAmt * 10 + precip[data[i].date.month - 1];
        }
        else if (data[i].unit == 'm')
        {
            precip[data[i].date.month - 1] = data[i].precipAmt + precip[data[i].date.month - 1];
        }

    }

    // Sort data by month in ascending order
    for (i = 0; i < MAX_MONTH - 1; i++) // iterate from last record
    {
        for (j = 0; j < MAX_MONTH - i - 1; j++) //iterate from 2nd last record
        {
            if (precip[j] > precip[j + 1]) // compare two records
            {
                // swap records
                tempPrecip = precip[j]; // transfer precip to "tempPrecip"
                precip[j] = precip[j + 1];
                precip[j + 1] = tempPrecip;

                tempMonth = month[j]; // transfer month to "tempMonth"
                month[j] = month[j + 1];
                month[j + 1] = tempMonth;
            }
        }
    }
   
    //display month header
    printf("Month     Precip(mm)\n"
        "--------- ----------\n");

    // display records for each month
    for (i = 0; i < MAX_MONTH; i++)
    {
        total = precip[i] + total;

        monthValues = month[i];

        switch (monthValues)
        {
        case 1:
            printf("%-9s %10.0lf\n", "January", precip[i]);
            break;
        case 2:
            printf("%-9s %10.0lf\n", "February", precip[i]);
            break;
        case 3:
            printf("%-9s %10.0lf\n", "March", precip[i]);
            break;
        case 4:
            printf("%-9s %10.0lf\n", "April", precip[i]);
            break;
        case 5:
            printf("%-9s %10.0lf\n", "May", precip[i]);
            break;
        case 6:
            printf("%-9s %10.0lf\n", "June", precip[i]);
            break;
        case 7:
            printf("%-9s %10.0lf\n", "July", precip[i]);
            break;
        case 8:
            printf("%-9s %10.0lf\n", "August", precip[i]);
            break;
        case 9:
            printf("%-9s %10.0lf\n", "September", precip[i]);
            break;
        case 10:
            printf("%-9s %10.0lf\n", "October", precip[i]);
            break;
        case 11:
            printf("%-9s %10.0lf\n", "November", precip[i]);
            break;
        case 12:
            printf("%-9s %10.0lf\n", "December", precip[i]);
            break;
        }

    }
    printf("--------- ----------\n");
    printf("   Total: %10.0lf\n", total);
    printf(" Average: %10.2lf\n", total / MAX_MONTH);
}

// display weather records by location name (descending order by precip.)
void viewDataByLocationName(struct WeatherRecord* data, int maxRecs)
{
    int i, j;
    double tempPrecip = 0;
    double total = 0;
    double precip[MAX_LOCATION] = { 0 };
    char location[MAX_LOCATION][20] = { "Chatham-Kent",
                                        "Halton",
                                        "Renfrew",
                                        "Kenora",
                                        "Simcoe",
                                        "Essex",
                                        "Ottawa",
                                        "Thunder Bay"
    };

    // get total records for each location
    for (i = 0; i < maxRecs; i++)
    {
        if (strcmp(data[i].location.name, "Chatham-Kent") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[0] = data[i].precipAmt * 10 + precip[0];
            }
            else if (data[i].unit == 'm')
            {
                precip[0] = data[i].precipAmt + precip[0];
            }
        }
        else if (strcmp(data[i].location.name, "Halton") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[1] = data[i].precipAmt * 10 + precip[1];
            }
            else if (data[i].unit == 'm')
            {
                precip[1] = data[i].precipAmt + precip[1];
            }
        }
        else if (strcmp(data[i].location.name, "Renfrew") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[2] = data[i].precipAmt * 10 + precip[2];
            }
            else if (data[i].unit == 'm')
            {
                precip[2] = data[i].precipAmt + precip[2];
            }
        }
        else if (strcmp(data[i].location.name, "Kenora") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[3] = data[i].precipAmt * 10 + precip[3];
            }
            else if (data[i].unit == 'm')
            {
                precip[3] = data[i].precipAmt + precip[3];
            }
        }
        else if (strcmp(data[i].location.name, "Simcoe") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[4] = data[i].precipAmt * 10 + precip[4];
            }
            else if (data[i].unit == 'm')
            {
                precip[4] = data[i].precipAmt + precip[4];
            }
        }
        else if (strcmp(data[i].location.name, "Essex") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[5] = data[i].precipAmt * 10 + precip[5];
            }
            else if (data[i].unit == 'm')
            {
                precip[5] = data[i].precipAmt + precip[5];
            }
        }
        else if (strcmp(data[i].location.name, "Ottawa") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[6] = data[i].precipAmt * 10 + precip[6];
            }
            else if (data[i].unit == 'm')
            {
                precip[6] = data[i].precipAmt + precip[6];
            }
        }
        else if (strcmp(data[i].location.name, "Thunder Bay") == 0)
        {
            if (data[i].unit == 'c')
            {
                precip[7] = data[i].precipAmt * 10 + precip[7];
            }
            else if (data[i].unit == 'm')
            {
                precip[7] = data[i].precipAmt + precip[7];
            }
        }
    }

    // Sort data by location name in descending order
    for (i = 0; i < MAX_LOCATION - 1; i++) // iterate from last record
    {
        for (j = 0; j < MAX_LOCATION - i - 1; j++) // iterate from 2nd last record
        {
            if (precip[j] < precip[j + 1]) // compare two records
            {
                char tempLocation[20];
                // swap records
                tempPrecip = precip[j]; // transfer precip to "tempPrecip"
                precip[j] = precip[j + 1];
                precip[j + 1] = tempPrecip;

                strcpy(tempLocation, location[j]); // transfer precip to "tempPrecip"
                strcpy(location[j], location[j + 1]);
                strcpy(location[j + 1], tempLocation);
            }
        }
    }

    printf("Location        Precip(mm)\n"
        "--------------- ----------\n");

    for (i = 0; i < MAX_LOCATION; i++)
    {
        total = precip[i] + total;
        printf("%15s %10.0lf\n", location[i], precip[i]);
    }

    printf("--------------- ----------\n");
    printf("         Total: %10.0lf\n", total);
    printf("       Average: %10.2lf\n", total / MAX_LOCATION);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// read weather records from file
int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)
{
    int recs = 0;

    if (fp != NULL)
    {
        while (recs < max &&
            fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",
                &data[recs].date.year, &data[recs].date.month,
                &data[recs].precipAmt, &data[recs].unit,
                &data[recs].location.regionCode,
                data[recs].location.name) == 6)
        {
            recs++;
        }
    }

    return recs;
}