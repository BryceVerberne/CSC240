/*
 * Title:  Shapes
 * Des:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include "Shape.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

// Prototypes
double getParameter();

int main() {
    Shape* shapes[6];         // Create an Array of Shapes
    Sphere ball1(10.0);        // Create an instance of Sphere
    Cube cuboid1(10.0);        // Create an instance of Cube
    Cylinder tube1(2.0, 5.0);  // Create an instance of Cylinder
    double radius;
    double width;
    double height;

    // TODO: Ask the user for the radius of the sphere and then create an instance of that sphere
    std::cout << "Enter the sphere's radius: ";
    radius = getParameter();
    std::cout << std::endl;

    Sphere ball2(radius);

    // TODO: Ask the user for the width of the cube and then create an instance of that cube
    std::cout << "Enter the cube's width: ";
    width = getParameter();
    std::cout << std::endl;

    Cube cuboid2(width);

    // TODO: Ask the user for the radius and height of the cylinder and then create an instance of the cylinder
    std::cout << "Enter the cylinder's radius: ";
    radius = getParameter();

    std::cout << "Enter the cylinder's height: ";
    height = getParameter();
    std::cout << std::endl;

    Cylinder tube2(radius, height);

    // TODO: Print each object
    std::cout << ball1.toString() << std::endl << std::endl;
    std::cout << cuboid1.toString() << std::endl << std::endl;
    std::cout << tube1.toString() << std::endl;

    // TODO: Add each object to your list


    // TODO: Use a for loop
    //       Print the  name of the class
    //       Print the Surface Area
    //       Print the volume

    return 0;
}

// TODO: Write a method called getParameter that returns a positive integer
//       It must continually ask the user to enter the value until a valid number is entered
//       It must handle invalid values (Exception Handling)
double getParameter() {
    double r;

    std::cin >> r;
    while(r < 0) {
        std::cout << "Please enter a positive value: ";
        std::cin >> r;
    }

    return r;
}