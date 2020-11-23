#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;
struct multdiv_entry {
    int mult;
    float div;
};

bool is_valid_dimensions(char* m, char* n);
void get_row(char row[20]);
void get_col(char col[20]);
multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** tables, int row, int col);
void delete_table(multdiv_entry** tables, int row);
void play_again(int& replay, char row[20], char col[20]);