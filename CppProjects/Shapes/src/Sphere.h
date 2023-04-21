/*
 * Title:  Shapes
 * Desc:   Sphere class representing a 3D sphere shape, inheriting from Shape class
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include <string>

class Sphere : public Shape {
public:
    // Default Constructor: Creates a Sphere object with a default value for radius
    Sphere();

    // Parameterized Constructor: Creates a Sphere object with the specified radius
    Sphere(double);

    // Destructor: Cleans up resources when a Sphere object is destroyed
    ~Sphere() = default;

    // volume: Calculates and returns the volume of the Sphere object
    double volume() override;

    // surfaceArea: Calculates and returns the surface area of the Sphere object
    double surfaceArea() override;

    // toString: Returns a string representation of the Sphere object, including its radius
    std::string toString();

private:
    double radius; // The radius of the sphere
};

#endif