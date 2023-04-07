/*
*  Title:  Nested Structures
*  Desc:   This program uses structures to hold rectangle data & calculate its area & perimeter. 
*  Author: Bryce Verberne
*  Date:   04/06/2023
*/



#include <iostream>
#include <iomanip>
using namespace std;

// The 'dimensions' structure holds the dimensions of a rectangle
struct dimensions {
    float length;        // Length of the rectangle
    float width;         // Width of the rectangle
};

// The 'results' structure holds calculation results of a rectangle
struct results {
    float area;          // Area of the rectangle (length * width)
    float perimeter;     // Perimeter of the rectangle ((2 * length) + (2 * width))
};

// The 'rectangle' structure holds data about a rectangle.
struct rectangle {
    dimensions sizes;    // A nested structure that holds the rectangle's dimensions
    results attributes;  // A nested structure that holds the rectangle's results from calculations
};

// Prototypes
float rectArea(rectangle rect);
float rectPerimeter(rectangle rect);

int main()
{
    // Define a rectangle structure variable named box.
    rectangle box;

    // Prompt the user to provide a length for the rectangle
    cout << "Enter the length of a rectangle: ";

    // Read & store the rectangle's length
    cin >> box.sizes.length;

    // Prompt the user to provide a width of the rectangle
    cout << "Enter the width of a rectangle: ";

    // Read & store the rectangle's width
    cin >> box.sizes.width;

    cout << endl;

    // Computer & store the area
    box.attributes.area = rectArea(box);

    // Compute & store the perimeter
    box.attributes.perimeter = rectPerimeter(box);

    cout << fixed << showpoint << setprecision(2);

    // Print the area & perimeter to console
    cout << "The area of the rectangle is " << box.attributes.area << "." << endl;
    cout << "The perimeter of the rectangle is " << box.attributes.perimeter << "." << endl;

    return 0;
}


// rectArea Function Description:
//  - Finds the area of a rectangle
//  - One parameter
//     1. rectangle Pointer - Points to rectangle structure
//  - Return: The value for area
float rectArea(rectangle rect) {
    return rect.sizes.length * rect.sizes.width;
}


// rectPerimeter Function Description:
//  - Finds the perimeter of a rectangle
//  - One parameter
//     1. rectangle Pointer - Points to rectangle structure
//  - Return: The value for perimeter
float rectPerimeter(rectangle rect) {
    return (rect.sizes.length * 2) + (rect.sizes.width * 2);
}