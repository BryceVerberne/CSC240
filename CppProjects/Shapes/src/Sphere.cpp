/*
 * Title:  Shapes
 * Desc:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */


#include <iostream>
#include <string>
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