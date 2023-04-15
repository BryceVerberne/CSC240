/*
*  Title:  Arrays Of Objects
*  Desc:   This program reads a file, stores the data in a type Inventory array, & prints the values to console.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



// Extended Description:
// This program declares a class called Inventory that has itemnNumber (which
// contains the id number of a product) and numOfItem (which contains the
// quantity on hand of the corresponding product) as private data members.
// The program will read these values from a file and store them in an
// array of objects (of type Inventory). It will then print these values
// to the screen.

#include <iostream>
#include <fstream>
using namespace std;

const int NUM_OF_PROD = 10; // This constant holds the number of products a store sells

// Inventory class declaration
class Inventory {
public:

    // getId: Stores the item id number in the private data member itemNumber
    void setId(int item);

    // getAmount: Stores the number of items in stock in the private data member numOfItem
    void setAmount(int num);

    // display: Prints the value of itemNumber and numOfItem to the screen for the calling object
    void display() const;

private:
    int	itemNumber;  // Holds an id number of the product
    int	numOfItem;   // Holds the number of items in stock
};

int main() {
    Inventory products[NUM_OF_PROD];  // Defines an array of objects of class Inventory
    ifstream inFile;                  // Input file to read values into array

    // Opens the file "Inventory.dat" for reading
    inFile.open("Inventory.dat");

    // Check if the file has been opened successfully
    if (!inFile.is_open()) {
        cout << "ERROR: Failed to Open File" << endl;
        return 1;
    }

    int pos = 0;    // loop counter
    int id = 0;	    // variable holding the id number
    int total = 0;  // variable holding the total for each id number

    // Read inventory numbers & number of items from a file & store them in the array of objects
    while (inFile >> id && inFile >> total) {
        products[pos].setId(id);
        products[pos].setAmount(total);
        ++pos;
    }

    // Print out the values (itemNumber & numOfItem) for each object in the array products.
    pos = 0;
    while (pos < NUM_OF_PROD) {
        products[pos].display();
        ++pos;
    }

    // Closes the file
    inFile.close();

    return 0;
}


// __________________________________________________________________
//
// Implementation Section
//

// setId
// -----
// Desc:   Stores the item id number in the private data member itemNumber
// Input:  int item - the item id number
// Output: None
void Inventory::setId(int item) {
    itemNumber = item;
}

// setAmount
// ---------
// Desc:   Stores the number of items in stock in the private data member numOfItem
// Input:  int num - the number of items in stock
// Output: None
void Inventory::setAmount(int num) {
    numOfItem = num;
}

// display
// -------
// Desc:   Prints the value of itemNumber and numOfItem to the screen for the calling object
// Input:  None
// Output: Displays the item number and number of items in stock on the console
void Inventory::display() const {
    cout << "Item number " << itemNumber << " has " << numOfItem << " items in stock" << endl;
}