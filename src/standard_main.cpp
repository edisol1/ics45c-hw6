#include <iostream>
#include <string>
#include "picture.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
using namespace std;

int main(int argc, char * argv[])
{
    Picture collage;

    collage.add(Circle{Point{0, 0}, "Circle_1", 5});
    
    collage.print_all(cout);
}
