/*
 * Title:  Shapes
 * Desc:   Implementation of the Cube class, which represents a 3D cube shape.
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <string>
#include <cmath>
#include "Cube.h"

/*
 * Default Constructor
 * -------------------
 * Desc: Initializes a Cube object with a default side length of 0.
 */
Cube::Cube() {
    width = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:  Initializes a Cube object with the specified side length.
 * Input: w - The side length of the cube.
 * Output: None.
 */
Cube::Cube(double w) {
    width = w;
}

/*
 * volume
 * ------
 * Desc:   Calculates and returns the volume of the Cube object.
 * Input:  None.
 * Output: The volume of the cube as a double value.
 */
double Cube::volume() {
    return pow(width, 3.0);
}

/*
 * surfaceArea
 * -----------
 * Desc:   Calculates and returns the surface area of the Cube object.
 * Input:  None.
 * Output: The surface area of the cube as a double value.
 */
double Cube::surfaceArea() {
    return 6 * pow(width, 2.0);
}

/*
 * toString
 * --------
 * Desc:   Returns a string representation of the Cube object, including the class name, surface area, and volume.
 * Input:  None.
 * Output: A string containing the class name (as returned by typeid).
 */
std::string Cube::toString() {
    return typeid(*this).name();
}