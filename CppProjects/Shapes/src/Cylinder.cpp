/**
 * @class Cylinder
 * @title 3D Cylinder Shape
 * @brief Represents a 3D cylinder shape and provides functions for calculating its surface area and volume.
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Cylinder.h"

/**
 * @brief Creates a Cylinder object with default values for radius and height.
 */
Cylinder::Cylinder() {
    radius = 0.0;
    height = 0.0;
}

/**
 * @brief Creates a Cylinder object with the specified radius and height.
 * @param r The radius of the cylinder.
 * @param h The height of the cylinder.
 */
Cylinder::Cylinder(double r, double h) {
    radius = r;
    height = h;
}

/**
 * @brief Calculates and returns the volume of the Cylinder object.
 * @return The volume of the cylinder as a double value.
 */
double Cylinder::volume() {
    return M_PI * pow(radius, 2.0) * height;
}

/**
 * @brief Calculates and returns the surface area of the Cylinder object.
 * @return The surface area of the cylinder as a double value.
 */
double Cylinder::surfaceArea() {
    return (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2.0));
}

/**
 * @brief Returns a string representation of the Cylinder object, including the class name, surface area, and volume.
 * @return A string containing the formatted text representing the Cylinder object.
 */
std::string Cylinder::toString() {
    // sstream Info Source: https://cplusplus.com/reference/sstream/stringstream/

    // Create a stringstream object to build the output string
    std::stringstream cylinderData;

    // Calculate the truncated volume and surface area by rounding down to 3 decimal places
    double truncatedVol = floor(volume() * 1000) / 1000;
    double truncatedArea = floor(surfaceArea() * 1000) / 1000;

    // Add the class name to the stringstream (obtained from typeid)
    cylinderData << typeid(*this).name();

    // Configure the stringstream to display fixed-point notation with 3 decimal places
    cylinderData << std::fixed << std::setprecision(3);

    // Add the surface area and volume to the stringstream, with right-aligned values
    cylinderData << "\nSurface Area:" << std::setw(10) << truncatedArea;
    cylinderData << "\nVolume:" << std::setw(16) << truncatedVol;

    // Return the formatted string built using the stringstream object
    return cylinderData.str();
}