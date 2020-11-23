#ifndef STUDENT_DB_H
#define STUDENT_DB_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

struct student {
    int id;
    string first_name;
    string last_name;
    string major;
};

int check_commandline_argument(int argc, char* argv[], ifstream& fin);
student * create_student_db(int num);
void populate_student_db_info(student *student_list, int num, ifstream &fin);
void sort_by_id(student *temp, int num);
void copy(student* temp, student *student_list, int num);
void sort_by_name(student *temp, int num);
void output(student *student_list, int num);
void delete_student_db_info(student **student_list, int num);

#endif