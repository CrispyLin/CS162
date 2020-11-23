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

float Shape::area()const {
	return 0;
}
/*
bool operator>(const Shape& s1, const Shape& s2) {
	cout << "operator '>' invoked, Comparing " << s1.name << " and " << s2.name <<". The result is "<< (s1.area() > s2.area()) << endl;
	
	return (s1.area() > s2.area());
}

bool operator<(const Shape& s1, const Shape& s2) {
	cout << "operator '<' invoked, Comparing " << s1.name << " and " << s2.name << ". The result is " << (s1.area() < s2.area()) << endl;
	return (s1.area() < s2.area());
}*/

bool Shape::operator>(const Shape& s1) {
	cout << "operator '>' invoked, Comparing " << this->name << " and " << s1.name << ". The result is " << (this->area() > s1.area()) << endl;

	return (this->area() > s1.area());
}

bool Shape::operator<(const Shape& s1) {
	cout << "operator '<' invoked, Comparing " << this->name << " and " << s1.name << ". The result is " << (this->area() < s1.area()) << endl;
	return (this->area() < s1.area());
}