/*
*****************************************************************************
							 Project 1
Full Name  : Kashish Insan
Full Name  : Lakshay Arora
Full Name  : Monilkumar Kishorbhai Patel

*****************************************************************************
*/

#ifndef WEATHER_H
#define WEATHER_H

#include <stdio.h>
#include <string.h>

//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////
#define MAX_RECORDS 250
#define MAX_REGION 4
#define MAX_MONTH 12
#define MAX_LOCATION 8

//////////////////////////////////////
// Structures
//////////////////////////////////////
struct Date
{
	int year;
	int month;
};

struct Location
{
	int regionCode;
	char name[20];
};

struct WeatherRecord
{
	struct Date date;
	double precipAmt;
	char unit;
	struct Location location;
};


//////////////////////////////////////
// SERVICE SELECTION FUNCTION
//////////////////////////////////////

// Options: Weather Analysis
void weatherAnalysisOptions(struct WeatherRecord* data, int maxRecs);

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// display all weather records
void viewAllData(struct WeatherRecord* data, int maxRecs);

// display weather records by region (descending order by precip.)
void viewDataByRegion(struct WeatherRecord* data, int maxRecs);

// display weather records by month (ascending order by precip.)
void viewDataByMonth(struct WeatherRecord* data, int maxRecs);

// display weather records by location name (descending order by precip.)
void viewDataByLocationName(struct WeatherRecord* data, int maxRecs);

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// read weather records from file
int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);

#endif


