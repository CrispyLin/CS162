#include "Card.h"
using namespace std;

//default constructor
Card::Card() {
	this->rank = -1;
	this->suit = -1;
}
//constructor
Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
}

//copy constructor
Card::Card(const Card& old_card){
	this->rank = old_card.rank;
	this->suit = old_card.suit;
} 

//operater overload
Card& Card::operator=(const Card& old_card){
	if (this != &old_card){
		this->rank = old_card.rank;
		this->suit = old_card.suit;
	}
}

//mutators and accessors
void Card::set_rank(int rank) {
	this->rank = rank;
	return;
}

int Card::get_rank() const {
	return this->rank;
}

void Card::set_suit(int suit) {
	this->suit = suit;
	return;
}

int Card::get_suit() const {
	return this->suit;
}


//other functions
string Card::map_suit() {
	switch (this->suit){
		case 0: return "clubs";
		case 1: return "diamonds";
		case 2: return "hearts";
		default: return "spades";
	}
}

string Card::map_rank() {
	switch (this->rank){
		case 0: return "2";
		case 1: return "3";
		case 2: return "4";
		case 3: return "5";
		case 4: return "6";
		case 5: return "7";
		case 6: return "8";
		case 7: return "9";
		case 8: return "10";
		case 9: return "J";
		case 10: return "Q";
		case 11: return "K";
		default: return "A";
	}
}

void Card::print_card() {
	cout<<map_suit()<<" "<<map_rank();
	return;
}