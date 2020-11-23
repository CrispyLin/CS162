#include "shape.h"

using namespace std;

string Shape::get_name() const {
	return this->name;
}

void Shape::set_name(string name) {
	this->name = name;
}

string Shape::get_color() const {
	return this->color;
}
void Shape::set_color(string color) {
	this->color = color;
}

Shape::Shape() {
	this->name = "Unknow name";
	this->color = "Unknow color";
}

Shape::Shape(string name, string color) {
	this->name = name;
	this->color = color;
}

int Shape::area() {
	return 0;
}