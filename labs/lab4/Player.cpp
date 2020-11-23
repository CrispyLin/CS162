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
void Player::display_unique_ranks() {
	Card* cards = this->hand.get_cards();
	int unique_card[13];
	int count = 0;
	for (int i = 0; i < this->hand.get_n_cards(); i++) {
		bool condition = true;
		for (int j = 0; j < count; j++) {
			if (cards[i].get_rank() == unique_card[j]) {
				condition = false;
				break;
			}
		}
		if (condition == true) {
			unique_card[count] = cards[i].get_rank();
			count++;
		}
	}

	//sort array
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++){
			if (unique_card[j] < unique_card[i]) {
				int temp = unique_card[i];
				unique_card[i] = unique_card[j];
				unique_card[j] = temp;
			}
		}
	}

	cout << "You can ask Carlos one of the following rank: \n";
	for (int i = 0; i < count; i++) {
		cout << "\t" <<cards[0].map_rank(unique_card[i]) << " ";
	}
	cout << endl << endl;;
}

void Player::add_book(int rank) {
	Card c;
	cout << "You got a new book from your cards, it is: " << c.map_rank(rank) << endl;
	if (this->books == NULL) {
		this->books = new int[1];
		this->books[0] = rank;
	}
	else {
		//books array exists, make a bigger one and copy
		int* new_arr = new int[this->n_books + 1];
		for (int i = 0; i < this->n_books; i++) {
			new_arr[i] = this->books[i];
		}
		new_arr[this->n_books] = rank;
		delete[] this->books;
		this->books = new_arr;
	}
	this->n_books++;
	this->hand.remove_this_rank(rank);
	return;
}

void Player::add_book_computer(int rank) {
	Card c;
	cout << "Carlos got a new book from his cards, it is: " << c.map_rank(rank) << endl;
	if (this->books == NULL) {
		this->books = new int[1];
		this->books[0] = rank;
	}
	else {
		//books array exists, make a bigger one and copy
		int* new_arr = new int[this->n_books + 1];
		for (int i = 0; i < this->n_books; i++) {
			new_arr[i] = this->books[i];
		}
		new_arr[this->n_books] = rank;
		delete[] this->books;
		this->books = new_arr;
	}
	this->n_books++;
	this->hand.remove_this_rank(rank);
	return;
}

void Player::display_books()const {
	Card c;
	if (this->n_books != 0) {
		cout << "You now have " << this->n_books << " book(s): " << endl;
		for (int i = 0; i < this->n_books; i++) {
			cout << "\t" << c.map_rank(this->books[i]) << endl;
		}
		cout << endl;
	}
	return;
}

void Player::display_books_computer()const {
	Card c;
	if (this->n_books != 0) {
		cout << "Carlos now has " << this->n_books << " book(s): " << endl;
		for (int i = 0; i < this->n_books; i++) {
			cout << "\t" << c.map_rank(this->books[i]) << endl;
		}
		cout << endl;
	}
	return;
}

void Player::make_book() {
	int rank = this->hand.which_book();
	switch (rank) {
		case -1: break;//there is no book can be made, do nothing
		case 0: add_book(0); break;
		case 1: add_book(1); break;
		case 2: add_book(2); break;
		case 3: add_book(3); break;
		case 4: add_book(4); break;
		case 5: add_book(5); break;
		case 6: add_book(6); break;
		case 7: add_book(7); break;
		case 8: add_book(8); break;
		case 9: add_book(9); break;
		case 10: add_book(10); break;
		case 11: add_book(11); break;
		case 12: add_book(12); break;
	}
}

void Player::make_book_computer() {
	int rank = this->hand.which_book();
	switch (rank) {
		case -1: break;//there is no book can be made, do nothing
		case 0: add_book_computer(0); break;
		case 1: add_book_computer(1); break;
		case 2: add_book_computer(2); break;
		case 3: add_book_computer(3); break;
		case 4: add_book_computer(4); break;
		case 5: add_book_computer(5); break;
		case 6: add_book_computer(6); break;
		case 7: add_book_computer(7); break;
		case 8: add_book_computer(8); break;
		case 9: add_book_computer(9); break;
		case 10: add_book_computer(10); break;
		case 11: add_book_computer(11); break;
		case 12: add_book_computer(12); break;
	}
}