/******************************************************
** Program: wizard_catalog.cpp
** Author: Xinwei Lin
** Date: 04/05/2020
** Description: A program that can sort spells for different wizards
** Input: two file names, ID, password, choices
** Output: sorted spells
******************************************************/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "catalog.h"
using namespace std;


int main(int argc, char* argv[]) {
    handle_commandline_arguments(argc);//check if user provides enough commandline argument, if not, exit
    wizard* wizard_list = NULL;
    spellbook* spellbook_list = NULL;
    int num1 = 0, num2 = 0;
    int* numOfWizard = &num1;
    int* numOfBook = &num2;
    read_files(argv[1], argv[2], &wizard_list, &spellbook_list, numOfWizard, numOfBook);
    int user_number = user_login(wizard_list, *numOfWizard);
    if(user_number == -1){
        delete_info(&wizard_list, &spellbook_list, *numOfBook);
        exit(0);
    }
    welcome(wizard_list, user_number);//printing welcome infomation after successfully logged in
    sortingOptions(wizard_list[user_number].position_title, *numOfBook, spellbook_list);
    delete_info(&wizard_list, &spellbook_list, *numOfBook);
    cout<<"Bye!"<<endl;
    return 0;
}
