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

		virtual float area() const = 0;

		//operators overload
		//friend bool operator>(const Shape&, const Shape&);
		//friend bool operator<(const Shape&, const Shape&);
		bool operator>(const Shape&);
		bool operator<(const Shape&);
};
#endif // !SHAPE_H