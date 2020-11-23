#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
using namespace std;

class Rectangle : public Shape {
	private:
		float width;
		float height;
	public:
		Rectangle();
		Rectangle(string, string, float, float);

		void set_width(float);
		float get_width()const;

		void set_height(float);
		float get_height()const;

		float area()const;
};


#endif 