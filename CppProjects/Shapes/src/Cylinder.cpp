/*
 * Title:  Shapes
 * Desc:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include <string>
#include "Cylinder.h"

/*
 * Default Constructor
 * -------------------
 * Desc:
 */
Cylinder::Cylinder() {
    radius = 0.0;
    height = 0.0;
}

/*
 * Parameterized Constructor
 * -------------------------
 * Desc:
 */
Cylinder::Cylinder(double r, double h) {
    radius = r;
    height = h;
}