/**
 * @class Cube
 * @title 3D Cube Shape
 * @brief Represents a 3D Cube shape and provides functions for calculating its surface area and volume.
 * @author Bryce Verberne
 * @date 04/19/2023
 */



#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Cube.h"

/**
 * @brief Initializes a Cube object with a default side length of 0.
 */
Cube::Cube() {
    width = 0.0;
}

/**
 * @brief Initializes a Cube object with the specified side length.
 * @param w The side length of the cube.
 */
Cube::Cube(double w) {
    width = w;
}

/**
 * @brief Calculates and returns the volume of the Cube object.
 * @return The volume of the cube as a double value.
 */
double Cube::volume() {
    return pow(width, 3.0);
}

/**
 * @brief Calculates and returns the surface area of the Cube object.
 * @return The surface area of the cube as a double value.
 */
double Cube::surfaceArea() {
    return 6 * pow(width, 2.0);
}

/**
 * @brief Returns a string representation of the Cube object, including the class name, surface area, and volume.
 * @return A string containing the formatted text representing the Cube object.
 */
std::string Cube::toString() {
    // sstream Info Source: https://cplusplus.com/reference/sstream/stringstream/

    // Create a stringstream object to build the output string
    std::stringstream cubeData;

    // Calculate the truncated volume and surface area by rounding down to 3 decimal places
    double truncatedVol = floor(volume() * 1000) / 1000;
    double truncatedArea = floor(surfaceArea() * 1000) / 1000;

    // Add the class name to the stringstream (obtained from typeid)
    cubeData << typeid(*this).name();

    // Configure the stringstream to display fixed-point notation with 3 decimal places
    cubeData << std::fixed << std::setprecision(3);

    // Add the surface area and volume to the stringstream, with right-aligned values
    cubeData << "\nSurface Area:" << std::setw(10) << truncatedArea;
    cubeData << "\nVolume:" << std::setw(16) << truncatedVol;

    // Return the formatted string built using the stringstream object
    return cubeData.str();
}