#include "shape.hpp"
#include <iostream>

// constructer initializing all the variables and attributes for the shapes
Shape::Shape(Point center, std::string name)
    : center{center}, name{name}
{
// only save the shapes location and its name 
}

void Shape::print(std::ostream& out) const
{
// printing out the values for the shape attributes 
    out << name << " at (" << center.x << ", " << center.y << ")\n";
}
