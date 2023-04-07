/*
*  Title:  Structure Basics
*  Desc:   This program uses a structure to hold data about a rectangle.
*  Author: Bryce Verberne
*  Date:   04/06/2023
*/



#include <iostream>
#include <iomanip>
using namespace std;

// The 'rectangle' structure holds data about a rectangle.
struct rectangle {
    float length;    // Length of the rectangle
    float width;     // Width of the rectangle
    float area;      // Area of the rectangle (length * width)
    float perimeter; // Perimeter of the rectangle ((2 * length) + (2 * width))
};

int main()
{
    // Define a rectangle variable named box
    rectangle box;

    // Prompt the user to input the rectangle's length
    cout << "Enter the length of a rectangle: ";

    // Read in the length member of box
    cin >> box.length;

    // Prompt the user to input the rectangle's width
    cout << "Enter the width of a rectangle: ";

    // Read in the width member of box
    cin >> box.width;

    cout << endl;

    // Compute the area member of box
    box.area = box.length * box.width;

    // Compute the perimeter member of box
    box.perimeter = (2 * box.length) + (2 * box.width);

    cout << fixed << showpoint << setprecision(2);

    // Output the area
    cout << "Rectangle Area: " << box.area << endl;

    // Output the perimeter
    cout << "Rectangle Perimeter: " << box.perimeter << endl;

    // Print to console if or if not the rectangle is a square.
    if (box.width == box.length) {
        cout << "The rectangle is a square." << endl;
    }
    else {
        cout << "The rectangle is not a square." << endl;
    }

    return 0;
}