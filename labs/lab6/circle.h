#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
using namespace std;

class Circle : public Shape {
	private:
		float radius;
	public:
		Circle();
		Circle(string, string, float);

		void set_radius(float);
		float get_radius()const;

		float area()const;
};

#endif 