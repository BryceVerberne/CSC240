/*
*  Title:  Dynamic Array Parameters
*  Desc:   This program demonstrates the use of dynamic arrays as parameters
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



#include <iostream>
using namespace std;

// Function prototypes
int sort(int* userScores, int size);

int main() {

    int *scores = nullptr;  // Points to the beginning of the integer array
    int total = 0;          // Total of all scores
    int numScores;          // Total number of scores to be inputted (array length)
    int average;            // Average of all scores

    // Allow user to input the number of scores to be inserted
    cout << "Input the number of scores: ";
    cin >> numScores;

    // Check for a legal value for 'numScores'
    while (numScores <= 0) {
        cout << "There must be at least one score. Please reenter." << endl;
        cout << "Input the number of scores: ";
        cin >> numScores;
    }

    scores = new int[numScores];  // Allocate memory for an array of scores

    // Check for non-valid address
    if (scores == nullptr) {
        cout << "Error in allocating memory." << endl;
        cout << "Program terminating.";

        return -1;
    }

    // Populate array & add to total
    for (int i = 0; i < numScores; ++i) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> *(scores + i);

        total += *(scores + i);
    }

    // Calculate & print average
    average = total / numScores;
    cout << "The average of the scores is " << average << "." << endl;

    cout << "Here are the scores in ascending order:" << endl;
    sort(scores, numScores);

    // Deallocate array memory
    delete [] scores;

    return 0;
}


// Function Description:
//  - Sorts numbers in an array.
//  - Two parameters:
//     1. Integer pointer (points to array of scores)
//     2. Integer (holds the number of scores)
//  - Return: An array that is sorted in ascending order
int sort(int* userScores, int size) {

    return 0;
}