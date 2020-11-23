/******************************************************
** Program: Go_Fish.cpp
** Author: Xinwei Lin
** Date: 07/10/2020
** Description: 
** Input: 
** Output: 
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"
using namespace std;


bool check_commandline(int argc, char** argv){
	if(argc != 2){
		cout<<"Error!\nUsage: ./go_fish false  or  ./go_fish true"<<endl;
		exit(1);
	}
	if(argv[1][0] == 't')
		return true;
	else
		return false;
}

void dealt_card(int index, Game *game){
	Deck deck = (*game).get_cards();
	Player player;
	Hand hand;
	for(int i=0;i<7;i++){
		int num = rand() % deck.get_n_cards(); //get a random number
		Card removed_card = deck.remove_card(num);//remove that random number from the deck
		hand.add_card(removed_card);
	}
	player.set_hand(hand);
	(*game).set_players(index, player);
	(*game).set_cards(deck);
}

void build_game(Game* game){
	//set up deck of the game
	Deck cards = Deck();
	cards.generate_cards();
	cards.randomizing();
	(*game).set_cards(cards);
	
	dealt_card(0, game);//set up for user
	dealt_card(1, game);//set up for computer*/
}

void cheat_view(){

}

void normal_view(){

}

//if user want to play again, the function will return true, vice versa.
bool again(){
	cout<<"Do you want to play again? (1 for yes, 0 for no) ";
	string input;
	do{
		getline(cin, input);
		if(input=="1")
			return true;
		else if(input=="0")
			return false;
		else{
			cout<<"Error, please type 1 or 0: ";
		}
	}while(1);
}

int main(int argc, char** argv) {
	srand(time(NULL));

	bool mode = check_commandline(argc, argv);
	bool go_again = true;
	while(go_again){
		Game game = Game();
		build_game(&game);
		if(mode)
			cheat_view();//user typed true
		else
			normal_view();//user typed false
		go_again = again();
	}
	cout<<"Bye!"<<endl;
	return 0;
}
