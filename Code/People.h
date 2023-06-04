#pragma once
#include <bits/stdc++.h>

using namespace std;   

class People {
    public:
        char *name;
        bool gender;
        char *birthday;
        char *ethnicity;
        char *birthplace;
        int permanent_address;
        char *contact_address;
        char *phonenumber;

        People ( const char *name = "Phan Gia Bao", const char *birthday = "17-10-2004", const char *ethnicity = "Kinh", const char *birthplace = "BinhDinh", const char *contact_address = "390 Hoang Dieu", const char *phonenumber = "0902565457" ) {
            this -> name = new char[strlen(name)+1];
            strcpy( this->name , name );

            this -> gender = 0;

            this -> birthday = new char[strlen(birthday)+1];
            strcpy( this->birthday , birthday );

            this -> ethnicity = new char[strlen(ethnicity)+1];
            strcpy( this->ethnicity , ethnicity );

            this -> birthplace = new char[strlen(birthplace)+1];
            strcpy( this->birthplace , birthplace );

            this -> permanent_address = 1;

            this -> contact_address = new char[strlen(contact_address)+1];
            strcpy( this->contact_address , contact_address );

            this -> phonenumber = new char[strlen(phonenumber)+1];
            strcpy( this->phonenumber , phonenumber );   
        }
    
        // ~ People() {
        //     delete[]name;
        //     delete[]birthday;
        //     delete[]ethnicity;
        //     delete[]birthplace;
        //     delete[]contact_address;
        //     delete[]phonenumber;
        // }
};