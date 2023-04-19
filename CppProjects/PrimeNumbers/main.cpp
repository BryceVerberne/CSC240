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
int* arrayBuilder(int* numberArr, int size, int* newSize);
void primePrinter(int* primeArr, int size, int bound);

int main() {
    int highBound;      // The high boundary value
    int lowBound;       // The low boundary value
    int numSize;        // The size of the number array
    int currentPrime;   // The next prime number found in the number array
    int* numbers;       // Pointer to the dynamically-allocated number array
    int* primeNumbers;  // Pointer to the dynamically-allocated prime number array
    int primeSize = 0;  // The size of the prime number array
    char input = 'y';   // User input to decide whether to continue the program or exit
    int* sizePtr;       // Pointer to the primeSize variable (used as a reference parameter)

    // Assign 'sizePtr' the address of 'primeSize'
    sizePtr = &primeSize;

    // Print an introduction for the user
    cout << "Hello! I'm your personal prime number checker.";

    // Continue the program as long as the user inputs 'y'
    while (input != 'n') {
        cout << endl;

        // Get the low and high boundaries from the user
        cout << "Provide a low and high boundary for where I can look for prime numbers." << endl;
        lowBound = lowBoundary();
        highBound = highBoundary();

        // Ensure that the low boundary is less than or equal to the high boundary
        while (lowBound > highBound) {
            cout << "The lower boundary must be less than or equal to the higher boundary." << endl;
            cout << "Please enter a new set of values." << endl;

            // Get new low and high boundaries from the user
            lowBound = lowBoundary();
            highBound = highBoundary();
        }

        // Assign 'numSize' to the value of highBound + 1 and initialize the 'numbers' array to this value
        numSize = highBound + 1;
        numbers = fillArray(numSize);

        // Find the first prime number in the number array
        currentPrime = nextPrime(numbers, numSize);

        // Loop until no more prime numbers are found in the number array
        while (currentPrime != -1) {
            // Mark the multiples of the current prime number in the number array
            marker(numbers, numSize, currentPrime);

            // Find the next prime number in the number array
            currentPrime = nextPrime(numbers, numSize);
        }

        // Build the prime number array using the 'numbers' array and the newSize reference parameter
        primeNumbers = arrayBuilder(numbers, numSize, sizePtr);

        // Print the prime numbers within the given boundaries
        primePrinter(primeNumbers, primeSize, lowBound);

        // Deallocate memory of dynamic arrays
        delete[] numbers;
        delete[] primeNumbers;
        numbers = nullptr;
        primeNumbers = nullptr;

        // Reset 'primeSize' in preparation for another iteration
        primeSize = 0;

        // Prompt the user to decide whether to continue the program or exit
        cout << "Would you like to go again? [y,n]" << endl;
        cin >> input;
    }

    return 0;
}


/*
 * lowBoundary
 * -----------
 * Desc:   Gets the low boundary value from the user
 * Input:  None
 * Output: int - A value representing the low boundary
 * Notes:  Ensures that the low boundary value is positive
 */
int lowBoundary() {
    int low; // The low boundary value

    // Prompt the user for the low boundary value
    cout << "Low Boundary: ";
    cin >> low;

    // Check to see if the entered number is positive, and if not, ask the user to reenter the value
    while (low < 0) {
        cout << "Please enter a positive value." << endl;
        cout << "Low Boundary: ";
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
 * Output: int - A value representing the high boundary
 * Notes:  Ensures that the high boundary value is positive
 */
int highBoundary() {
    int high; // The high boundary value

    // Prompt the user for the high boundary value
    cout << "High Boundary: ";
    cin >> high;

    // Check to see if the entered number is positive, and if not, ask the user to reenter the value
    while (high < 0) {
        cout << "Please enter a positive value." << endl;
        cout << "High Boundary: ";
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
 * Notes:  The array will be initialized with -1 for indices 0 and 1, and 0 for all other indices
 */
int* fillArray(int size) {
    int* numberArr = new int[size];  // Declare and initialize dynamic array
    int* end = numberArr + size;     // Pointer to the end of the array

    // Iterate through each element in the array
    for (int* ptr = numberArr; ptr != end; ++ptr) {
        // Set the value of the current element to -1 if it is at index 0 or 1
        if (((ptr - numberArr) == 0) || ((ptr - numberArr) == 1)) {
            *ptr = -1;
        }

        // Set the value of the current element to 0 for all other indices
        else {
            *ptr = 0;
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
    int* end = numberArr + size;  // Pointer to the end of the array

    // Iterate through the array starting from index 2
    for (int* ptr = (numberArr + 2); ptr != end; ++ptr) {
        // If the current element has a value of 0, it is a prime number
        if (*ptr == 0) {
            return ptr - numberArr;  // Find the index with pointer arithmetic
        }
    }

    // Return the index of the next prime number or -1 if none is found
    return -1;
}

/*
 * marker
 * ------
 * Desc:   Marks the multiples of the given prime number in the number array
 * Input:  int* numberArr - The array of numbers to mark the multiples in
 *         int size - The size of the number array
 *         int prime - The prime number whose multiples will be marked
 * Output: None
 * Notes:  Marks the multiples of the prime number with -1, and the prime number itself with 1
 */
void marker(int* numberArr, int size, int prime) {
    int* primePtr = numberArr + prime; // Pointer to the prime number in the array
    int* end = numberArr + size;       // Pointer to the end of the array
    int* indexPtr = primePtr + prime;  // Pointer to the first multiple of the prime number in the array

    // Circle the prime number itself with 1
    *primePtr = 1;

    // Iterate through the array, marking the multiples of the prime number with -1
    while (indexPtr < end) {
        // Mark the multiple with -1 and increment 'indexPtr' with our prime value
        *indexPtr = -1;
        indexPtr += prime;
    }
}


/*
 * arrayBuilder
 * ------------
 * Desc:   Builds a new array containing the indices of 'circled' elements (value of +1) in the input array
 * Input:  int* numberArr - The input array of integers
 *         int size - The size of the input array
 *         int* newSize - A pointer to an integer representing the size of the new array (output)
 * Output: int* - A pointer to the new array containing the indices of 'circled' elements
 * Notes:  The function returns the new array via the 'return' statement, and the new array's size via the
 *         reference parameter 'newSize'
 */
int* arrayBuilder(int* numberArr, int size, int* newSize) {
    int* primeArr;  // The new array to store the indices of 'circled' elements
    int* primePtr;  // Helps assign values to 'primeArr' values
    int* end;       // Pointer to the end of the array

    // Calculate the end address of 'numberArr'
    end = numberArr + size;

    // Count the number of 'circled' elements (value of +1) in the input array
    for (int* ptr = numberArr; ptr != end; ++ptr) {
        if (*ptr == 1) {
            ++*newSize;
        }
    }

    // Allocate memory for the new array based on the value of *newSize
    primeArr = new int[*newSize];

    // Assign 'primePtr' the head address of 'primeArr' in order to assign each element a value
    primePtr = primeArr;

    // Populate the new array with the indices of 'circled' elements in the input array
    for (int* ptr = numberArr; ptr != end; ++ptr) {
        if (*ptr == 1) {
            *primePtr = (ptr - numberArr);
            ++primePtr;
        }
    }

    // Return the new array
    return primeArr;
}

/*
 * primePrinter
 * -------------
 * Desc:   Prints the prime numbers from the input array that are greater or equal to the given bound
 * Input:  int* primeArr - The input array containing prime numbers
 *         int size - The size of the input array
 *         int bound - The lower bound for the prime numbers to print
 * Output: None
 * Notes:  The prime numbers are printed separated by commas
 */
void primePrinter(int* primeArr, int size, int bound) {
    int* end = primeArr + size;  // Pointer to the end of the array

    cout << "Prime numbers found: ";

    // Iterate through the input array and print the prime numbers greater or equal to the bound
    for (int* ptr = primeArr; ptr != end; ++ptr) {
        if (*ptr >= bound) {
            cout << *ptr;

            // Add a comma and space if there are more prime numbers to print
            if ((ptr + 1) < end) {
                cout << ", ";
            }
        }
    }

    // Print a newline character to separate the output
    cout << endl << endl;
}