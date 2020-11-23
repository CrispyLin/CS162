#ifndef CARD_H
#define CARD_H
#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Card {
	private:
		int rank; // Should be in the range 0-12.
		int suit; // Should be in the range 0-3.
	public:
		// must have constructors, destructor, accessors, and mutators
		Card();
		Card(int, int);
		Card(const Card&); //copy constructor
		Card& operator=(const Card&);
		void set_rank(int);
		int get_rank() const;
		void set_suit(int);
		int get_suit() const;
		string map_suit();
		string map_rank();
		void print_card();
};

#endif // !CARD_H
