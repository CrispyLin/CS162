#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include "animal.h"
#include "monkey.h"
#include "sea_otter.h"
#include "sloth.h"
using namespace std;

class Zoo {
	private:
		Animal** animals;
		int num;
		int credit;
	public:
		//constructors
		Zoo();
		Zoo(Animal**, int, int);
		//copy constructor and assignment operator overload
		//Zoo(const Zoo&);
		//Zoo& operator=(const Zoo&);

		//destructor
		~Zoo();

		//setters and getters
		Animal** get_animals()const;
		void set_animals(Animal**);

		int get_num()const;
		void set_num(int);

		int get_credit()const;
		void set_credit(int);

		//member functions
		void remove_a_animal(int);
		void add_a_animal(Animal*);
		int generate_revenue();

		void birth(int);
		void animal_sick();
		void give_birth();
		int boom();
		int random_event();

		void buy_animal();
		void add_animal(int);
		int get_user_want_animal();

		void print_animals_info();
		bool if_user_have_enough_money(int);

		void sell_animal();
		void delete_animal(int);

		void grow();

		bool feeding(int, bool);

		void count_animals(int* baby_m, int* adult_m, int* baby_sea, int* adult_sea, int* baby_sl, int* adult_sl);
};

#endif