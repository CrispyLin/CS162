#include "sea_otter.h"
using namespace std;
//constructors
Sea_otter::Sea_otter() : Animal() {
	this->name = "sea otter";
}

Sea_otter::Sea_otter(int age, string name) : Animal(age, name) {}