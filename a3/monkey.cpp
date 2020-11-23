#include "monkey.h"
using namespace std;

//constructors
Monkey::Monkey() : Animal() {
	this->name = "monkey";
}

Monkey::Monkey(int age, string name): Animal(age, name) {}
