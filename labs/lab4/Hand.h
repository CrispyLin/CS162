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
		void print_cards(int)const;
		void print_specific_rank_cards(int) const;
		Card remove_card(int);

		//check to see if the input rank exist in the hand/does any cards have the same rank
		bool is_rank_exist_on_hand(string);

		//if there is a book can be made, the function will return 0-12, inclusively, if not it will return -1.
		int which_book() const;

		void remove_this_rank(int);
};

#endif // !HAND_H
