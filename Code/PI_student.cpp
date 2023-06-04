#include "PI_student.h"

using namespace std;   

istream &operator>>(istream &is, PI_student &student) {

    cout << "Enter student's name: ";
    fflush(stdin);
    is.getline(student.name,30);

    cout << "\nEnter 0 for male and 1 for female. "; 
    cout << "\nEnter student's gender: "; 
    is >> student.gender;
    
    cout << "\nEnter student's day of birth: ";
    fflush(stdin);
    is.getline(student.birthday,30);

    cout << "Enter student's ethnic group: ";
    fflush(stdin);
    is.getline(student.ethnicity,30);

    cout << "Enter student's birthplace: ";
    fflush(stdin);
    is.getline(student.birthplace,30);

    do {
    cout << "\nEnter number 1 for DANANG and number 2 for QUANGNAM";
    cout << "\nEnter student's permanent address: ";
    is >> student.permanent_address;
        if ( student.permanent_address != 1 && student.permanent_address != 2 ) {
            cout << "The information is invalid. Please re-enter.";
        }
    } while ( student.permanent_address != 1 && student.permanent_address != 2 );
    
    cout<<"\nEnter student's contact address: ";
    fflush(stdin);
    is.getline(student.contact_address,30);
        
    cout<<"Enter student's phonenumber: ";
    fflush(stdin);
    is.getline(student.phonenumber,30);

    cout<<"Enter name of secondary school: ";
    fflush(stdin);
    is.getline(student.secondary_school_name,30);

    cout<<"Enter student ID: ";
    is >> student.ID_student;

    cout << "\nEnter 1 for VERY GOOD, 2 for GOOD and 3 for AVERAGE";
    for ( int i = 6; i <= 9 ; i++ ) {
        cout << "\nEnter conduct classification at grade "<<i<<": ";
        is >> student.conduct[i];

        cout << "Enter ranked acdemic at grade "<<i<<": ";
        is >> student.ranked_acdemic[i];
    }

    do {
        cout << "\nEnter number 1 for VERY GOOD, 2 for GOOD and 3 for AVERAGE";
        cout << "\nEnter graduation rating at secondary school: ";
        is >> student.graduation_rate;
        if ( student.graduation_rate != 1 && student.graduation_rate != 2 && student.graduation_rate != 3 ) {
            cout << "The information is invalid. Please re-enter.";
        }
    } while ( student.graduation_rate != 1 && student.graduation_rate != 2 && student.graduation_rate != 3);

    cout << "\n1. Maths\n" << "2. Physics\n" << "3. Chemistry\n" << "4. Biology\n" << "5. English\n";
    cout << "6. IT\n" << "7. Literature\n" << "8. History\n" << "9. Geography\n" << "10. French\n" << "11. Japanese\n";
    cout << "Choose special subject student enrolled: ";
    is >> student.subject;

    // Gán giá trị = 0;
    for ( int i = 0; i < 4 ; i++ ) {
        student.prize[i] = 0;
    }
    /*Nhập các giải thưởng đã nhận cấp quốc gia và cấp thành phố các môn chuyên mà mình đã đăng kí*/
    cout << "\n1. National level" << "\n2. City level" << "\n3. 1 and 2" << "\n4. No prize";
    cout << "\nChoose prize level that fit special subject student have gained: ";
    cin >> student.prize[0];

    if ( student.prize[0] == 2 ) {  
                cout << "\n1. First prize" << "\t2. Second prize" << "\t3. Third prize" << "\t4. Honorable mention";
                cout << "\nEnter prize student competed in city level competition: ";
                is >> student.prize[1];
    }
    // Nhập giải thưởng tin học trẻ, KHKT: giải cấp thành phố về Tin học trẻ khi đăng kí vào môn chuyên Tin học và Khoa học kĩ thuật ( đv môn chuyên tương ứng)
    // Xét cả tin học trẻ và KHKT ( chỉ xét đv hs thi chuyên tin )
    if ( student.subject == 6 ) {
        cout << "\n0. No" << "\t1. Yes ";
        cout << "\nDid student gain IT for youth or Science and Engineering's prize: ";
        is >> student.prize[2];

        if ( student.prize[2] == 1) {
            cout << "\n1. First prize" << "\t2. Second prize" << "\t3. Third prize" << "\t4. Honorable mention";
            cout << "\nEnter the higest prize that student competed in these competition: ";
            is >> student.prize[2];
        }
    }
    
    // Xét KHKT (đối vs các môn chuyên trừ chuyên tin)
    else { 
        cout << "\n0. No" << "\t1. Yes ";
        cout << "\nDid student gain Science and Engineering's prize that fit special subject? ";
        is >> student.prize[2];

        if ( student.prize[2] == 1 ) {
            cout << "\n1. First prize" << "\t2. Second prize" << "\t3. Third prize" << "\t4. Honorable mention";
            cout << "\nEnter prize student competed in competition: ";
            is >> student.prize[2];
        }
    }

    cout << "\n___ENTER THE EXAM RESULT___";
    cout << "\nEnter mark in maths: ";
    is >> student.result[0];
    cout << "Enter mark in literature: ";
    is >> student.result[1];
    cout << "Enter mark in english: ";
    is >> student.result[2];
    cout << "Enter mark in special subject: ";
    is >> student.result[3];

    student.score = student.result[0] + student.result[1] + student.result[2] + 3 * student.result[3];

}

ostream &operator << (ostream &os, PI_student &student) {
    os << "\nname: " << student.name;
    os << "\ngender: " << student.gender;
    os << "\nbirthday: " << student.birthday;
    os << "\nethnicity: " << student.ethnicity;
    os << "\nbirthplace: " << student.birthplace;
    os << "\npermanent_address: " << student.permanent_address;
    os << "\ncontact_address: " << student.contact_address;
    os << "\nphonenumber: " << student.phonenumber;
    os << "\nschoolname: " << student.secondary_school_name;
    os << "\nID_student: " << student.ID_student;
    for ( int i = 6; i <= 9 ; i++ ) {
        cout << "\nconduct classification at grade "<<i<<": " << student.conduct[i];
        cout << "\nranked acdemic at grade "<<i<<": " << student.ranked_acdemic[i];
    }    
    os << "\ngraduation_rate: " << student.graduation_rate;
    os << "\nsubject: " << student.subject;
    for ( int i = 0; i < 4 ; i++ ) {
        cout << "\nprize ["<<i<<"]: " << student.prize[i];
    }
    os << "\nMark in maths: " << student.result[0];
    os << "\nMark in literature: " << student.result[1];
    os << "\nMark in english: " << student.result[2];
    os << "\nMark in special subject: " << student.result[3];

    os << "\nEntrance exam result: " << student.score;
}