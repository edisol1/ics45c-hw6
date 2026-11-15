#include "circle.hpp"
#include <iostream>
#include <numbers>

// since circle inherients from shape initialize the values that shape needs 
// circle is unique attribute is the radius 
Circle::Circle(Point center, std::string name, int radius)
    : Shape{center, name}, radius{radius} // basic constructor 
{
}

double Circle::area() const
{
    return 0.0; 
}

Circle* Circle::clone() const
{
    return new Circle{*this}; // creating a clone of the original circle object
}

void Circle::draw(std::ostream& out) const {
    for (int y = -radius; y <= radius; y += 2) {
        for (int x = -radius; x <= radius; ++x) {
            out << (x * x + y * y <= radius * radius ? '*' : ' ');
        }

        out << '\n';
    }
}

