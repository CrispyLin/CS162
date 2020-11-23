#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game {
	private:
		Deck cards;
		Player players[2];
	public:
		// must have constructors, destructor, accessors, and mutators
		Game();
		Game(const Game& );
		Game& operator=(const Game&);

		void set_cards(Deck);
		Deck get_cards()const;

		void set_players(int, Player);
		Player get_player(int)const;

		//member functions
		void set_up();
		void print_deck();
		bool is_game_over();
		void calculate_results();//calculate results and print results
		Card go_fish(int);//randomly remove a card from deck and add to the player's hand
		bool user_round_cheat();
		bool user_round();
		bool computer_round();
		int get_user_option();
		bool user_get_cards_or_go_fish(int);
		bool computer_get_cards_or_go_fish(int);
		Card draw_card();
};

#endif // !GAME_H
