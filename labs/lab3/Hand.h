#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Card.h"
using namespace std;

class Hand {
	private:
		Card* cards;
		int n_cards; // Number of cards in the hand.
	public:
		// must have constructors, destructor, accessors, and mutators
		Hand();
		Hand(Card*, int);
		Hand (const Hand& );
		Hand& operator=(const Hand&);
		~Hand();
		void set_cards(Card*);
		void set_n_cards(int);
		Card* get_cards()const;
		int get_n_cards()const;
		void add_card(Card);
};

#endif // !HAND_H
