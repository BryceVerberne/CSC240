/**
 * @file Cylinder.h
 * @title Shapes
 * @brief Cylinder class representing a 3D cylinder shape, inheriting from Shape class.
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include <string>

class Cylinder : public Shape {
public:
    /**
     * @brief Creates a Cylinder object with default values for radius and height.
     */
    Cylinder();

    /**
     * @brief Creates a Cylinder object with the specified radius and height.
     * @param r The radius of the cylinder.
     * @param h The height of the cylinder.
     */
    Cylinder(double, double);

    /**
     * @brief Cleans up resources when a Cylinder object is destroyed.
     */
    ~Cylinder() override = default;

    /**
     * @brief Calculates and returns the volume of the Cylinder object.
     * @return The volume of the cylinder as a double value.
     */
    double volume() override;

    /**
     * @brief Calculates and returns the surface area of the Cylinder object.
     * @return The surface area of the cylinder as a double value.
     */
    double surfaceArea() override;

    /**
     * @brief Returns a string representation of the Cylinder object, including the class name, surface area, and volume.
     * @return A string containing the formatted text representing the Cylinder object.
     */
    std::string toString() override;

private:
    /**
     * @brief The radius of the cylinder.
     */
    double radius;

    /**
     * @brief The height of the cylinder.
     */
    double height;
};

#endif