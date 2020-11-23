#include "Player.h"
using namespace std;
//constructors
Player::Player() {
	this->hand = Hand();
	this->books = NULL;
	this->n_books = 0;
}

Player::Player(Hand hand, int* books, int n_books) {
	this->books = books;
	this->n_books = n_books;
	this->hand = hand;
}

//copy constructor
Player::Player(const Player& old_player){
	this->hand = old_player.hand;
	this->n_books = old_player.n_books;
	if(old_player.books!=NULL){
		this->books = new int [this->n_books];
		for(int i=0;i<this->n_books;i++){
			this->books[i] = old_player.books[i];
		}
	}else
		this->books = NULL;
}

//operator overload
Player& Player::operator=(const Player& old_player){
	if (this != &old_player){
		if(this->books!=NULL){
			delete [] this->books;
			this->books = NULL;
			this->n_books = 0;
		}
		this->hand = old_player.hand;
		this->n_books = old_player.n_books;
		if(old_player.books!=NULL){
			this->books = new int [this->n_books];
			for(int i=0;i<this->n_books;i++){
				this->books[i] = old_player.books[i];
			}
		}else
			this->books = NULL;
	}
	return *this;
}

//destructor
Player::~Player(){
	if(this->books!=NULL && this->n_books!=0){
		delete [] this->books;
	}
	this->books = NULL;
	this->n_books = 0;
}

//mutators and accessors
void Player::set_hand(Hand hand) {
	this->hand = hand;
}

void Player::set_books(int* books) {
	this->books = books;
}

void Player::set_n_books(int n_books) {
	this->n_books = n_books;
}

Hand Player::get_hand()const {
	return this->hand;
}

int* Player::get_books()const {
	return this->books;
}

int Player::get_n_books()const {
	return this->n_books;
}

//other member functions
