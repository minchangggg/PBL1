#pragma once
#include "People.h"

using namespace std; 

class PI_student : public People {
    public:
        char *secondary_school_name;
        // Mã số học sinh
        int ID_student;
        // Hạnh kiểm 4 năm THCS
        int *conduct;
        // Học lực 4 năm THCS
        int *ranked_acdemic;
        // Xếp loại TN THCS
        int graduation_rate;
        // Giải:……..môn….…: trong kỳ thi chọn học sinh giỏi THCS 
        int *prize; 
        // Môn chuyên học sinh đăng kí xét tuyển 
        int subject;
        // Điểm thi Toán Văn Anh và môn chuyên
        float *result;
        // Điểm xét tuyển
        float score;

        PI_student( const char *secondary_school_name = "Sao Nam" , const int ID_student = 106220076 ) : People () {
            this -> secondary_school_name = new char[strlen(secondary_school_name)+1];
            strcpy( this->secondary_school_name , secondary_school_name );
            this -> ID_student = ID_student;
            this -> conduct = new int [10];
            this -> ranked_acdemic = new int [10]; 
            this -> graduation_rate = 1;
            this -> prize = new int [3];
            this -> subject = 1;
            this -> result = new float [4];
            this -> score = 1;
        }
        
        // ~ PI_student() {
        //     delete [] secondary_school_name;
        //     delete [] ID_student;
        //     delete [] conduct;
        //     delete [] ranked_acdemic;
        //     delete [] prize;
        //     delete [] result;
        // }

        friend istream &operator >> (istream &is, PI_student &student);
        friend ostream &operator << (ostream &os, PI_student &student);

};

istream &operator >> (istream &is, PI_student &student);
ostream &operator << (ostream &os, PI_student &student);

