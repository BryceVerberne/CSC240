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
    Shape* shapes[3];         // Create an Array of Shapes
    double cylinderRadius;
    double sphereRadius;
    double width;
    double height;

    // TODO: Ask the user for the radius of the sphere and then create an instance of that sphere
    sphereRadius = getParameter();
    Sphere ball(sphereRadius);

    // TODO: Ask the user for the width of the cube and then create an instance of that cube
    width = getParameter();
    Cube cuboid(width);

    // TODO: Ask the user for the radius and height of the cylinder and then create an instance of the cylinder
    cylinderRadius = getParameter();
    height = getParameter();

    Cylinder tube(cylinderRadius, height);

    // TODO: Print each object
    printf("Sphere{radius=%.1f}\n", sphereRadius);
    printf("Cube{width=%.1f}\n", width);
    printf("Cylinder{radius=%.1f, height=%.1f}\n", cylinderRadius, height);

    // TODO: Add each object to your list
    shapes[0] = &ball;
    shapes[1] = &cuboid;
    shapes[2] = &tube;

    // TODO: Use a for loop
    //       Print the  name of the class
    //       Print the Surface Area
    //       Print the volume
    for (int i = 0; i < 3; ++i) {
        std::cout << std::endl << shapes[i]->toString() << std::endl;
        printf("Surface Area: %9.3f\n", shapes[i]->surfaceArea());
        printf("Volume: %15.3f\n", shapes[i]->volume());
    }

    return 0;
}

// TODO: Write a method called getParameter that returns a positive integer
//       It must continually ask the user to enter the value until a valid number is entered
//       It must handle invalid values (Exception Handling)
double getParameter() {
    double r;

    std::cin >> r;
    while(r < 0) {
        std::cin >> r;
    }

    return r;
}