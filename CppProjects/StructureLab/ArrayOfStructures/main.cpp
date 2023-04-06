/*
*  Title:  Array of Structures
*  Desc:   This program demonstrates how to use an array of structures.
*  Author: Bryce Verberne
*  Date:   04/06/2023
*/



#include <iostream>
#include <iomanip>
using namespace std;

// The taxPayer structure holds data about an individual's tax-related information.
struct taxPayer
{
    float taxRate;     // Tax rate for the taxpayer's income
    float income;      // Taxpayer's total income
    float taxes;       // Calculated taxes owed (taxRate * income)
};

int main()
{
    // Define an array named citizen, which holds 5 taxPayers structures.
    taxPayer citizen[5];

    cout << fixed << showpoint << setprecision(2);

    cout << "Enter the annual income and tax rate for 5 tax payers." << endl << endl;

    // Prompt the user to input tax info for all 5 citizens
    for (int count = 0; count < 5; count++) {
        cout << "Enter this year's income for tax payer " << (count + 1);
        cout << ": ";

        // Read & store the income of the citizen
        cin >> citizen[count].income;

        cout << "Enter the tax rate for tax payer " << (count + 1);
        cout << ": ";

        // Read & store the tax rate of the citizen
        cin >> citizen[count].taxRate;

        // Compute the taxes for the citizen & store the result
        citizen[count].taxes = citizen[count].taxRate * citizen[count].income;

        cout << endl;
    }

    cout << endl;
    cout << "Taxes due for this year: " << endl;

    // Output tax info for all 5 citizens
    for(int index = 0; index < 5; ++index) {
        cout << "Tax Payer " << (index + 1) << ": " << "$"
             << citizen[index].taxes << endl;
    }

    return 0;
}