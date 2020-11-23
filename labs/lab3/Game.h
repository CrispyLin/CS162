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

		bool is_game_over();
};

#endif // !GAME_H
