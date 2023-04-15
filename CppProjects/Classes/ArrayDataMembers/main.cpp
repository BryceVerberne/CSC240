/*
*  Title:  Array Data Members
*  Desc:   This program stores float values in an array data member & prints these values to console.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



// Extended Description:
// This program reads floating point data from a data file and places those
// values into the private data member called values (a floating point array)
// of the FloatList class. Those values are then printed to the screen.
// The input is done by a member function called GetList. The output
// is done by a member function called PrintList. The amount of data read in
// is stored in the private data member called length. The member function
// GetList is called first so that length can be initialized to zero.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_LENGTH = 50; // MAX_LENGTH contains the maximum length of the list

// FloatList class declaration
class FloatList {
public:

    // Default constructor: Initializes an empty FloatList object with length set to 0
    FloatList();

    // Destructor: Cleans up resources when the FloatList object is destroyed
    ~FloatList();

    // getList: Reads floating point numbers from a file & stores them in the FloatList object
    void getList(ifstream& inFile);

    // printList: Prints the floating point numbers stored in the FloatList object to the console
    void printList() const;

    // findAverage: Calculates the average of the floating point numbers stored in the FloatList object
    float findAverage() const;

private:
    int length;                // Holds the number of elements in the array
    float values[MAX_LENGTH]{};  // The array of floating point numbers
};

int main() {
    ifstream tempData;  // Defines a data file for reading temperature values

    // Creates an object called list of the FloatList class
    FloatList list;

    cout << fixed << showpoint;
    cout << setprecision(2);

    // Opens the file "temperatures.txt" for reading
    tempData.open("temperatures.txt");

    // Check if the file has been opened successfully
    if (!tempData.is_open()) {
        cout << "ERROR: Failed to Open File" << endl;
        return 1;
    }

    // Read numbers from the file & store them in 'list'
    list.getList(tempData);

    // Print the numbers stored in 'list' to console
    list.printList();

    // Calculate & print the average to console
    cout << "The average temperature is " << list.findAverage() << endl;

    // Closes the file
    tempData.close();

    return 0;
}



// __________________________________________________________________
//
// Implementation Section
//

// Default Constructor
// -------------------
// Desc: Initializes an empty FloatList object with length set to 0
FloatList::FloatList() {
    length = 0;
}

// Destructor
// ----------
// Desc: Cleans up resources when the FloatList object is destroyed
FloatList::~FloatList() = default;

// getList
// -------
// Desc:   Reads floating point numbers from a file & stores them in the FloatList object
// Input:  ifstream reference representing the file to read from
// Output: None
void FloatList::getList(ifstream& file) {
    while (file >> values[length]) {
        ++length;
    }
}

// printList
// ---------
// Desc:   Prints the floating point numbers stored in the FloatList object to the console
// Input:  None
// Output: Displays the floating point numbers on the console
void FloatList::printList() const {
    int count = 0;

    while (count < length) {
        cout << values[count] << endl;
        ++count;
    }
}

// findAverage
// -----------
// Desc:   Calculates the average of the floating point numbers stored in the FloatList object
// Input:  None
// Output: float value representing the average of the floating point numbers
float FloatList::findAverage() const {
    int count = 0;
    float total = 0;

    while (count < length) {
        total += values[count];
        ++count;
    }

    return (total / length);
}