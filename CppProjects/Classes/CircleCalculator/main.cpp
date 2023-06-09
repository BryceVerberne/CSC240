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

    // Default Constructor:Initializes a circle object with default radius of 1 and center (0, 0)
    Circles();

    // Parameterized Constructor: Initializes a circle object with specified radius and default center (0, 0)
    Circles(float r);

    // Parameterized Constructor: Initializes a circle object with default radius of 1 and specified center coordinates
    Circles(int x, int y);

    // Parameterized Constructor: Initializes a circle object with specified radius and center coordinates
    Circles(float r, int x, int y);

    // Destructor: Cleans up resources when the circle object is destroyed
    ~Circles();

    // setCenter: Sets the center coordinates of the circle object
    void setCenter(int x, int y);

    // findArea: Calculates the area of the circle object
    double findArea() const;

    // findCircumference: Calculates the circumference of the circle object
    double findCircumference() const;

    // printCircleStats: Prints the radius, center coordinates, area, and circumference of the circle object
    void printCircleStats() const;

private: // Data Members
    float radius; // Radius of the circle
    int center_x; // X-coordinate of the circle's center
    int center_y; // Y-coordinate of the circle's center
};

const double PI = 3.14;

int main()
{
    Circles sphere1(2);      // sphere1 is defined as an object of the Circles class
    Circles sphere2;         // sphere2 is defined as an object of the Circles class
    Circles sphere3(15, 16); // sphere3 is defined as an object of the Circles class


    sphere1.printCircleStats(); // Print the radius, center, area, & circumference of sphere1
    cout << endl;
    sphere2.printCircleStats(); // Print the radius, center, area, & circumference of sphere2
    cout << endl;
    sphere3.printCircleStats(); // Print the radius, center, area, & circumference of sphere3
    cout << endl;

    return 0;
}


// __________________________________________________________________
//
// Implementation Section
//

// Default Constructor
// -------------------
// Desc: Initializes a circle object with default radius of 1 and center (0, 0)
Circles::Circles() {
    radius = 1;
    setCenter(0, 0);
}

// Parameterized Constructor
// -------------------------
// Desc:  Initializes a circle object with specified radius and default center (0, 0)
// Input: float radius
Circles::Circles(float r) {
    radius = r;
    setCenter(0, 0);
}

// Parameterized Constructor
// -------------------------
// Desc:  Initializes a circle object with default radius of 1 and specified center coordinates
// Input: int x-coordinate, int y-coordinate
Circles::Circles(int x, int y) {
    radius = 1;
    setCenter(x, y);
}

// Parameterized Constructor
// -------------------------
// Desc:  Initializes a circle object with specified radius and center coordinates
// Input: float radius, int x-coordinate, int y-coordinate
Circles::Circles(float r, int x, int y) {
    radius = r;
    setCenter(x, y);
}

// Destructor
// ----------
// Desc: Cleans up resources when the circle object is destroyed
Circles::~Circles() {
    cout << "This concludes the Circles class" << endl;
}

// setCenter
// ---------
// Desc:   Sets the center coordinates of the circle object
// Input:  int x-coordinate, int y-coordinate
// Output: None
void Circles::setCenter(int x, int y) {
    center_x = x;
    center_y = y;
}

// findArea
// --------
// Desc:   Calculates the area of the circle object
// Input:  None
// Output: double value representing the area of the circle
double Circles::findArea() const {
    return PI * (radius * radius);
}

// findCircumference
// -----------------
// Desc:   Calculates the circumference of the circle object
// Input:  None
// Output: double value representing the circumference of the circle
double Circles::findCircumference() const {
    return 2 * PI * radius;
}

// printCircleStats
// ----------------
// Desc:   Prints the radius, center coordinates, area, and circumference of the circle object
// Input:  None
// Output: Displays the radius and center coordinates on the console
void Circles::printCircleStats() const {
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x << ", " << center_y << ")" << endl;

    cout << "The area of the circle is " << findArea() << endl;
    cout << "The circumference of the circle is " << findCircumference() << endl;
}