/*
*  Title:  Airport Stats
*  Desc:   This program uses structures to store monthly info for an airport.
*  Author: Bryce Verberne
*  Date:   04/06/2023
*/



#include <iostream>
using namespace std;

// The 'airportInfo' structure holds data about the airport's plane activities.
struct airportInfo {
    int landed;        // Total number of planes landed
    int departed;      // Total number of planes departed
    int mostLandings;  // Greatest number of planes landed in a single day during the month
    int leastLandings; // Least number of planes landed in a single day during the month
};

// Prototypes
void fillArray(airportInfo *travelInfo, string *calendar);
void leastGreatest(airportInfo *travelInfo, string *calendar);
void average(airportInfo *travelInfo);
void totalPlanes(airportInfo *travelInfo);

int main() {

    cout << "This program stores an airport's monthly landings & departures." << endl << endl;

    // Create an array of 12 structures to hold travel info for an entire year
    airportInfo travel[12];

    // Create an array that holds each month
    string months[] = {"January", "February", "March", "April", "May",
                       "June", "July", "August", "September", "October",
                       "November", "December"};

    // Prompt the user for input & store it in the array
    fillArray(travel, months);

    cout << "In Summary:" << endl;

    // Find the total departures & landings that year, calculate the average, & output average to console
    average(travel);

    // Find the total landings & departures that year, then output the total to the console
    totalPlanes(travel);

    // Calculate & output greatest & least amount that landed on any one day & the month it occurred on
    leastGreatest(travel, months);

    return 0;
}


// fillArray Function Description:
//  - Prompts the user for input & stores it in the array
//  - Two parameters:
//     1. airportInfo Pointer - Points to array of structures (airportInfo)
//     2. string pointer      - Points to array of strings
//  - Return: No return (void)
void fillArray(airportInfo *travelInfo, string *calendar) {
    // Prompt user to enter data for each month.
    for (int i = 0; i < 12; ++i) {
        // Prompt user to input data for a particular month
        cout << "Enter data for " << calendar[i] << "." << endl;

        // Prompt user for data on the number of planes that landed
        cout << "Total Planes Landed: ";
        cin >> travelInfo[i].landed;

        // Prompt user for data on the number of planes that departed
        cout << "Total Planes Departed: ";
        cin >> travelInfo[i].departed;

        // Prompt user for the most landings in a given day that month
        cout << "Most Landings in a Given Day: ";
        cin >> travelInfo[i].mostLandings;

        // Prompt user for the least landings in a given day that month
        cout << "Least Landings in a Given Day: ";
        cin >> travelInfo[i].leastLandings;

        cout << endl;
    }

    cout << endl;
}


// average Function Description:
//  - Finds the total landings & departures that year & calculates the average
//  - One parameter:
//     1. airportInfo Pointer - Points to array of structures (airportInfo)
//  - Return: No return (void)
void average(airportInfo *travelInfo) {
    int totalLand = 0;    // Total landings that year
    int totalDepart = 0;  // Total departures that year
    int average;    // Calculated average planes that land every month

    // Outputs the average amount of planes that land each month
    for (int i = 0; i < 12; ++i) {
        totalLand += travelInfo[i].landed;
        totalDepart += travelInfo[i].departed;
    }

    // Calculate & print landing average
    average = totalLand / 12;
    cout << "Average Landings Monthly: " << average << endl;

    // Calculate & print departure average
    average = totalDepart / 12;
    cout << "Average Departures Monthly: " << average << endl;
}


// totalPlanes Function Description:
//  - Finds the total landings & departures that year
//  - One parameter:
//     1. airportInfo Pointer - Points to array of structures (airportInfo)
//  - Return: No return (void)
void totalPlanes(airportInfo *travelInfo) {
    int total = 0;  // Total landings & departures that year

    for (int i = 0; i < 12; ++i) {
        total += travelInfo[i].departed + travelInfo[i].landed;
    }

    cout << "Total Landings & Departures This Year: " << total << endl;
}


// leastGreatest Function Description:
//  - Finds the least & greatest amount of landings on a given month & prints it to console
//  - Two parameters:
//     1. airportInfo Pointer - Points to array of structures (airportInfo)
//     2. string pointer      - Points to array of strings
//  - Return: No return (void)
void leastGreatest(airportInfo *travelInfo, string *calendar) {
    int max = travelInfo[0].mostLandings;
    int min = travelInfo[0].leastLandings;
    int maxMonth;
    int minMonth;

    for (int i = 0; i < 12; ++i) {
        if (max < travelInfo[i].mostLandings) {
            max = travelInfo[i].mostLandings;
            maxMonth = i;
        }

        if (min > travelInfo[i].leastLandings) {
            min = travelInfo[i].leastLandings;
            minMonth = i;
        }
    }

    cout << "There was a high of " << max << " landing(s) in " << calendar[maxMonth] << "." << endl;
    cout << "There was a low of " << min << " landing(s) in " << calendar[minMonth] << "." << endl;
}