#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "catalog.h"
using namespace std;

void handle_commandline_arguments(int argc) {
    if (argc != 3) {
        cout << "Commandline arguments Error!" << endl;
        exit(1);
    }
    return;
}

wizard* read_wizard(char* file1, int *num) {
    ifstream fin;
    fin.open(file1);
    if (!fin.is_open()) {
        // The file could not be opened
        cout << "The file "<<file1<<" cannot be open" << endl;
        exit(1);
    }
    wizard* wizard_list = NULL; //make a pointer set it to NULL I will use it to store the address of the wizard array later
    int numOfWizard = -1; //an int to hold how many wizards are in the file
    fin >> numOfWizard; //read how many wizard in file
    *num = numOfWizard;
    wizard_list = new wizard[numOfWizard];
    
    for (int i = 0; i < numOfWizard; i++) {
        fin >> wizard_list[i].name >> wizard_list[i].id >> wizard_list[i].password >> wizard_list[i].position_title >> wizard_list[i].beard_length;
    }

    fin.close();
    return wizard_list;
}

float calculate_avg_success_rate(spell* s, int num) {
    float total = 0.0;
    for (int i = 0; i < num; i++) {
        total += s[i].success_rate;
    }
    return total / num;
}

spellbook* create_spellbooks(int num) {
    spellbook* spellbook_list = new spellbook[num];
    return spellbook_list;
}

spell* create_spells(int num) {
    spell* s = new spell[num];
    return s;
}

void populate_spell_data(spell* s, int num, ifstream& fin) {
    for (int i = 0; i < num; i++) {
        fin >> s[i].name >> s[i].success_rate >> s[i].effect;
    }
    return;
}

void populate_spellbook_data(spellbook* spellbook_list, int num, ifstream& fin) {
    for (int i = 0; i < num; i++) {
        fin >> spellbook_list[i].title >> spellbook_list[i].author >> spellbook_list[i].num_pages >> spellbook_list[i].edition >> spellbook_list[i].num_spells;
        spellbook_list[i].s = create_spells(spellbook_list[i].num_spells);
        populate_spell_data(spellbook_list[i].s, spellbook_list[i].num_spells, fin);
        spellbook_list[i].avg_success_rate = calculate_avg_success_rate(spellbook_list[i].s, spellbook_list[i].num_spells);//calculating avg success rate
    }
    return;
}

//the function reads two files and create two arrays to store data
void read_files(char* file1, char* file2, wizard** wizard_list, spellbook** spellbook_list, int* numOfWizard, int* numOfBook) {
    //read wizard file
    *wizard_list = read_wizard(file1, numOfWizard);

    //read spellbook file down below
    ifstream fin;
    fin.open(file2);
    if (!fin.is_open()) {
        // The file could not be opened
        cout << "The file " << file2 << " cannot be open" << endl;
        exit(1);
    }
    fin >> *numOfBook; //read how many spell books are in the file
    *spellbook_list = create_spellbooks(*numOfBook);
    populate_spellbook_data(*spellbook_list, *numOfBook, fin);
    fin.close();
    return;
}


void delete_info(wizard** wizard_list,spellbook** spellbook_list, int num_book) {
    if(wizard_list!=NULL){
        delete[](*wizard_list);
    }

    if(spellbook_list!=NULL){
        for (int i = 0; i < num_book; i++) {;
            delete[](*spellbook_list)[i].s;
        }
        delete[](*spellbook_list);
    }

    return;
}

void print(wizard* wizard_list, spellbook* spellbook_list, int* numOfWizard, int* numOfBook) {
    for (int i = 0; i < *numOfBook; i++) {
        cout << spellbook_list[i].title << " " << spellbook_list[i].author << " " << spellbook_list[i].num_pages << " " << spellbook_list[i].edition << " " << spellbook_list[i].num_spells << " " << endl;
        for (int j = 0; j < spellbook_list[i].num_spells; j++) {
            cout << spellbook_list[i].s[j].name <<""<< spellbook_list[i].s[j].success_rate << " " << spellbook_list[i].s[j].effect << endl;
        }
        cout << endl;
    }
}

int get_id(){
    do{
        string input = "";
        cout<<"Please enter your id: ";
        getline(cin, input);
        if(input == ""){
            cout<<"ID must be all integers!"<<endl;
            continue;
        }
        for(int i=0;i<input.length();i++){
            if(int(input[i])<48 || int(input[i])>57){
                cout<<"ID must be all integers!"<<endl;
                break;
            }
            else if(i==input.length()-1){
                return atoi(input.c_str());
            }
        }
    }while(1);
}

string get_password(){
    do{
        string input = "";
        cout<<"Please enter your password: ";
        getline(cin, input);
        if(input == ""){
            cout<<"Please enter something :)"<<endl;
            continue;
        }
        return input;
    }while(1);
}

int search_wizard(wizard* wizard_list, int id, string password, int numOfWizard){
    for(int i=0; i<numOfWizard; i++){
        if(id == wizard_list[i].id){
            if(password == wizard_list[i].password){
                return i;
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}

int user_login(wizard* wizard_list, int numOfWizard) {
    int count = 0;
    int num=-1;
    do {
        int id = get_id();//get id from user
        string password = get_password(); //get password from user
        num = search_wizard(wizard_list, id, password, numOfWizard);//search wizard list based on id and password user provided
        if (num>=0) { // if search_wizard find the corresponding wizard, it will return non-zero value, otherwisem it returns -1
            cout<<endl;
            return num;
        }
        else {
            count++;
            cout<<"Incorrect id or password"<<endl;
            if(count == 3){
                cout<<"You have failed 3 times to login in, the program will exit"<<endl;
                return -1;
            }
        }
    } while (count < 3);//user can type wrong id and password up to 3 times
}

void welcome(wizard* wizard_list, int num){
    cout<<"Welcome "<<wizard_list[num].name<<endl;
    cout<<"ID: "<<wizard_list[num].id<<endl;
    cout<<"Status: "<< wizard_list[num].position_title<<endl;
    cout<<"Beard Length: "<< wizard_list[num].beard_length<<endl<<endl;
    return;
}

void display_options(){
    cout<<"Which option would you like to choose?"<<endl;
    cout<<"1. Sort spellbooks by number of pages"<<endl;
    cout<<"2. Group spells by their effect"<<endl;
    cout<<"3. Sort spellbooks by average success rate"<<endl;
    cout<<"4. Quit "<<endl;
    return;
}

int get_option(){
    while(1){
        cout<<"Your choice: ";
        string input;
        getline(cin,input);
        int int_input = atoi(input.c_str());
        if(int_input==1||int_input==2||int_input==3||int_input==4){
            cout<<endl;
            return int_input;
        }else{
            cout<<"Error, please re-enter"<<endl;
        }
    }
}

void copy_spellbook(int numOfBook, spellbook* spellbook_list, spellbook* temp){
    for(int i=0;i<numOfBook;i++){
        temp[i].title = spellbook_list[i].title;
        temp[i].num_pages = spellbook_list[i].num_pages;
        temp[i].num_spells = spellbook_list[i].num_spells;
        temp[i].avg_success_rate = spellbook_list[i].avg_success_rate;
        temp[i].s = new spell [temp[i].num_spells];
        for(int j=0;j<temp[i].num_spells;j++){
            temp[i].s[j].effect = spellbook_list[i].s[j].effect;
            temp[i].s[j].name = spellbook_list[i].s[j].name;
            temp[i].s[j].success_rate = spellbook_list[i].s[j].success_rate;
        }
    }
    return;
}

bool no_bad_spells(spell* s, int num){
    for(int i=0;i<num;i++){
        if(s[i].effect=="death"||s[i].effect=="posion")
            return false;
    }
    return true;
}


void print_screen_1(string position_title, spellbook* temp, int num){
    if(position_title=="Student"){
        for(int i=0;i<num;i++){
            if(no_bad_spells(temp[i].s, temp[i].num_spells)){
                cout<<temp[i].title<<" "<<temp[i].num_pages<<endl;
            }
        }
    }else{
        for(int i=0;i<num;i++){
            cout<<temp[i].title<<" "<<temp[i].num_pages<<endl;
        }
    }
    cout<<endl;
}

string get_file_name(){
    cout<<"Please provide desired filename: ";
    string filename;
    getline(cin,filename);
    return filename;
}

void print_file_1(string position_title, spellbook* temp, int num){
    ofstream fout;
    string file = get_file_name();
    fout.open(file.c_str(), ios::app);//open a file with appending mode

    if(position_title=="Student"){
        for(int i=0;i<num;i++){
            if(no_bad_spells(temp[i].s, temp[i].num_spells)){
                fout<<temp[i].title<<" "<<temp[i].num_pages<<endl;
            }
        }
    }else{
        for(int i=0;i<num;i++){
            fout<<temp[i].title<<" "<<temp[i].num_pages<<endl;
        }
    }
    cout<<"Appended requested information to file."<<endl<<endl;
    fout.close();
    return;
}

int get_print_method(){
    do{
        cout<<"How would you like the information displayed?"<<endl;
        cout<<"1. Print to screen (Press 1)\n2. Print to file (Press 2)\nYour Choice: ";
        string input = "";
        getline(cin,input);
        if(atoi(input.c_str())==1||atoi(input.c_str())==2){
            cout<<endl;
            return atoi(input.c_str());
        }else
            cout<<"Error! Please re-enter."<<endl;
        
    }while(1);
}

void sort_by_numberOfPages(string position_title, int numOfBook, spellbook* spellbook_list){
    //sorting first, when printing, igonre those books containing death or poison spells
    spellbook temp[numOfBook];
    //create a temp array that have the same value as spellbook_list
    copy_spellbook(numOfBook, spellbook_list, temp);
    //sort 
    for(int i=0;i<numOfBook;i++){
        for(int j=i+1;j<numOfBook;j++){
            if(temp[i].num_pages>temp[j].num_pages){
                spellbook tmp;
                tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }
    int method = get_print_method();
    if(method == 1)
        print_screen_1(position_title, temp, numOfBook);
    else
        print_file_1(position_title, temp, numOfBook);

    for(int i=0;i<numOfBook;i++){
        delete [] temp[i].s;
    }
    
    return;
}

void copy_spells(int* count, spell* spells, spellbook* spellbook_list, int numOfBook, string effect){
    for(int i=0;i<numOfBook;i++){
        for(int j=0;j<spellbook_list[i].num_spells;j++){
            if(spellbook_list[i].s[j].effect==effect){
                spells[*count].effect = spellbook_list[i].s[j].effect;
                spells[*count].name = spellbook_list[i].s[j].name;
                (*count)++;
            }
        }
    }
    return;
}

void sort_spells(int* count, spell* spells, spellbook* spellbook_list, int numOfBook){
    //copying memory_loss first, followed by fire, bubble, poison, and death.
    copy_spells(count,spells,spellbook_list,numOfBook,"memory_loss");
    copy_spells(count,spells,spellbook_list,numOfBook,"fire");
    copy_spells(count,spells,spellbook_list,numOfBook,"bubble");
    copy_spells(count,spells,spellbook_list,numOfBook,"posion");
    copy_spells(count,spells,spellbook_list,numOfBook,"death");
    return;
}

void print_screen_2(string position_title, spell* spells, int count){
    for(int i=0;i<count;i++){
        if(spells[i].effect=="posion"||spells[i].effect=="death"){
            cout<<endl;
            return;
        }
        cout<<spells[i].effect<<" "<<spells[i].name<<endl;
    }
    cout<<endl;
}

void print_file_2(string position_title, spell* spells, int count){
    ofstream fout;
    string file = get_file_name();
    fout.open(file.c_str(), ios::app);//open a file with appending mode

    if(position_title=="Student"){
        for(int i=0;i<count;i++){
            if(spells[i].effect=="posion"||spells[i].effect=="death"){
                cout<<endl;
                return;
            }
            fout<<spells[i].effect<<" "<<spells[i].name<<endl;
        }
    }else{
        for(int i=0;i<count;i++){
            fout<<spells[i].effect<<" "<<spells[i].name<<endl;
        }
    }
    cout<<"Appended requested information to file."<<endl<<endl;
    fout.close();
    return;
}

spellbook* sort_by_effects(string position_title, int numOfBook, spellbook* spellbook_list){
    int count=0;
    spell spells[10000];
    sort_spells(&count, spells, spellbook_list, numOfBook);//this function is going to copy all spells in order in the spell array
    
    int method = get_print_method();
    if(method == 1)
        print_screen_2(position_title, spells, count);
    else
        print_file_2(position_title, spells, count);
}

void print_screen_3(string position_title, spellbook* temp, int num){
    if(position_title=="Student"){
        for(int i=0;i<num;i++){
            if(no_bad_spells(temp[i].s, temp[i].num_spells)){
                cout<<temp[i].title<<" "<<temp[i].avg_success_rate<<endl;
            }
        }
    }else{
        for(int i=0;i<num;i++){
            cout<<temp[i].title<<" "<<temp[i].avg_success_rate<<endl;
        }
    }
    cout<<endl;
}

void print_file_3(string position_title, spellbook* temp, int num){
    ofstream fout;
    string file = get_file_name();
    fout.open(file.c_str(), ios::app);//open a file with appending mode

    if(position_title=="Student"){
        for(int i=0;i<num;i++){
            if(no_bad_spells(temp[i].s, temp[i].num_spells)){
                fout<<temp[i].title<<" "<<temp[i].avg_success_rate<<endl;
            }
        }
    }else{
        for(int i=0;i<num;i++){
            fout<<temp[i].title<<" "<<temp[i].avg_success_rate<<endl;
        }
    }
    cout<<"Appended requested information to file."<<endl<<endl;
    fout.close();
    return;
}

void sort_by_success_rate(string position_title, int numOfBook, spellbook* spellbook_list){
    //sorting first, when printing, igonre those books containing death or poison spells
    spellbook temp[numOfBook];
    //create a temp array that have the same value as spellbook_list
    copy_spellbook(numOfBook, spellbook_list, temp);
    //sort 
    for(int i=0;i<numOfBook;i++){
        for(int j=i+1;j<numOfBook;j++){//bubble sort
            if(temp[i].avg_success_rate>temp[j].avg_success_rate){
                spellbook tmp;
                tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }
    int method = get_print_method();
    if(method == 1)
        print_screen_3(position_title, temp, numOfBook);
    else
        print_file_3(position_title, temp, numOfBook);

    for(int i=0;i<numOfBook;i++){
        delete [] temp[i].s;
    }
    
    return;
}

void sortingOptions(string position_title, int numOfBook, spellbook* spellbook_list){
    while(1){
        display_options();
        int option = get_option();

        switch(option){
            case 1: sort_by_numberOfPages(position_title, numOfBook, spellbook_list); break;
            case 2: sort_by_effects(position_title, numOfBook, spellbook_list); break;
            case 3: sort_by_success_rate(position_title, numOfBook, spellbook_list); break;
            case 4: return; break;
        }
    }
}
