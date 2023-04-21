/*
 * Title:  Shapes
 * Desc:   Abstract Shape class representing a base class for 3D geometric shapes
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    // Destructor: Virtual destructor to ensure proper cleanup when deleting derived class objects
    virtual ~Shape() = default;

    // volume: Pure virtual function for calculating and returning the volume of a derived Shape object
    virtual double volume() = 0;

    // surfaceArea: Pure virtual function for calculating and returning the surface area of a derived Shape object
    virtual double surfaceArea() = 0;

    // toString: Pure virtual function that returns the object's class name (as returned by typeid).
    virtual std::string toString() = 0;

};

#endif