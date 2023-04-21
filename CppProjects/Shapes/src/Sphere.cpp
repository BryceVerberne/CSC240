/*
 * Title:  Shapes
 * Desc:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include <string>
#include <cmath>
#include "Sphere.h"

/*
 * Default Constructor
 * -------------------
 * Desc:
 */
Sphere::Sphere() {
    radius = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:
 */
Sphere::Sphere(double r) {
    radius = r;
}

/*
 * volume
 * ------
 * Desc:   Calculates and returns the volume of the Cube object
 * Input:
 * Output:
 * Notes:
 */
double Sphere::volume() {
    return (4.0/3.0) * M_PI * pow(radius, 3.0);
}

/*
 * surfaceArea
 * -----------
 * Desc:   Calculates and returns the surface area of the Cylinder object
 * Input:
 * Output:
 * Notes:
 */
double Sphere::surfaceArea() {
    return 4 * M_PI * pow(radius, 2.0);
}