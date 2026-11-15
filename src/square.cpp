#include "square.hpp"
#include <iostream>

// simialr to how circle rectangle and triangle inherit from shape and use the shape 
// attributes square is a rectangle. 
Square::Square(Point center, std::string name, int side)
    : Rectangle{center, name, side, side}
{
}
