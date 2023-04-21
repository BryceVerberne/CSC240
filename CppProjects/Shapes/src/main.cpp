/*
 * Title:  Shapes
 * Des:
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#include <iostream>
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"

int main() {
    Sphere ball(10.0);
    Cube cuboid(10.0);
    Cylinder tube(2.0, 5.0);

    std::cout << "Sphere" << std::endl;
    std::cout << "Surface Area: " << ball.surfaceArea() << std::endl;
    std::cout << "Volume: " << ball.volume() << std::endl;

    std::cout << std::endl;

    std::cout << "Cube" << std::endl;
    std::cout << "Surface Area: " << cuboid.surfaceArea() << std::endl;
    std::cout << "Volume: " << cuboid.volume() << std::endl;

    std::cout << std::endl;

    std::cout << "Cylinder" << std::endl;
    std::cout << "Surface Area: " << tube.surfaceArea() << std::endl;
    std::cout << "Volume: " << tube.volume() << std::endl;

    return 0;
}

/**
* Example Output
* Sphere{radius=10.0}
* Cube{width=10.0}
* Cylinder{radius=2.0, height=5.0} *
* Sphere
* Surface Area: 1256.6370614359173
* Volume: 4188.790204786391 *
* Cube
* Surface Area: 600.0
* Volume: 1000.0 *
* Cylinder
* Surface Area: 87.96459430051421
* Volume: 62.83185307179586
*/