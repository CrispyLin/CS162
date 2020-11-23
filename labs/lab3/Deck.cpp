#include "Deck.h"
using namespace std;

//constructors
Deck::Deck(){
    this->n_cards = 0;
    for(int i=0;i<52;i++){
        this->cards[i] = Card();
    }
}

//copy constructor
Deck::Deck(const Deck& old_deck){
    this->n_cards = old_deck.n_cards;
    for(int i=0;i<this->n_cards;i++){
        this->cards[i] = old_deck.cards[i];
    }
}

//operator overload
Deck& Deck::operator=(const Deck& old_deck){
    if (this != &old_deck){
        this->n_cards = old_deck.n_cards;
        for(int i=0;i<this->n_cards;i++){
            this->cards[i] = old_deck.cards[i];
        }
    }
    return *this;
}

//mutators and accessors
int Deck::get_n_cards()const{
    return this->n_cards;
}

void Deck::set_n_cards(int i){
    this->n_cards = i;
    return;
}

Card Deck::get_card(int index)const{
    return this->cards[index];
}

void Deck::set_cards(int index, Card card){
    this->cards[index] = card;
}

//other member functions
Card Deck::remove_card(int index){
    Card card = this->cards[index]; //have a copy of removing card
    for(int i=index;i<51;i++){ //moving around cards after the removed card
        this->cards[i] = this->cards[i+1];
    }
    this->n_cards--;
    return card;
}

void Deck::generate_cards(){
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            Card card = Card(j,i); //create a card with non-default constructor
            this->cards[this->n_cards] = card;
            this->n_cards++;
        }
    }
    return;
}

void Deck::randomizing(){
    for(int i=0;i<200;i++){ //replcing cards in the deck 200 times
        int n1 = rand() % 52; //generate number between 0 and 51, inclusively
        int n2 = -1;
        do{
            n2 = rand() % 52;
        }while(n1==n2); //keep generating until get different second index

        //replacing cards
        Card temp = this->cards[n1];
        this->cards[n1] = this->cards[n2];
        this->cards[n2] = temp;
    }
    return;
}
