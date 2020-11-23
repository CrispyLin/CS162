#include "multdiv.h"
using namespace std;
bool is_valid_dimensions(char* m, char* n){
    int rows = atoi(m);
    int cols = atoi(n);
    if(rows==0 || cols==0){
        return false;
    }
    return true;
}

void get_row(char row[20]){
    cout<<"Enter an integer greater than 0 for row: ";
    cin >> row;
    return;
}

void get_col(char col[20]){
    cout<<"Enter an integer greater than 0 for col: ";
    cin >> col;
    return;
}

multdiv_entry** create_table(int row, int col){
    multdiv_entry** table = new multdiv_entry * [row];
    for (int i = 0; i < row; i++) {
        table[i] = new multdiv_entry [col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            table[i][j].mult = (i+1) * (j+1);
            table[i][j].div = (float)(i+1) / (j+1);
            table[i][j].div = round(table[i][j].div * 100) / 100;
        }
    }
    return table;
}

void print_table(multdiv_entry** tables, int row, int col) {
    cout << "Multiplication Table :" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << tables[i][j].mult << " ";
        }
        cout << endl;
    }
    cout << "Division Table :" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << tables[i][j].div << " ";
        }
        cout << endl;
    }
}

void delete_table(multdiv_entry** tables, int row) {
    for (int i = 0; i < row; i++) {
        delete [] tables[i];
    }
    delete [] tables;
}

void play_again(int& replay, char row[20], char col[20]) {
    cout << "Would you like to see a different size matrix (0-no, 1-yes) ? ";
    char input[20];
    cin >> input;
    if (atoi(input) == 1) {
        replay = 1;
        get_row(row);
        get_col(col);
    }
    else {
        replay = 0;
    }
    return;
}

