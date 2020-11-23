#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Hand.h"
using namespace std;

class Player {
	private:
		Hand hand;
		int* books; // Array with ranks for which the player has books.
		int n_books;
	public:
		// must have constructors, destructor, accessors, and mutators
		Player();
		Player(Hand, int*, int);
		Player(const Player& );
		Player& operator=(const Player&);
		~Player();
		void set_hand(Hand);
		void set_books(int*);
		void set_n_books(int);
		Hand get_hand()const;
		int* get_books()const;
		int get_n_books()const;

		void display_unique_ranks();//this function will return an array that represents unique ranks on the hand
		void make_book();
		void make_book_computer();
		void add_book(int);
		void add_book_computer(int);
		void display_books()const;
		void display_books_computer()const;
};
#endif // !PLAYER_H
