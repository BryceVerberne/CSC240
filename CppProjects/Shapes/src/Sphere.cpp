/*
 * Title:  Shapes
 * Desc:   Implementation of the Sphere class, which represents a 3D sphere shape.
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <string>
#include <cmath>
#include "Sphere.h"

/*
 * Default Constructor
 * -------------------
 * Desc: Initializes a Sphere object with a default radius of 0.
 */
Sphere::Sphere() {
    radius = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:  Initializes a Sphere object with the specified radius.
 * Input: r - The radius of the sphere.
 * Output: None.
 */
Sphere::Sphere(double r) {
    radius = r;
}

/*
 * volume
 * ------
 * Desc:   Calculates and returns the volume of the Sphere object.
 * Input:  None.
 * Output: The volume of the sphere as a double value.
 */
double Sphere::volume() {
    return (4.0/3.0) * M_PI * pow(radius, 3.0);
}

/*
 * surfaceArea
 * -----------
 * Desc:   Calculates and returns the surface area of the Sphere object.
 * Input:  None.
 * Output: The surface area of the sphere as a double value.
 */
double Sphere::surfaceArea() {
    return 4 * M_PI * pow(radius, 2.0);
}

/*
 * toString
 * --------
 * Desc:   Returns a string representation of the Sphere object, including the class name, surface area, and volume.
 * Input:  None.
 * Output: A string containing the class name (as returned by typeid), surface area, and volume of the sphere.
 */
std::string Sphere::toString() {
    std::string sphereData = typeid(*this).name();

    sphereData += "\nSurface Area: ";
    sphereData += std::to_string(surfaceArea());

    sphereData += "\nVolume: ";
    sphereData += std::to_string(volume());

    return sphereData;
}
