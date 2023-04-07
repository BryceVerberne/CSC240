/*
*  Title:  Dynamic Array Parameters
*  Desc:   This program demonstrates the use of dynamic arrays as parameters
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



#include <iostream>
using namespace std;

// Function prototypes
int getSize();
int fillArray(int* scoreArray, int size);
void sortArray(int* scoreArray, int size);
void indexOf(int* scoreArray, int size);

int main() {

    int *scores = nullptr;  // Points to the beginning of the integer array
    int total;              // Total of all scores
    int numScores;          // Total number of scores to be inputted (array length)
    int average;            // Average of all scores

    // Get the size of the array
    numScores = getSize();

    // Allocate memory for an array of scores
    scores = new int[numScores];

    // Check for non-valid address
    if (scores == nullptr) {
        cout << "Error in allocating memory." << endl;
        cout << "Program terminating.";

        return -1;
    }

    // Populate array & get total
    total = fillArray(scores, numScores);

    // Calculate & print average
    average = total / numScores;
    cout << "The average of the scores is " << average << "." << endl;

    // Sort & print the array in ascending order
    sortArray(scores, numScores);

    // Search the array for a user-defined value
    indexOf(scores, numScores);

    // Deallocate array memory
    delete [] scores;

    return 0;
}


// arraySize Function Description:
//  - Prompts the user for input & stores the score array's size.
//  - Zero parameters.
//  - Return: The number of scores that the user wants to record (array size).
int getSize() {
    int size;  // Stores the user-defined size of the array

    // Allow user to input the number of scores to be inserted
    cout << "Input the number of scores: ";
    cin >> size;

    // Check for a legal value for 'numScores'
    while (size <= 0) {
        cout << "There must be at least one score. Please reenter." << endl;
        cout << "Input the number of scores: ";
        cin >> size;
    }

    return size;
}


// fillArray Function Description:
//  - Prompts the user for input, stores it in an array, & calculates the total of all input
//  - Two parameters:
//     1. Integer Pointer (points to array of integers)
//     2. Integer (holds the size of the array)
//  - Return: The total of all scores inputted.
int fillArray(int* scoreArray, int size) {
    int total = 0;  // Total for all scores inputted

    // Populate array
    for (int i = 0; i < size; ++i) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> *(scoreArray + i);

        total += *(scoreArray + i);
    }

    return total;
}


// sort Function Description:
//  - Sorts numbers in an array in ascending order.
//  - Two parameters:
//     1. Integer Pointer (points to array of integers)
//     2. Integer (holds the size of the array)
//  - Return: No return (void)
void sortArray(int* scoreArray, int size) {
    // Output start of sorted array list
    cout << "\nHere are the scores in ascending order:" << endl;

    // Use the selection sort algorithm to sort the array in ascending order
    for (int i = 0; i < (size - 1); ++i) {
        int minIndex = i;

        for (int j = (i + 1); j < size; ++j) {
            if (*(scoreArray + j) < *(scoreArray + minIndex)) {
                minIndex = j;
            }
        }

        // Swap *(scoreArray+i) & *(scoreArray+minIndex)
        int tempVal = *(scoreArray + i);
        *(scoreArray + i) = *(scoreArray + minIndex);
        *(scoreArray + minIndex) = tempVal;
    }

    // Print the array to console
    for (int i = 0; i < size; ++i) {
        cout << *(scoreArray + i) << endl;
    }
}


// indexOf Function Description:
//  - Searches an array for a user-defined value & prints if or if not it is present.
//  - Two parameters:
//     1. Integer Pointer (points to array of integers)
//     2. Integer (holds the size of the array)
//  - Return: No return (void)
void indexOf(int* scoreArray, int size) {
    int idNum;               // Stores the id the user wants to query
    bool isPresent = false;  // Determines if the id is present in the array

    // Prompt the user for input
    cout << "\nInput an id number to be searched: ";
    cin >> idNum;

    // Check if array contains input
    for (int i = 0; i < size; ++i) {
        if (*(scoreArray + i) == idNum) {
            isPresent = true;
        }
    }

    // Print if input is or isn't present
    if (isPresent) {
        cout << idNum << " is in the array.";
    }
    else {
        cout << idNum << " is not in the array." << endl;
    }
}