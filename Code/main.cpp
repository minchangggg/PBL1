#include "Menu.h"

using namespace std;   

char *name_subject[] = {"Maths", "Physics", "Chemistry","Biology", "English", "IT", "Literature", "History", "Geography", "French", "Japanese"};
int num_student_subject[] = {60, 50, 35, 35, 35, 20, 25, 10, 10, 10, 10 };

Danhsach subject [11];
Danhsach failed_list;
int currentStudent = -1;

int main() {
    system("cls");
    //LoadData(subject);
    MainMenu(subject, failed_list, num_student_subject, name_subject, currentStudent);
    return 0;
}