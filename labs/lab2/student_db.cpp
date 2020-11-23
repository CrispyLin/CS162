#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "student_db.h"
using namespace std;

int check_commandline_argument(int argc, char* argv[], ifstream& fin){
    if(argc!=2){
        cout<<"Error! Please give enough commandline arguments"<<endl;
        exit(1);
    }
    fin.open(argv[1]);
    if (!fin.is_open()) {
        // The file could not be opened
        cout << "The file "<<argv[1]<<" cannot be open" << endl;
        string file;
        while(1){
            cout<<"Type your input file name: ";
            cin >> file;
            fin.open(file.c_str());
            if (!fin.is_open()) {
                // The file could not be opened
                cout << "The file "<<file<<" cannot be open" << endl;
            }else{
                break;
            }
        }
    }
    int num = 0;
    fin>>num;
    return num;
}

student * create_student_db(int num){
    student* student_list = new student [num];
    return student_list;
}

void populate_student_db_info(student *student_list, int num, ifstream &fin){
    for(int i=0;i<num;i++){
        fin>>student_list[i].id>>student_list[i].first_name>>student_list[i].last_name>>student_list[i].major;
    }
    return;
}

void sort_by_id(student *temp, int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(temp[i].id>temp[j].id){
                student tmp;
                tmp.first_name = temp[i].first_name;
                tmp.last_name = temp[i].last_name;
                tmp.major = temp[i].major;
                tmp.id = temp[i].id;

                temp[i].first_name = temp[j].first_name;
                temp[i].last_name = temp[j].last_name;
                temp[i].major = temp[j].major;
                temp[i].id = temp[j].id;

                temp[j].first_name = tmp.first_name;
                temp[j].last_name = tmp.last_name;
                temp[j].major = tmp.major;
                temp[j].id = tmp.id;
            }
        }
    }
}

void copy(student* temp, student *student_list, int num){
    for(int i=0;i<num;i++){
        temp[i].id = student_list[i].id;
        temp[i].first_name = student_list[i].first_name;
        temp[i].last_name = student_list[i].last_name;
        temp[i].major = student_list[i].major;
    }
    return;
}

void sort_by_name(student *temp, int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(temp[i].last_name>temp[j].last_name){
                student tmp;
                tmp.first_name = temp[i].first_name;
                tmp.last_name = temp[i].last_name;
                tmp.major = temp[i].major;
                tmp.id = temp[i].id;

                temp[i].first_name = temp[j].first_name;
                temp[i].last_name = temp[j].last_name;
                temp[i].major = temp[j].major;
                temp[i].id = temp[j].id;

                temp[j].first_name = tmp.first_name;
                temp[j].last_name = tmp.last_name;
                temp[j].major = tmp.major;
                temp[j].id = tmp.id;
            }
        }
    }
}



void output(student *student_list, int num){
    ofstream fout;
    string file = "output.txt";
    fout.open(file.c_str());//open a file with appending mode

    //sorting students by id and output them into file
    student temp1[num];
    copy(temp1, student_list, num);
    sort_by_id(temp1, num);
    fout<<"Sorted students by ID number"<<endl;
    for(int i=0;i<num;i++){
        fout<<temp1[i].id<<" "<<temp1[i].first_name<<" "<<temp1[i].last_name<<" "<<temp1[i].major<<endl;
    }
    fout<<endl;

    //sorting students by last name and output them into file
    student temp2[num];
    copy(temp2, student_list, num);
    sort_by_name(temp1, num);
    fout<<"Sorted students by last name"<<endl;
    for(int i=0;i<num;i++){
        fout<<temp1[i].id<<" "<<temp1[i].first_name<<" "<<temp1[i].last_name<<" "<<temp1[i].major<<endl;
    }
    fout<<endl;

    //sorting students by unique majors and output them into file
    fout<<"Sorted students by majors"<<endl;
    for(int i=0;i<num;i++){
        if(student_list[i].major=="Political_Science")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    for(int i=0;i<num;i++){
        if(student_list[i].major=="Criminal_Justice")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    for(int i=0;i<num;i++){
        if(student_list[i].major=="Law")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    for(int i=0;i<num;i++){
        if(student_list[i].major=="Public_and_Environmental_Affairs")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    for(int i=0;i<num;i++){
        if(student_list[i].major=="General_Sciences")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    for(int i=0;i<num;i++){
        if(student_list[i].major=="Communications")
            fout<<student_list[i].id<<" "<<student_list[i].first_name<<" "<<student_list[i].last_name<<" "<<student_list[i].major<<endl;
    }
    fout.close();
    return;
}

void delete_student_db_info(student **student_list, int num){
    delete [] (*student_list);
}
