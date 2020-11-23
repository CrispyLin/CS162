#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

void print_shape_info(Shape& s) {
	cout << "This is a " << s.get_name() << ", ";
	cout << "it's color is " << s.get_color() << ", ";
	cout << "it's area is " << s.area() << endl;
	return;
}

int main() {
	//instantiates some rectangle and circle objects and prints out their information.
	Rectangle r1("rectangle 1", "black", 10, 15);
	print_shape_info(r1);
	Rectangle r2("rectangle 2", "blue", 5, 10);
	print_shape_info(r2);
	cout << "testing if '>' and '<' operator are working for two rectangle objects" << endl;
	if (r1 > r2) {
		cout << "The area of rectangle 1 is bigger than rectangle 2" << endl;
	}
	else if (r1 < r2) {
		cout << "The area of rectangle 1 is smaller than rectangle 2" << endl;
	}
	else {
		cout << "The area of rectangle 1 is equal to rectangle 2" << endl;
	}

	cout << endl;

	Circle c1("Circle 1", "pink", 3);
	print_shape_info(c1);
	Circle c2("Circle 2", "yellow", 7);
	print_shape_info(c2);
	cout << "testing if '>' and '<' operator are working for two circle objects" << endl;
	if (c1 > c2) {
		cout << "The area of circle 1 is bigger than circle 2" << endl;
	}
	else if (c1 < c2) {
		cout << "The area of circle 1 is smaller than circle 2" << endl;
	}
	else {
		cout << "The area of circle 1 is equal to circle 2" << endl;
	}

	cout << endl;

	Square sq1;
	sq1.set_width(12.0);
	print_shape_info(sq1);
	Square sq2("square 2", "green", 5);//using non default constructor
	print_shape_info(sq2);
	cout << "testing if '>' and '<' operator are working for two square objects" << endl;
	if (sq1 > sq2) {
		cout << "The area of square 1 is bigger than square 2" << endl;
	}
	else if (sq1 < sq2) {
		cout << "The area of square 1 is smaller than square 2" << endl;
	}
	else {
		cout << "The area of square 1 is equal to square 2" << endl;
	}

	cout << endl;

	cout << "testing if '>' and '<' operator are working for two different objects" << endl;
	if (r2 > sq2) {
		cout << "The area of rectangle 2 is bigger than square 2" << endl;
	}
	else if (r2 > sq2) {
		cout << "The area of rectangle 2 is smaller than square 2" << endl;
	}
	else {
		cout << "The area of rectangle 2 is equal to square 2" << endl;
	}


	return 0;
}