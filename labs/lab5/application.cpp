#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
using namespace std;

int main() {
	//step 1 
	// instantiates some Shape objects and prints out their information.
	Shape s1;
	cout << "Shape 1's name is: " << s1.get_name() << endl;
	cout << "Shape 1's color is: " << s1.get_color() << endl << endl;

	Shape s2("diamond", "red");
	cout << "Shape 2's name is: " << s2.get_name() << endl;
	cout << "Shape 2's color is: " << s2.get_color() << endl << endl;

	//step 2
	//instantiates some rectangle and circle objects and prints out their information.
	Rectangle r1;
	cout << "Rectangle 1's name is: " << r1.get_name() << endl;
	cout << "Rectangle 1's color is: " << r1.get_color() << endl;
	cout << "Rectangle 1's width is: " << r1.get_width() << endl;
	cout << "Rectangle 1's height is: " << r1.get_height() << endl;
	cout << "Rectangle 1's area is: " << r1.area() << endl << endl;

	Rectangle r2("rectangle 2", "blue", 5, 10);
	cout << "Rectangle 2's name is: " << r2.get_name() << endl;
	cout << "Rectangle 2's color is: " << r2.get_color() << endl;
	cout << "Rectangle 2's width is: " << r2.get_width() << endl;
	cout << "Rectangle 2's height is: " << r2.get_height() << endl;
	cout << "Rectangle 2's area is: " << r2.area() << endl << endl;

	Circle c1;
	cout << "Circle 1's name is: " << c1.get_name() << endl;
	cout << "Circle 1's color is: " << c1.get_color() << endl;
	cout << "Circle 1's radius is: " << c1.get_radius() << endl;
	cout << "Circle 1's area is: " << c1.area() << endl << endl;

	Circle c2("Circle 2", "yellow", 7);
	cout << "Circle 2's name is: " << c2.get_name() << endl;
	cout << "Circle 2's color is: " << c2.get_color() << endl;
	cout << "Circle 2's radius is: " << c2.get_radius() << endl;
	cout << "Circle 2's area is: " << c2.area() << endl << endl;

	//step 3
	Square sq1;
	cout << "Square 1's name is: " << sq1.get_name() << endl;
	cout << "Square 1's color is: " << r2.get_color() << endl;
	cout << "Square 1's width is: " << sq1.get_width() << endl;
	cout << "Square 1's height is: " << sq1.get_height() << endl;
	cout << "Square 1's area is: " << sq1.area() << endl << endl;

	cout << "using set_width to modify square 1" << endl << endl;
	sq1.set_width(3.0);

	cout << "Square 1's name is: " << sq1.get_name() << endl;
	cout << "Square 1's color is: " << r2.get_color() << endl;
	cout << "Square 1's width is: " << sq1.get_width() << endl;
	cout << "Square 1's height is: " << sq1.get_height() << endl;
	cout << "Square 1's area is: " << sq1.area() << endl << endl;

	cout << "using set_height to modify square 1" << endl << endl;
	sq1.set_height(9.0);

	cout << "Square 1's name is: " << sq1.get_name() << endl;
	cout << "Square 1's color is: " << r2.get_color() << endl;
	cout << "Square 1's width is: " << sq1.get_width() << endl;
	cout << "Square 1's height is: " << sq1.get_height() << endl;
	cout << "Square 1's area is: " << sq1.area() << endl << endl;

	Square sq2("square 2", "green", 5);//using non default constructor
	cout << "Square 2's name is: " << sq1.get_name() << endl;
	cout << "Square 2's color is: " << r2.get_color() << endl;
	cout << "Square 2's width is: " << sq1.get_width() << endl;
	cout << "Square 2's height is: " << sq1.get_height() << endl;
	cout << "Square 2's area is: " << sq1.area() << endl << endl;
	return 0;
}