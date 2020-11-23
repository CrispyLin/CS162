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

void Game::set_up() {
    cout << "dealing cards......" << endl << endl;
    this->cards.generate_cards();
    this->cards.randomizing();
    Hand hand1, hand2;
    //deal cards for user
    for (int i = 0; i < 7; i++) {
        int num = rand() % this->cards.get_n_cards();
        Card removed_card = this->cards.remove_card(num);
        hand1.add_card(removed_card);
    }
    this->players[0].set_hand(hand1);
    //deal cards for computer
    for (int i = 0; i < 7; i++) {
        int num = rand() % this->cards.get_n_cards();
        Card removed_card = this->cards.remove_card(num);
        hand2.add_card(removed_card);
    }
    this->players[1].set_hand(hand2);
}

void Game::print_deck() {
    cout << "Currently, the card stock has " << this->cards.get_n_cards() << " cards left." << endl << endl;
}

void Game::calculate_results() {
    //to see how many books two players have, bigger one wins
    int user_n_books = this->players[0].get_n_books();
    int computer_n_books = this->players[1].get_n_books();
    if (user_n_books > computer_n_books) {
        cout << "You have " << user_n_books << " books, Carlos has "<<computer_n_books<<"\nYou win!" << endl;
    }
}

Card Game::draw_card() {
    if (this->cards.get_n_cards() != 0) {
        return this->cards.remove_card(0);
    }
}

Card Game::go_fish(int player_index) {
    Card c;
    if (player_index == 0) {
        cout << "You don't have card that has same rank as Carlos requested, you said Go Fish." << endl;
        cout << "Carlos draws a card from deck" << endl;
        c = draw_card();
        Hand h = this->players[1].get_hand();
        h.add_card(c);
        this->players[1].set_hand(h);
    }
    else {
        cout << "Carlos said Go Fish, you will draw a card from deck" << endl << endl;
        c = draw_card();
        cout << "You get a card: ";
        c.print_card();
        cout << endl;
        Hand h = this->players[0].get_hand();
        h.add_card(c);
        this->players[0].set_hand(h);
    }
    return c;
}

int Game::get_user_option() {
    cout << "Which rank of cards do you want to ask for? ";
    string input;
    Card c;
    while (1) {
        getline(cin, input);
        if (this->players[0].get_hand().is_rank_exist_on_hand(input)) {
            return c.map_rank(input);
        }
        else {
            cout << "Error, Enter again: ";
        }
    }
}

bool Game::user_get_cards_or_go_fish(int rank_to_ask) {
    Card c;
    if (this->players[1].get_hand().is_rank_exist_on_hand(c.map_rank(rank_to_ask))) {
        //if true, get cards from players[index], this function will return false;
        Hand h = this->players[1].get_hand();
        Hand h2 = this->players[0].get_hand();

        for (int i = 0; i < h.get_n_cards(); i++) {
            if (h.get_cards()[i].get_rank() == rank_to_ask) {
                Card removed_card = h.remove_card(i);
                cout << "You get a card ";
                removed_card.print_card();
                cout<< " from Carlos" <<endl;
                h2.add_card(removed_card);
                i--;//because the card is removed from index i, so next loop will continue to the same index
            }
        }
        this->players[1].set_hand(h);
        this->players[0].set_hand(h2);
        return true;
    }
    else {
        if (this->cards.get_n_cards() != 0) {
            Card returned_card = go_fish(1);
            if (returned_card.get_rank() == rank_to_ask) {
                return true;
            }
            return false;
        }
        else {
            //when deck ran out of cards
            cout << "Deck ran out of cards, you cannot draw card form deck." << endl;
            return false;
        }

    }
}


bool Game::computer_get_cards_or_go_fish(int rank_to_ask) {
    Card c;
    if (this->players[0].get_hand().is_rank_exist_on_hand(c.map_rank(rank_to_ask))) {
        //if true, get cards from players[index], this function will return false;
        Hand h = this->players[0].get_hand();
        Hand h2 = this->players[1].get_hand();

        for (int i = 0; i < h.get_n_cards(); i++) {
            if (h.get_cards()[i].get_rank() == rank_to_ask) {
                Card removed_card = h.remove_card(i);
                cout << "Carlos gets a card ";
                removed_card.print_card();
                cout << " from you" << endl;
                h2.add_card(removed_card);
                i--;//because the card is removed from index i, so next loop will continue to the same index
            }
        }
        this->players[0].set_hand(h);
        this->players[1].set_hand(h2);
        return true;
    }
    else {
        if (this->cards.get_n_cards() != 0) {
            Card returned_card = go_fish(0);
            if (returned_card.get_rank() == rank_to_ask) {
                cout << "Carlos gets card: ";
                returned_card.print_card();
                cout << endl;
                return true;
            }
        }
        else {
            //when deck ran out of cards
            cout << "Deck ran out of cards, Carlos cannot draw card form deck." << endl;
            return false;
        }
        return false;
    }
}

bool Game::user_round_cheat() {
    if (is_game_over()) {
        return false;
    }
    cout << "-----------------Your turn-------------------" << endl;
    print_deck();//print current deck
    this->players[1].get_hand().print_cards(1);//print cards on Carlos' hand
    this->players[1].display_books_computer();//display carlo's card
    this->players[0].get_hand().print_cards(0);//print cards on user's hand
    this->players[0].display_books();//display user's card
    this->players[0].display_unique_ranks(); //provide user which ranks are avaliable to ask
    if (this->players[0].get_hand().get_n_cards() != 0) {
        int rank_to_ask = get_user_option(); //get the rank user want to ask
        //check if the asked rank exist in Carlos' hand
        //if yes, remove cards from Carlos' hand, if not, get a card from deck
        //second parameter is the play where the cards are coming from
        bool another_round = user_get_cards_or_go_fish(rank_to_ask);
        this->players[0].make_book();//after get cards, check if there are books can be made
        cout << endl;
        return another_round;
    }
    else {
        Card c;
        cout << "Sorry, you ran out of cards on your hand, you will draw a card from the deck and ask the same rank automatically." << endl;
        Card draw_a_card = draw_card();
        Hand h = this->players[0].get_hand();
        h.add_card(draw_a_card);
        this->players[0].set_hand(h);
        cout << "You got a card ";
        draw_a_card.print_card();
        cout << endl;
        cout << "You ask Carlos for " << c.map_rank(draw_a_card.get_rank()) << " cards" << endl << endl;
        bool another_round = user_get_cards_or_go_fish(draw_a_card.get_rank());
        this->players[0].make_book();//after get cards, check if there are books can be made
        cout << endl;
        return another_round;
    }
}

bool Game::computer_round() {
    if (is_game_over()) {
        return false;
    }
    cout << "------------------Carlos' turn-------------------" << endl;
    Card c;
    int n_cards = this->players[1].get_hand().get_n_cards();
    if (n_cards != 0) {
        int index = rand() % n_cards;//generate an random index
        int rank_to_ask = this->players[1].get_hand().get_cards()[index].get_rank();//get that index of card's rank to ask user
        cout << "Carlos wants your " << c.map_rank(rank_to_ask) << " cards" << endl << endl;
        bool another_round = computer_get_cards_or_go_fish(rank_to_ask);
        this->players[1].make_book_computer();
        cout << endl;
        return another_round;
    }
    else {
        cout << "Carlos ran out of his cards, he can only draw a card from deck" << endl;
        Card draw_a_card = draw_card();
        Hand h = this->players[1].get_hand();
        h.add_card(draw_a_card);
        this->players[1].set_hand(h);
        cout << "Carlos got a card ";
        draw_a_card.print_card();
        cout << "Carlos wants your " << c.map_rank(draw_a_card.get_rank()) << " cards" << endl << endl;
        cout << endl;
        bool another_round = computer_get_cards_or_go_fish(draw_a_card.get_rank());
        this->players[1].make_book_computer();
        cout << endl;
        return another_round;
    }
}

bool Game::user_round() {
    if (is_game_over()) {
        return false;
    }
    cout << "-----------------Your turn-------------------" << endl;
    print_deck();//print current deck
    this->players[0].get_hand().print_cards(0);//print cards on user's hand
    this->players[0].display_books();//display user's card
    this->players[0].display_unique_ranks(); //provide user which ranks are avaliable to ask
    if (this->players[0].get_hand().get_n_cards() != 0) {
        int rank_to_ask = get_user_option(); //get the rank user want to ask
        //check if the asked rank exist in Carlos' hand
        //if yes, remove cards from Carlos' hand, if not, get a card from deck
        //second parameter is the play where the cards are coming from
        bool another_round = user_get_cards_or_go_fish(rank_to_ask);
        this->players[0].make_book();//after get cards, check if there are books can be made
        cout << endl;
        return another_round;
    }
    else {
        Card c;
        cout << "Sorry, you ran out of cards on your hand, you will draw a card from the deck and ask the same rank automatically." << endl;
        Card draw_a_card = draw_card();
        Hand h = this->players[0].get_hand();
        h.add_card(draw_a_card);
        this->players[0].set_hand(h);
        cout << "You got a card ";
        draw_a_card.print_card();
        cout << endl;
        cout << "You ask Carlos for " << c.map_rank(draw_a_card.get_rank()) << " cards" << endl << endl;
        bool another_round = user_get_cards_or_go_fish(draw_a_card.get_rank());
        this->players[0].make_book();//after get cards, check if there are books can be made
        cout << endl;
        return another_round;
    }
}