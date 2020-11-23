#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(): Shape() {
	this->name = "rectangle";
	this->width = 0.0;
	this->height = 0.0;
}

Rectangle::Rectangle(string name, string color, float width, float height): Shape(name, color) {
	this->width = width;
	this->height = height;
}


void Rectangle::set_width(float width) {
	this->width = width;
}

float Rectangle::get_width()const {
	return this->width;
}

void Rectangle::set_height(float height) {
	this->height = height;
}

float Rectangle::get_height()const {
	return this->height;
}

float Rectangle::area() const {
	return this->width * this->height;
}