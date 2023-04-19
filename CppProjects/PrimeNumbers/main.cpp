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
int* fillArray(int size);
int nextPrime(int* numberArr, int size);
void marker(int* numberArr, int size, int prime);

int main() {
    int highBound;    // The high boundary value
    int lowBound;     // The low boundary value
    int size;         // The size of the number array
    int primeNumber;  // The next prime number found in the number array

    // Print an introduction for the user
    cout << "Specify a range of positive integers with a low & high boundary." << endl;

    // Get the low & high boundaries from the user
    lowBound = lowBoundary();
    highBound = highBoundary();

    // Ensure that the low boundary is less than or equal to the high boundary
    while (lowBound > highBound) {
        cout << "The lower boundary must be less than or equal to the higher boundary." << endl;
        cout << "Please enter a new set of values." << endl;

        // Get new low & high boundaries from the user
        lowBound = lowBoundary();
        highBound = highBoundary();
    }

    // Calculate the size of the number array based on the high boundary
    size = highBound + 1;

    int *numbers = fillArray(size);  // Create & initialize the number array

    // Find the first prime number in the number array
    primeNumber = nextPrime(numbers, size);

    // Loop until no more prime numbers are found in the number array
    while (primeNumber != -1) {
        // Mark the multiples of the current prime number in the number array
        marker(numbers, size, primeNumber);

        // Find the next prime number in the number array
        primeNumber = nextPrime(numbers, size);

        // Print the current state of the number array
        for (int i = 0; i < size; ++i) {
            cout << "Element " << i << ": " << numbers[i] << endl;
        }

        cout << endl;
    }

    return 0;
}



/*
 * lowBoundary
 * -----------
 * Desc:   Gets the low boundary value from the user
 * Input:  None
 * Output: int value representing the low boundary
 * Notes:  Ensures that the low boundary value is positive
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
 * Notes:  Ensures that the high boundary value is positive
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

/*
 * fillArray
 * ---------
 * Desc:   Initializes an array of integers based on the given size
 * Input:  int size - The size of the array to create
 * Output: int* - A pointer to the newly created array
 * Notes:  The array will be initialized with -1 for indices 0 & 1, & 0 for all other indices
 */
int* fillArray(int size) {
    int* numberArr = new int[size];

    // Iterate through each element in the array
    for (int i = 0; i < size; ++i) {
        // Set the value of the current element to -1 if it is at index 0 or 1
        if ((i == 0) || (i == 1)) {
            numberArr[i] = -1;
        }
        // Set the value of the current element to 0 for all other indices
        else {
            numberArr[i] = 0;
        }
    }

    // Return the pointer to the newly created array
    return numberArr;
}

/*
 * nextPrime
 * ---------
 * Desc:   Finds the next prime number in the given number array
 * Input:  int* numberArr - The array of numbers to search for the next prime
 *         int size - The size of the number array
 * Output: int - The index of the next prime number in the array, or -1 if no prime is found
 */
int nextPrime(int* numberArr, int size) {
    int index = -1;

    // Iterate through the array starting from index 2
    for (int i = 2; i < size; ++i) {
        // If the current element has a value of 0, it is a prime number
        if (numberArr[i] == 0) {
            index = i;
            break;
        }
    }

    // Return the index of the next prime number or -1 if none is found
    return index;
}

/*
 * marker
 * ------
 * Desc:   Marks the multiples of the given prime number in the number array
 * Input:  int* numberArr - The array of numbers to mark the multiples in
 *         int size - The size of the number array
 *         int prime - The prime number whose multiples will be marked
 * Output: None
 * Notes:  Marks the multiples of the prime number with -1, & the prime number itself with 1
 */
void marker(int* numberArr, int size, int prime) {
    numberArr[prime] = 1;  // Mark the prime number itself with a value of 1
    int index = 2 * prime; // Initialize the index to the first multiple of the prime number

    // Iterate through the array, marking the multiples of the prime number with -1
    while(index < size) {
        numberArr[index] = -1;
        index += prime;
    }
}
