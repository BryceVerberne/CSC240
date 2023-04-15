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
public:  // Constructors & Member Functions

    // Default constructor
    //   Desc: Initializes an empty FloatList object with length set to 0
    FloatList();

    // Destructor
    //   Desc: Cleans up resources when the FloatList object is destroyed
    ~FloatList();

    // getList: Reads floating point numbers from a file and stores them in the FloatList object
    //   Input:  ifstream reference representing the file to read from
    //   Output: None
    void getList(ifstream& inFile);

    // printList: Prints the floating point numbers stored in the FloatList object to the console
    //   Input:  None
    //   Output: Displays the floating point numbers on the console
    void printList() const;

private:  // Data Members
    int length;                // Holds the number of elements in the array
    float values[MAX_LENGTH];  // The array of floating point numbers
};

int main()
{
    ifstream tempData;  // Defines a data file for reading temperature values

    // Creates an object called list of the FloatList class
    FloatList list;

    cout << fixed << showpoint;
    cout << setprecision(2);

    // Opens the file "temperatures.txt" for reading
    tempData.open("temperatures.txt");

    // Check if the file has been opened successfully
    if (tempData.is_open()) {
        cout << "File Opened Successfully" << endl;
    }
    else {
        cout << "Failed to Open File" << endl;
    }

    // Closes the file
    tempData.close();

    return 0;
}


// __________________________________________________________________
//
// Implementation section
//

FloatList::FloatList() {
	// Fill in the code to complete this constructor that
	// sets the private data member length to 0
}

// Fill in the entire code for the getList function
// The getList function reads the data values from a data file
// into the values array of the class FloatList

// Fill in the entire code for the printList function
// The printList function prints to the screen the data in
// the values array of the class FloatList