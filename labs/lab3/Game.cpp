#include "Game.h"
using namespace std;
//constructors
Game::Game(){
    this->cards = Deck();
    this->players[0] = Player();
    this->players[1] = Player();
}

//mutators and accessors
void Game::set_cards(Deck cards){
    this->cards = cards;
}

Deck Game::get_cards()const{
    return this->cards;
}

void Game::set_players(int index, Player player){
    this->players[index] = player;
}

Player Game::get_player(int index)const{
    return this->players[index];
}

//copy constructor
Game::Game(const Game& old_game){
    this->cards = old_game.cards;
    this->players[0] = old_game.players[0];
    this->players[1] = old_game.players[1];
}

Game& Game::operator=(const Game& old_game){
    if (this != &old_game){
        this->cards = old_game.cards;
        this->players[0] = old_game.players[0];
        this->players[1] = old_game.players[1];
    }
    return *this;
}

//other member functions
bool Game::is_game_over(){
    //to check is the game is over or not, see if there are no cards on the deck and both players' hand
    int n_card_deck = this->cards.get_n_cards();
    int n_card_user = this->players[0].get_hand().get_n_cards();
    int n_card_ai = this->players[1].get_hand().get_n_cards();

    if(n_card_ai==0 && n_card_deck==0 && n_card_user==0)
        return true;
    return false;
}