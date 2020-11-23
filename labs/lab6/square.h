#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
using namespace std;

class Square : public Rectangle {
public:
	Square();
	Square(string, string, float);
	void set_width(float);
	void set_height(float);
};

#endif