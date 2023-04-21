/*
 * Title:  Shapes
 * Desc:   Cylinder class representing a 3D cylinder shape, inheriting from Shape class
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include <string>

class Cylinder : public Shape {
public:
    // Default Constructor: Creates a Cylinder object with default values for radius and height
    Cylinder();

    // Parameterized Constructor: Creates a Cylinder object with the specified radius and height
    Cylinder(double, double);

    // Destructor: Cleans up resources when a Cylinder object is destroyed
    ~Cylinder() = default;

    // volume: Calculates and returns the volume of the Cylinder object
    double volume() override;

    // surfaceArea: Calculates and returns the surface area of the Cylinder object
    double surfaceArea() override;

    // toString: Returns a string representation of the Cylinder object's class name (as returned by typeid)
    std::string toString() override;

private:
    double radius; // The radius of the cylinder
    double height; // The height of the cylinder
};

#endif