/*
*  Title:  Dynamic Arrays
*  Desc:   This program demonstrates the use of dynamic arrays
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float *monthSales = nullptr;  // Pointer used to point to an array
                                  // holding monthly sales

    float total = 0;	// Total of all sales
    float average;		// Average of monthly sales
    int numOfSales;		// Number of sales to be processed
    int count;			// Loop counter

    cout << fixed << showpoint << setprecision(2);

    cout << "How many monthly sales will be processed? ";
    cin >> numOfSales;

    // Allocate memory for the array pointed to by monthSales.
    monthSales = new float[numOfSales];

    // Determine if memory has been allocated
    if (monthSales == nullptr) {
        cout << "Error allocating memory!\n";
        return 1;
    }

    cout << "Enter the sales below.\n";

    for (count = 0; count < numOfSales; count++) {
        // Show the number of the month
        cout << "Sales for Month number	" << (count + 1) << ": ";

        // Bring sales into an element of the array
        cin >> *(monthSales + count);
    }

    // Calculate the total
    for (count = 0; count < numOfSales; count++)
    {
        total = total + *(monthSales + count);
    }

    // Calculate the average
    average = total / numOfSales;

    cout << "Average Monthly sale is $" << average << "." << endl;

    // Deallocate memory assigned to the array.
    delete [] monthSales;

    return 0;
}