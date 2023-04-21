/**
 * @file Cube.h
 * @title Shapes
 * @brief Cube class representing a 3D cube shape, inheriting from Shape class.
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include <string>

class Cube : public Shape {
public:
    /**
     * @brief Initializes a Cube object with a default side length of 0.
     */
    Cube();

    /**
     * @brief Initializes a Cube object with the specified side length.
     * @param w The side length of the cube.
     */
    Cube(double);

    /**
     * @brief Cleans up resources when a Cube object is destroyed.
     */
    ~Cube() override = default;

    /**
     * @brief Calculates and returns the volume of the Cube object.
     * @return The volume of the cube as a double value.
     */
    double volume() override;

    /**
     * @brief Calculates and returns the surface area of the Cube object.
     * @return The surface area of the cube as a double value.
     */
    double surfaceArea() override;

    /**
     * @brief Returns a string representation of the Cube object, including the class name, surface area, and volume.
     * @return A string containing the formatted text representing the Cube object.
     */
    std::string toString() override;

private:
    /**
     * @brief The width (edge length) of the cube.
     */
    double width;
};

#endif