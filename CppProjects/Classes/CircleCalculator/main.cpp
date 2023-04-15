/*
*  Title:  Circle Calculator
*  Desc:   This program uses the Circle class to display the area & circumference of a circle.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



// Extended Description:
// This program declares a class for a circle that will have
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles
// (spheres in the program) initialized at definition or set by a function.

#include <iostream>
using namespace std;

// Circles class declaration
class Circles
{
public: // Constructors & Member Functions

    // Default constructor
    //   Desc: Initializes a circle object with default radius of 1 and center (0, 0)
    Circles();

    // Parameterized constructor
    //   Desc: Initializes a circle object with specified radius and center coordinates
    //   Input: float radius, int x-coordinate, int y-coordinate
    Circles(float r, int x, int y);

    // Destructor
    //   Desc: Cleans up resources when the circle object is destroyed
    ~Circles();

    // setCenter: Sets the center coordinates of the circle object
    //   Input: int x-coordinate, int y-coordinate
    //   Output: None
    void setCenter(int x, int y);

    // findArea: Calculates the area of the circle object
    //   Input: None
    //   Output: double value representing the area of the circle
    double findArea();

    // findCircumference: Calculates the circumference of the circle object
    //   Input: None
    //   Output: double value representing the circumference of the circle
    double findCircumference();

    // printCircleStats: Prints the radius and center coordinates of the circle object
    //   Input: None
    //   Output: Displays the radius and center coordinates on the console
    void printCircleStats();

private: // Data Members
    float radius; // Radius of the circle
    int center_x; // X-coordinate of the circle's center
    int center_y; // Y-coordinate of the circle's center
};

const double PI = 3.14;

#include <iostream>
using namespace std;

// Add Circles class declaration and other necessary code here...

const double PI = 3.14;

int main()
{
    Circles sphere(8, 9, 10); // sphere is defined as an object of the Circles class

    sphere.printCircleStats(); // Print the radius and center coordinates of the sphere

    // Use the 'findArea()' member function to print the sphere's area to console
    cout << "The area of the circle is " << sphere.findArea() << endl;

    // Use the 'findCircumference()' member function to print the sphere's circumference to console
    cout << "The circumference of the circle is " << sphere.findCircumference() << endl;

    return 0;
}


// __________________________________________________________________
//
// Implementation section
//

// Default constructor
//   Desc: Initializes a circle object with default radius of 1 and center (0, 0)
Circles::Circles() {
    radius = 1;
    setCenter(0, 0);
}

// Parameterized constructor
//   Desc:  Initializes a circle object with specified radius and center coordinates
//   Input: float radius, int x-coordinate, int y-coordinate
Circles::Circles(float r, int x, int y) {
    radius = r;
    setCenter(x, y);
}

// Destructor
//   Desc: Cleans up resources when the circle object is destroyed
Circles::~Circles() {}

// -----------
//  setCenter
// -----------
// Desc:   Sets the center coordinates of the circle object
// Input:  int x-coordinate, int y-coordinate
// Output: None
void Circles::setCenter(int x, int y) {
    center_x = x;
    center_y = y;
}

// ----------
//  findArea
// ----------
// Desc:   Calculates the area of the circle object
// Input:  None
// Output: double value representing the area of the circle
double Circles::findArea() {
    return PI * (radius * radius);
}

// -------------------
//  findCircumference
// -------------------
// Desc:   Calculates the circumference of the circle object
// Input:  None
// Output: double value representing the circumference of the circle
double Circles::findCircumference() {
    return 2 * PI * radius;
}

// ------------------
//  printCircleStats
// ------------------
// Desc:   Prints the radius and center coordinates of the circle object
// Input:  None
// Output: Displays the radius and center coordinates on the console
void Circles::printCircleStats() {
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x << ", " << center_y << ")" << endl;
}