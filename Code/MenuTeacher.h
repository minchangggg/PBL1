#pragma once
#include "lequydon.h"

using namespace std;

void Edit_infor ( Danhsach subject [] );

void Output ( Danhsach subject [] , char *name_subject[] );

// Xuất danh sách học sinh đăng kí xét tuyển ( bao gồm điểm xét tuyển ) theo 11 môn chuyên ( theo chữ cái đầu của tên )
void Output_alphabet ( Danhsach subject [], char *name_subject[] );
void Output_score ( Danhsach subject [], char *name_subject[] );

// Xuất ds học sinh đậu theo từng môn chuyên (ds xét theo điểm từ cao xuống thấp)
void Output_passed_list ( Danhsach subject [] , Danhsach &failed_list, char *name_subject[], int num_student_subject[] );

// Xuất ds học sinh rớt theo từng môn chuyên (ds xét theo điểm từ cao xuống thấp)
void Output_failed_list ( Danhsach subject [] , Danhsach &failed_list , int num_student_subject[] );

void Menu_teacher_input( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [], char *name_subject[] );
void Menu_teacher_output ( Danhsach subject[], Danhsach &failed_list, int num_student_subject [], char *name_subject[] );

