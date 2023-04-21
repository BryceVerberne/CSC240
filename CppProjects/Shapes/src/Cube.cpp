/*
 * Title:  Shapes
 * Desc:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include <string>
#include <cmath>
#include "Cube.h"

/*
 * Default Constructor
 * -------------------
 * Desc:
 */
Cube::Cube() {
    width = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:
 */
Cube::Cube(double w) {
    width = w;
}

/*
 * volume
 * ------
 * Desc:   Calculates and returns the volume of the Cube object
 * Input:
 * Output:
 * Notes:
 */
double Cube::volume() {
    return pow(width, 3.0);
}

/*
 * surfaceArea
 * -----------
 * Desc:   Calculates and returns the surface area of the Cylinder object
 * Input:
 * Output:
 * Notes:
 */
double Cube::surfaceArea() {
    return 6 * pow(width, 2.0);
}