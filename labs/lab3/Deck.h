#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Card.h"
using namespace std;

class Deck {
	private:
		Card cards[52];
		int n_cards; // Number of cards remaining in the deck.
	public:
		// must have constructors, destructor, accessors, and mutators
		Deck();
		Deck(const Deck& );
		Deck& operator=(const Deck&);
		int get_n_cards()const;
		void set_n_cards(int);
		Card get_card(int)const;
		void set_cards(int,Card);
		Card remove_card(int);
		void generate_cards();
		void randomizing();
};

#endif // !DECK_H
