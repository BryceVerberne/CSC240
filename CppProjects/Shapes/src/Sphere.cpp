/**
 * @file Sphere.cpp
 * @title Shapes
 * @brief Implementation of the Sphere class, which represents a 3D sphere shape.
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Sphere.h"

/**
 * @brief Initializes a Sphere object with a default radius of 0.
 */
Sphere::Sphere() {
    radius = 0.0;
}

/**
 * @brief Initializes a Sphere object with the specified radius.
 * @param r The radius of the sphere.
 */
Sphere::Sphere(double r) {
    radius = r;
}

/**
 * @brief Calculates and returns the volume of the Sphere object.
 * @return The volume of the sphere as a double value.
 */
double Sphere::volume() {
    return (4.0/3.0) * M_PI * pow(radius, 3.0);
}

/**
 * @brief Calculates and returns the surface area of the Sphere object.
 * @return The surface area of the sphere as a double value.
 */
double Sphere::surfaceArea() {
    return 4 * M_PI * pow(radius, 2.0);
}

/**
 * @brief Returns a string representation of the Sphere object, including the class name, surface area, and volume.
 * @return A string containing the formatted text representing the Sphere object.
 */
std::string Sphere::toString() {
    // sstream Info Source: https://cplusplus.com/reference/sstream/stringstream/

    // Create a stringstream object to build the output string
    std::stringstream sphereData;

    // Calculate the truncated volume and surface area by rounding down to 3 decimal places
    double truncatedVol = floor(volume() * 1000) / 1000;
    double truncatedArea = floor(surfaceArea() * 1000) / 1000;

    // Add the class name to the stringstream (obtained from typeid)
    sphereData << typeid(*this).name();

    // Configure the stringstream to display fixed-point notation with 3 decimal places
    sphereData << std::fixed << std::setprecision(3);

    // Add the surface area and volume to the stringstream, with right-aligned values
    sphereData << "\nSurface Area:" << std::setw(10) << truncatedArea;
    sphereData << "\nVolume:" << std::setw(16) << truncatedVol;

    // Return the formatted string built using the stringstream object
    return sphereData.str();
}