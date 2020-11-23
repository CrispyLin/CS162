#include "multdiv.h"
int main(int argc, char* argv[]) {
    char row[20];
    char col[20];
    int replay = 0;
    strcpy(row, argv[1]);
    strcpy(col, argv[2]);
    do {
        while (is_valid_dimensions(row, col) == false) {
            cout<<"Invalid size(s)!!!"<<endl;
            get_row(row);
            get_col(col);
        }
        multdiv_entry** table = create_table(atoi(row), atoi(col));
        print_table(table, atoi(row), atoi(col));
        delete_table(table, atoi(row));
        play_again(replay, row, col);
    } while (replay == 1);

    return 0;
}