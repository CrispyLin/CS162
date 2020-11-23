#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

struct wizard {
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

struct spell {
    string name;
    float success_rate;
    string effect;
};

struct spellbook {
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell* s;
};

void handle_commandline_arguments(int argc);
wizard* read_wizard(char* file1, int *num);
float calculate_avg_success_rate(spell* s, int num);
spellbook* create_spellbooks(int num);
spell* create_spells(int num);
void populate_spell_data(spell* s, int num, ifstream& fin);
void populate_spellbook_data(spellbook* spellbook_list, int num, ifstream& fin);
void read_files(char* file1, char* file2, wizard** wizard_list, spellbook** spellbook_list, int* numOfWizard, int* numOfBook);
void delete_info(wizard** wizard_list,spellbook** spellbook_list, int num_book);
void print(wizard* wizard_list, spellbook* spellbook_list, int* numOfWizard, int* numOfBook);
int get_id();
string get_password();
int search_wizard(wizard* wizard_list, int id, string password, int numOfWizard);
int user_login(wizard* wizard_list, int numOfWizard);
void welcome(wizard* wizard_list, int num);
void display_options();
int get_option();
void copy_spellbook(int numOfBook, spellbook* spellbook_list, spellbook* temp);
bool no_bad_spells(spell* s, int num);
void print_screen_1(string position_title, spellbook* temp, int num);
string get_file_name();
void print_file_1(string position_title, spellbook* temp, int num);
int get_print_method();
void sort_by_numberOfPages(string position_title, int numOfBook, spellbook* spellbook_list);
void copy_spells(int* count, spell* spells, spellbook* spellbook_list, int numOfBook, string effect);
void sort_spells(int* count, spell* spells, spellbook* spellbook_list, int numOfBook);
void print_screen_2(string position_title, spell* spells, int count);
void print_file_2(string position_title, spell* spells, int count);
spellbook* sort_by_effects(string position_title, int numOfBook, spellbook* spellbook_list);
void print_screen_3(string position_title, spellbook* temp, int num);
void print_file_3(string position_title, spellbook* temp, int num);
void sort_by_success_rate(string position_title, int numOfBook, spellbook* spellbook_list);
void sortingOptions(string position_title, int numOfBook, spellbook* spellbook_list);

#endif