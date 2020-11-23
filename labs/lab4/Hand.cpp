#include "Hand.h"
using namespace std;

//constructors
Hand::Hand() {
	this->cards = NULL;
	this->n_cards = 0;
}

Hand::Hand(Card* cards, int n_cards) {
	this->cards = cards;
	this->n_cards = n_cards;
}

//copy constructor
Hand::Hand (const Hand& old_hand){
	this->n_cards = old_hand.n_cards;
	if(old_hand.cards != NULL){
		this->cards = new Card [this->n_cards];
		for(int i=0;i<this->n_cards;i++){
			this->cards[i] = old_hand.cards[i];
		}
	}else
		this->cards = NULL;
	return;
}

//operator overload
Hand& Hand::operator=(const Hand& old_hand){
	if (this != &old_hand){
		if(this->cards!=NULL){
			delete [] this->cards;
			this->n_cards = 0;
		}
		this->n_cards = old_hand.n_cards;
		if(old_hand.cards != NULL){
			this->cards = new Card [this->n_cards];
			for(int i=0;i<this->n_cards;i++){
				this->cards[i] = old_hand.cards[i];
			}
		}else
			this->cards = NULL;
	}
	return *this;
}

//destructor
Hand::~Hand(){
	if(this->cards!=NULL){
		delete [] this->cards;
	}
	this->cards = NULL;
	this->n_cards = 0;
}

//mutators and accessors
void Hand::set_cards(Card* cards) {
	this->cards = cards;
	return;
}

void Hand::set_n_cards(int n_cards) {
	this->n_cards = n_cards;
}

Card* Hand::get_cards()const {
	return this->cards;
}

int Hand::get_n_cards()const {
	return this->n_cards;
}

//other member functions
void Hand::add_card(Card new_card){
	if(this->cards!=NULL){
		Card* arr = new Card [this->n_cards+1];
		for(int i=0;i<this->n_cards;i++){
			arr[i] = this->cards[i];
		}
		arr[n_cards] = new_card;
		this->n_cards++;
		delete [] this->cards;
		this->cards = arr;
	}else{
		//cards are empty
		Card* arr = new Card [1];
		arr[n_cards] = new_card;
		this->n_cards++;
		this->cards = arr;
	}
	return;
}

Card Hand::remove_card(int index) {
	Card removed_card;
	if (this->cards != NULL) {
		removed_card = this->cards[index];//have a copy of the card being removed
		Card* arr = new Card[this->n_cards - 1];
		for (int i = 0; i < index; i++) {
			arr[i] = this->cards[i];
		}
		for (int i = index; i < this->n_cards-1; i++) {
			arr[i] = this->cards[i + 1];
		}
		delete[] this->cards;
		this->cards = arr;
		this->n_cards--;
	}
	else {
		cout << "card array is empty on the hand" << endl;
	}
	return removed_card;
}

void Hand::print_specific_rank_cards(int rank) const {
	for (int i = 0; i < this->n_cards; i++) {
		if (this->cards[i].get_rank() == rank) {
			cout << "\t";
			this->cards[i].print_card();
			cout << endl;
		}
	}
	return;
}

void Hand::print_cards(int player_or_computer)const {
	if (this->cards != NULL) {
		if (player_or_computer == 0) {
			cout << "You now have those card(s) on your hand: " << endl;
		}
		else
			cout << "Carlos now has those card(s) on his hand: " << endl;
		for (int i = 0; i < 13; i++) {
			print_specific_rank_cards(i);
		}
		cout << endl;
	}
	return;
}

bool Hand::is_rank_exist_on_hand(string r) {
	for (int i = 0; i < this->n_cards; i++) {
		if (this->cards[i].is_same_rank(r)) {
			return true;
		}
	}
	return false;
}

int Hand::which_book() const {
	int rank0 = 0, rank1 = 0, rank2 = 0, rank3 = 0, rank4 = 0, rank5 = 0, rank6 = 0, rank7 = 0, rank8 = 0, rank9 = 0, rank10 = 0, rank11 = 0, rank12 = 0;
	for (int i = 0; i < this->n_cards; i++) {
		switch (this->cards[i].get_rank()) {
			case 0: rank0++; break;
			case 1: rank1++; break;
			case 2: rank2++; break;
			case 3: rank3++; break;
			case 4: rank4++; break;
			case 5: rank5++; break;
			case 6: rank6++; break;
			case 7: rank7++; break;
			case 8: rank8++; break;
			case 9: rank9++; break;
			case 10: rank10++; break;
			case 11: rank11++; break;
			case 12: rank12++; break;
		}
	}

	if (rank0 == 4) return 0;
	else if (rank1 == 4) return 1;
	else if (rank2 == 4) return 2;
	else if (rank3 == 4) return 3;
	else if (rank4 == 4) return 4;
	else if (rank5 == 4) return 5;
	else if (rank6 == 4) return 6;
	else if (rank7 == 4) return 7;
	else if (rank8 == 4) return 8;
	else if (rank9 == 4) return 9;
	else if (rank10 == 4) return 10;
	else if (rank11 == 4) return 11;
	else if (rank12 == 4) return 12;
	else return -1;
}

void Hand::remove_this_rank(int rank) {
	for (int i = 0; i < this->n_cards; i++) {
		if (this->cards[i].get_rank() == rank) {
			remove_card(i);
			i--;
		}
	}
	return;
}