/*
 * Title:  Shapes
 * Desc:   A program to demonstrate polymorphism, abstraction, and inheritance
 *         with Shape, Sphere, Cube, and Cylinder classes.
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */

#include <iostream>
#include "Shape.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

// Function Prototypes
double getParameter();

int main() {
    Shape* shapes[3];  // Create an array of pointers to Shape objects

    // Variables to store user input for the dimensions of each shape
    double cylinderRadius;  // Radius of the cylinder
    double sphereRadius;    // Radius of the sphere
    double width;           // Width of the cube
    double height;          // Height of the cylinder

    // Get the user input for the radius of the sphere and create a Sphere instance with the input
    sphereRadius = getParameter();
    Sphere ball(sphereRadius);

    // Get the user input for the width of the cube and create a Cube instance with the input
    width = getParameter();
    Cube cuboid(width);

    // Get the user input for the radius and height of the cylinder and create a Cylinder instance with the input
    cylinderRadius = getParameter();
    height = getParameter();
    Cylinder tube(cylinderRadius, height);

    // Print each object with its properties
    printf("Sphere{radius=%.1f}\n", sphereRadius);
    printf("Cube{width=%.1f}\n", width);
    printf("Cylinder{radius=%.1f, height=%.1f}\n", cylinderRadius, height);

    // Add objects to 'shapes' array
    shapes[0] = &ball;
    shapes[1] = &cuboid;
    shapes[2] = &tube;

    // Iterate through the shapes array, print the object name, surface area, and volume
    for (int i = 0; i < 3; ++i) {
        std::cout << std::endl << shapes[i]->toString() << std::endl;
    }

    return 0;
}


/*
 * getParameter
 * ------------
 * Desc:   Prompts the user for a positive double value as input and returns it.
 * Input:  None.
 * Output: The input positive double value.
 * Notes:  Continuously asks for input until a valid positive double value is entered.
 */
double getParameter() {
    double r;

    while(!(std::cin >> r) || (r < 0)) {
        // Tutorial: https://www.youtube.com/watch?v=m2P5A4nR51g&ab_channel=JesusHilarioHernandez

        // Clear the error state of the input stream
        std::cin.clear();

        // Discard previous input
        std::cin.ignore(123, '\n');
    }

    return r;
}