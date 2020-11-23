#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "student_db.h"
using namespace std;

int main(int argc, char* argv[]) {
    ifstream fin;
    int num_student = check_commandline_argument(argc, argv, fin);
    student* student_list = create_student_db(num_student);
    populate_student_db_info(student_list, num_student, fin);
    output(student_list, num_student);
    delete_student_db_info(&student_list, num_student);
    fin.close();
}