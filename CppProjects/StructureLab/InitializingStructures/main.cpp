/*
*  Title:  Initializing Structures
*  Desc:   This program demonstrates partially initialized structure variables.
*  Author: Bryce Verberne
*  Date:   04/06/2023
*/



#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// The taxPayer structure holds data about an individual's tax-related information.
struct taxPayer
{
    string name;       // Taxpayer's name
    long socialSecNum; // Taxpayer's SSN
    float taxRate;     // Tax rate for the taxpayer's income
    float income;      // Taxpayer's total income
    float taxes;       // Calculated taxes owed (taxRate * income)
};

int main()
{
    // Initialize & assign data to a structure variable named citizen1
    taxPayer citizen1 = {"Tim McGuiness", 255871234, 0.35};

    // Initialize & assign data to a structure variable named citizen2
    taxPayer citizen2 = {"John Kane", 278990582, 0.29};

    cout << fixed << showpoint << setprecision(2);

    // Prompt the user to enter this year's income for the citizen1
    cout << "Enter " << citizen1.name << "'s income for this year: ";

    // Read in this income to the appropriate structure member
    cin >> citizen1.income;

    // Calculate the taxes due for citizen1
    citizen1.taxes = citizen1.taxRate * citizen1.income;

    // Output this year's taxes for citizen1 to console
    cout << "Name: " << citizen1.name << endl;
    cout << "Social Security Number: " << citizen1.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen1.taxes << endl << endl;

    // Prompt the user to enter this year's income for citizen2
    cout << "Enter " << citizen2.name << "'s income for this year: ";

    // Read in this income to the appropriate structure member
    cin >> citizen2.income;

    // Calculate taxes due for citizen2
    citizen2.taxes = citizen2.taxRate * citizen2.income;

    // Output this year's taxes for citizen2 to console
    cout << "Name: " << citizen2.name << endl;
    cout << "Social Security Number: " << citizen2.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen2.taxes << endl << endl;

    return 0;
}