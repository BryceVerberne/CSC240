/**
 * @file Shape.h
 * @title Shapes
 * @brief Abstract Shape class representing a base class for 3D geometric shapes.
 * @author Bryce Verberne
 * @date 04/19/2023
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    /**
     * @brief Virtual destructor to ensure proper cleanup when deleting derived class objects.
     */
    virtual ~Shape() = default;

    /**
     * @brief Pure virtual function for calculating and returning the volume of a derived Shape object.
     * @return The volume of the shape as a double value.
     */
    virtual double volume() = 0;

    /**
     * @brief Pure virtual function for calculating and returning the surface area of a derived Shape object.
     * @return The surface area of the shape as a double value.
     */
    virtual double surfaceArea() = 0;

    /**
     * @brief Pure virtual function that returns the object's class name (as returned by typeid).
     * @return A string containing the formatted text representing the Shape object.
     */
    virtual std::string toString() = 0;
};

#endif