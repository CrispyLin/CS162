#include "circle.h"
using namespace std;

Circle::Circle():Shape() {
	this->name = "circle";
	this->radius = 0.0;
}

Circle::Circle(string name, string color, float radius): Shape(name, color) {
	this->radius = radius;
}

void Circle::set_radius(float radius) {
	this->radius = radius;
}

float Circle::get_radius()const {
	return this->radius;
}

float Circle::area()const {
	return this->radius * 2 * 3.1415926;
}