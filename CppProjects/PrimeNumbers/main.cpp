/*
*  Title:  Prime Numbers
*  Desc:   This program displays the prime numbers within a given range of numbers.
*  Author: Bryce Verberne
*  Date:   04/17/2023
*/



#include <iostream>
using namespace std;

// Function prototypes
int lowBoundary();
int highBoundary();

int main() {
    int highBound;  // The high boundary value
    int lowBound;   // The low boundary value

    // Print an introduction for the user
    cout << "Specify a range of positive integers with a low & high boundary." << endl;

    // Get the low and high boundaries
    lowBound = lowBoundary();
    highBound = highBoundary();

    // Ensure that the low boundary is less than or equal to the high boundary
    while (lowBound > highBound) {
        cout << "Please enter a low boundary value that is less than or equal to the high boundary value." << endl;
        lowBound = lowBoundary();
        highBound = highBoundary();
    }

    // Print the validated low and high boundaries
    cout << "This is your low boundary: " << lowBound << endl;
    cout << "This is your high boundary: " << highBound << endl;

    return 0;
}

/*
 * lowBoundary
 * -----------
 * Desc:   Gets the low boundary value from the user
 * Input:  None
 * Output: int value representing the low boundary
 */
int lowBoundary() {
    int low; // The low boundary value

    // Prompt the user for the low boundary value
    cout << "Low Boundary: ";
    cin >> low;

    // Check to see if the entered number is positive, & if not, ask the user to reenter the value
    while (low <= 0) {
        cout << "Please enter a positive value: ";
        cin >> low;
    }

    // Return the low boundary value
    return low;
}

/*
 * highBoundary
 * ------------
 * Desc:   Gets the high boundary value from the user
 * Input:  None
 * Output: int value representing the high boundary
 */
int highBoundary() {
    int high; // The high boundary value

    // Prompt the user for the high boundary value
    cout << "High Boundary: ";
    cin >> high;

    // Check to see if the entered number is positive, & if not, ask the user to reenter the value
    while (high <= 0) {
        cout << "Please enter a positive value: ";
        cin >> high;
    }

    // Return the high boundary value
    return high;
}
