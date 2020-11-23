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