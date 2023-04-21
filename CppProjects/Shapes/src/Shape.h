/*
 * Title:  Shapes
 * Desc:   Abstract Shape class representing a base class for 3D geometric shapes
 * Author: Bryce Verberne
 * Date:   04/19/2023
 */



#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    // Destructor: Virtual destructor to ensure proper cleanup when deleting
    //             derived class objects through a Shape pointer
    virtual ~Shape() = default;

    // volume: Pure virtual function for calculating and returning the volume
    //         of a derived Shape object
    virtual double volume() = 0;

    // surfaceArea: Pure virtual function for calculating and returning the
    //              surface area of a derived Shape object
    virtual double surfaceArea() = 0;

};

#endif