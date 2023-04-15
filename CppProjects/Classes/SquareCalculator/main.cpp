/*
*  Title:  Square Calculator
*  Desc:   This program uses the Square class to find the perimeter of a square.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



#include <iostream>
using namespace std;

// Square class declaration
class Square {
public: // Constructors & Member Functions

    // Default constructor
    //   Desc: Initializes a square object with default side length of 1
    Square();

    // Parameterized constructor
    //   Desc: Initializes a square object with specified side length
    //   Input: float value representing the length of a side
    Square(float length);

    // Destructor
    //   Desc: Cleans up resources when the square object is destroyed
    ~Square();

    // setSide: Sets the length of a side for the square object
    //   Input: float value representing the length of a side
    //   Output: None
    void setSide(float length);

    // findArea: Calculates the area of the square object
    //   Input: None
    //   Output: float value representing the area of the square
    float findArea();

    // findPerimeter: Calculates the perimeter of the square object
    //   Input: None
    //   Output: float value representing the perimeter of the square
    float findPerimeter();

private: // Data Members
    float side; // float value representing the length of a side of the square object
};

int main() {
    Square box;	    // box is defined as an object of the Square class
    Square box1(9); // box1 is defined as an object of the Square class
    float size;	    // size contains the length of a side of the square

    // Prompt the user to enter the length of the side of the square & store it in size
    cout << "Please input the length of the side of the square" << endl;
    cin >> size;

    // Pass the value of size to our object using 'setSide()'
    box.setSide(size);

    // Use the 'findArea()' member function to print our square's area to console
    cout << "The area of the square is " << box.findArea() << endl;

    // Use the 'findPerimeter()' member function to print our square's perimeter to console
    cout << "The perimeter of the square is " << box.findPerimeter() << endl << endl;

    // Output the area & perimeter of box1
    cout << "The area of box1 is " << box1.findArea() << endl;
    cout << "The perimeter of " << box1.findPerimeter() << endl;

    return 0;
}


// _______________________________________________________
//
// Implementation section
//

// Default constructor
// Desc: Initializes a square object with default side length of 1
Square::Square() {
    side = 1;
}

// Parameterized constructor
// Desc:  Initializes a square object with specified side length
// Input: float value representing the length of a side
Square::Square(float length) {
    side = length;
}

// Destructor
// Desc: Cleans up resources when the square object is destroyed
Square::~Square() {}

// ---------
//  setSide
// ---------
// Desc:   Sets the length of a side for the square object
// Input:  float value representing the length of a side
// Output: None
void Square::setSide(float length) {
    side = length;
}

// ----------
//  findArea
// ----------
// Desc:   Calculates the area of the square object
// Input:  None
// Output: float value representing the area of the square
float Square::findArea() {
    return side * side;
}

// ---------------
//  findPerimeter
// ---------------
// Desc:   Calculates the perimeter of the square object
// Input:  None
// Output: float value representing the perimeter of the square
float Square::findPerimeter() {
    return 4 * side;
}