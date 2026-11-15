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

	collage.add(Rectangle{Point{3, 4}, "Rectangle_1", 8, 4});

	collage.add(Triangle{Point{6, 7}, "Triangle_1", 5, 5});
   
   	collage.add(Square{Point{1, 10}, "Square_1", 10});
	
	collage.print_all(cout);

	collage.draw_all(cout);

	cout << "Total area = " << collage.total_area() << '\n';
	// need to print it out since the total area returns double instead of void 
}
