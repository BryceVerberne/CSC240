/*
 * Title:  Shapes
 * Desc:   Cube class representing a 3D cube shape, inheriting from Shape class
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */

#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include <string>

class Cube : public Shape {
public:
    // Default Constructor: Creates a Cube object with a default value for width
    Cube();

    // Parameterized Constructor: Creates a Cube object with the specified width
    Cube(double);

    // Destructor: Cleans up resources when a Cube object is destroyed
    ~Cube() = default;

    // volume: Calculates and returns the volume of the Cube object
    double volume() override;

    // surfaceArea: Calculates and returns the surface area of the Cube object
    double surfaceArea() override;

    // toString: Returns a string representation of the Cube object, including its width
    std::string toString();

private:
    double width; // The width (edge length) of the cube
};

#endif