/**
 * @file Sphere.h
 * @title Shapes
 * @brief Sphere class representing a 3D sphere shape, inheriting from Shape class
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include <string>

class Sphere : public Shape {
public:
    /**
     * @brief Initializes a Sphere object with a default radius of 0.
     */
    Sphere();

    /**
     * @brief Initializes a Sphere object with the specified radius.
     * @param r The radius of the sphere.
     */
    Sphere(double);

    /**
     * @brief Cleans up resources when a Sphere object is destroyed.
     */
    ~Sphere() override = default;

    /**
     * @brief Calculates and returns the volume of the Sphere object.
     * @return The volume of the sphere as a double value.
     */
    double volume() override;

    /**
      * @brief Calculates and returns the surface area of the Sphere object.
      * @return The surface area of the sphere as a double value.
      */
    double surfaceArea() override;

    /**
     * @brief Returns a string representation of the Sphere object, including the class name, surface area, and volume.
     * @return A string containing the formatted text representing the Sphere object.
     */
    std::string toString() override;

private:
    /**
     * @brief The radius of the sphere.
     */
    double radius;
};

#endif