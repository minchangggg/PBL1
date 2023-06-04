#pragma once
#include "PI_student.h"

using namespace std;  

struct Danhsach {
    PI_student *STUDENT;
    int num;
    Danhsach ( ) {
        STUDENT = NULL;
        num = 0;
    }
};

void add_student ( PI_student student , Danhsach &subject );

void sort_alphabet ( Danhsach &subject );
void SORT_ALPHABET ( Danhsach subject [] );

void sort_score ( Danhsach &subject );
void SORT_SCORE ( Danhsach subject [] );

bool first_round_condition ( PI_student student );
void pass_first_round ( Danhsach &list , Danhsach &failed_list );

bool second_round_condition ( PI_student student );
void pass_second_round ( Danhsach &list , Danhsach &failed_list );

void final_round_condition (Danhsach &subject , Danhsach &failed_list , int num_student_subject[] );
void pass_final_round ( Danhsach subject[] , Danhsach &failed_list , int num_student_subject[] );

float benchmark ( Danhsach &subject , Danhsach &failed_list , int num_student_subject[] );
void BENCHMARK ( Danhsach subject[] , Danhsach &failed_list , int num_student_subject[] , char *name_subject[] );