#include "square.h"
using namespace std;

Square::Square() : Rectangle() {
	this->name = "square";
}
Square::Square(string name, string color, float edge) : Rectangle(name, color, edge, edge) {}

void Square::set_width(float width) {
	Rectangle::set_width(width);
	Rectangle::set_height(width);
}

void Square::set_height(float height) {
	Rectangle::set_width(height);
	Rectangle::set_height(height);
}