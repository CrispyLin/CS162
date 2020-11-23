/******************************************************
** Program: Go_Fish.cpp
** Author: Xinwei Lin
** Date: 07/10/2020
** Description: A go fish game
** Input: 0-10 numbers and A J K Q
** Output: Cards, books
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

int main(int argc, char** argv) {
	//Create two objects with dynamic memory involved
	
	Card* ptr1 = new Card[10]; //making a card array
	for (int i = 0; i < 10; i++) {
		ptr1[i] = Card(1, 1);//initialize ptr1 with rank 1, suit 1
	}
	Hand h1(ptr1, 10);//using non-default constructor



	Card* ptr2 = new Card[10]; //making another card array
	for (int i = 0; i < 10; i++) {
		ptr2[i] = Card(10, 1); //initialize ptr2 with rank 10, suit 1
	}
	Hand h2(ptr2, 10);//using non-default constructor




	//printing values of h1
	cout << "Value of h1 before using assignment operator overload" << endl;
	for (int i = 0; i < 10; i++) {
		h1.get_cards()[i].print_card();
		cout << endl;
	}
	cout << endl;

	//printing values of h2
	cout << "Value of h2 before using assignment operator overload" << endl;
	for (int i = 0; i < 10; i++) {
		h2.get_cards()[i].print_card();
		cout << endl;
	}
	cout << endl;




	h2 = h1; //using assignment operator overload so that h2 will have same but identical values





	//printing values of h2
	cout << "Value of h2 after using assignment operator overload" << endl;
	for (int i = 0; i < 10; i++) {
		h2.get_cards()[i].print_card();
		cout << endl;
	}
	cout << endl;





	Hand h3 = h1; //using copy constructor






	//printing values of h3
	cout << "Value of h3" << endl;
	for (int i = 0; i < 10; i++) {
		h2.get_cards()[i].print_card();
		cout << endl;
	}

	return 0;
}
