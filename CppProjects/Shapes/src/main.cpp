/*
 * Title:  Shapes
 * Des:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

int main() {
    // Create an Array of Shapes

    // Create an instance of sphere, cube and cylinder
    Sphere ball(10.0);
    Cube cuboid(10.0);
    Cylinder tube(2.0, 5.0);

    // TODO: Create variables to hold radius and height

    // TODO: Ask the user for the radius of the sphere and then create an instance of that sphere

    // TODO: Ask the user for the width of the cube and then create an instance of that sphere

    // TODO: Ask the user for the radius and height of the cylinder

    // TODO: Create an instance of the cylinder

    // TODO: Print each object
    std::cout << ball.toString() << std::endl << std::endl;

    std::cout << cuboid.toString() << std::endl << std::endl;

    std::cout << tube.toString() << std::endl;

    // TODO: Add each object to your list


    // TODO: Use a for loop
    //       Print the  name of the class
    //       Print the Surface Area
    //       Print the volume

    return 0;
}