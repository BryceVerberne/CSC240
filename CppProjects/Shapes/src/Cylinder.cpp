/*
 * Title:  Shapes
 * Desc:   Implementation of the Cylinder class, which represents a 3D cylinder shape.
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Cylinder.h"

/*
 * Default Constructor
 * -------------------
 * Desc: Creates a Cylinder object with default values for radius and height
 */
Cylinder::Cylinder() {
    radius = 0.0;
    height = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:   Creates a Cylinder object with the specified radius and height
 * Input:  r - The radius of the cylinder.
 *         h - The height of the cylinder.
 * Output: None.
 */
Cylinder::Cylinder(double r, double h) {
    radius = r;
    height = h;
}

/*
 * volume
 * ------
 * Desc:   Calculates and returns the volume of the Cylinder object
 * Input:  None.
 * Output: The volume of the cylinder as a double value.
 */
double Cylinder::volume() {
    return M_PI * pow(radius, 2.0) * height;
}

/*
 * surfaceArea
 * -----------
 * Desc:   Calculates and returns the surface area of the Cylinder object
 * Input:  None.
 * Output: The surface area of the cylinder as a double value.
 */
double Cylinder::surfaceArea() {
    return (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2.0));
}

/*
 * toString
 * --------
 * Desc:   Returns a string representation of the Cylinder object, including the class name, surface area, and volume.
 * Input:  None.
 * Output: A string containing the formatted text representing the Cylinder object.
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