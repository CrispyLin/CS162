#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape {
	protected:
		string name;
		string color;
	public:
		Shape();
		Shape(string, string);

		string get_name() const;
		void set_name(string);

		string get_color() const;
		void set_color(string);

		int area();
};#endif // !SHAPE_H