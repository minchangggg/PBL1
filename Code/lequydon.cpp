#include "lequydon.h"

using namespace std;

// resize mảng động và thêm hs vào mảng của môn chuyên tương ứng 
void add_student ( PI_student student , Danhsach &subject ) {
    if (subject.num == 0) {
        subject.STUDENT = new PI_student[1];
        subject.STUDENT [subject.num] = student;
        subject.num ++;
        return;
    }

    PI_student temp [ subject.num ]; 
    for ( int i = 0 ; i < subject.num ; i++ ) {
        temp [i] = subject.STUDENT[i];
    }
    
    delete [] subject.STUDENT;
    subject.STUDENT = new PI_student [subject.num + 1];
    for ( int i = 0 ; i < subject.num ; i++ ) {
        subject.STUDENT[i] = temp [i];
    }

    subject.STUDENT [subject.num] = student;
    subject.num ++;
}

void Input ( Danhsach &list , Danhsach subject [] ) {

    // Danhsach subject [11] là mảng tĩnh 1 chìu gồm 11 danh sách, mỗi danh sách chứa 1 mảng động thông tin 
                                                                // học sinh dạng PI_student *STUDENT
    for ( int i = 0 ; i < list.num ; i++ ) {
        cin >> list.STUDENT[i];
        add_student ( list.STUDENT[i] , subject[list.STUDENT[i].subject - 1] );
    }
}

bool compare ( char *arrA , char *arrB ) {
    for ( int i = 0 ; i < min ( strlen( arrA ) , strlen ( arrB ) ) ; i++) {
        if ( arrA[i] < arrB [i] ) {
            return true;
        }
        else if ( arrA[i] > arrB [i] ) {
            return false;
        }
    }
    if ( strlen( arrA ) > strlen ( arrB ) ) {
        return false;
    }

    return true;

}

void sort_alphabet ( Danhsach &subject ) {
    char *first_name [subject.num];
    for ( int i = 0 ; i < subject.num ; i++ ) {
        first_name [i] = new char [ strlen(subject.STUDENT[i].name) ];
    }

    for ( int i = 0 ; i < subject.num ; i++ ) {
        for ( int j = strlen(subject.STUDENT[i].name) - 1 ; j >= 0 ; j-- ) {
            if ( subject.STUDENT[i].name[j] != ' ' ) { 
                for ( int k = strlen(subject.STUDENT[i].name) ; k > 0 ; k-- ) {
                    first_name[i][k] = first_name[i][k-1];
                }
                first_name[i][0] = subject.STUDENT[i].name[j];
            }
            else break;
        }
    }

    for ( int i = 0 ;  i < (subject.num - 1) ; i++ ) {
        for ( int j = i + 1 ; j < subject.num ; j++ ) {
            if ( compare ( first_name[i] , first_name[j] ) == false ) {
                swap ( first_name[i] , first_name[j] );
                swap ( subject.STUDENT[i] , subject.STUDENT[j] );
            }
        }
    }
}

void SORT_ALPHABET ( Danhsach subject [] ) {
    for ( int i = 0 ; i < 11 ; i++ ) {
        sort_alphabet ( subject[i] );
    }
}

void sort_score ( Danhsach &subject ) {
    if ( subject.num == 0 ) return;

    for ( int i = 0 ; i < (subject.num-1) ; i++ ) {
        for ( int j = i + 1 ; j < subject.num ; j++ ) {
            if ( subject.STUDENT[i].score < subject.STUDENT[j].score ) {
                swap ( subject.STUDENT[i], subject.STUDENT[j] );
            }
        }
    }
}

void SORT_SCORE ( Danhsach subject [] ) {
    for ( int i = 0 ; i < 11 ; i++ ) {       
        sort_score ( subject[i] );
    }
}

bool first_round_condition ( PI_student student ) {

    // Xếp loại hạnh kiểm, học lực các lớp cấp THCS từ khá trở lên.
    for ( int i = 6; i <= 9 ; i++ ) {
        if ( student.conduct[i] == 3 || student.ranked_acdemic[i] == 3 ) {
        return false;
        }
    }

    // Xếp loại tốt nghiệp THCS từ khá trở lên.
    if ( student.graduation_rate == 3 ) {
        return false;
    }

    return true;
}

void pass_first_round ( Danhsach &list , Danhsach &failed_list ) {
    Danhsach passed_list;
    for ( int i = 0 ; i < list.num ; i++ ) {
        if ( first_round_condition ( list.STUDENT[i] ) == true ) {
            add_student ( list.STUDENT[i] , passed_list );
            // cout << " \n\t\tSTUDENT "<< i + 1 <<" PASS PART 1 ";
        }
        else {
            add_student ( list.STUDENT[i] , failed_list );
        }
    }
    list = passed_list;
}

int mark_in_second_round ( PI_student student ) {
    // Đạt giải học sinh giỏi quốc gia, quốc tế hoặc đạt giải học sinh giỏi thành phố các bộ môn văn hóa lớp 9
    int criteria1 = 0;
    if ( student.prize[0] == 1 || student.prize[0] == 3 || student.prize[1] == 1 ) {
        criteria1 = 40;
    }
    else if ( student.prize[1] == 2 ) {
        criteria1 = 30;
    }
    else if ( student.prize[1] == 3 ) {
        criteria1 = 20;
    }
    else if ( student.prize[1] == 4 ) {
        criteria1 = 10;
    }

    // Xếp loại học lực 4 năm cấp THCS
    int criteria2 = 0;
    int verygood = 0, good = 0;
    for ( int i = 6; i <= 9 ; i++ ) { 
        if (student.ranked_acdemic[i] == 1 ) verygood ++;
        else good++;
    }

    if ( verygood == 4 ) criteria2 = 30;
    else if ( verygood == 3 && good == 1 ) criteria2 = 25;  
    else if ( verygood == 2 && good == 2 ) criteria2 = 20;
    else if ( verygood == 1 && good == 3 ) criteria2 = 15; 

    // Xếp loại tốt nghiệp THCS
    int criteria3 = 0;
    if ( student.graduation_rate == 1 ) criteria3 = 15;
    if ( student.graduation_rate == 2 ) criteria3 = 10;

    // Đạt các loại giải còn lại
    float criteria4 = 0;
    if ( student.prize[2] == 1 ) {
        criteria4 = 15;
    }
    else if ( student.prize[2] == 2 ) {
        criteria4 = 10;
    }
    else if ( student.prize[2] == 3 ) {
        criteria4 = 5;
    }
    else if ( student.prize[2] == 4 ) {
        criteria4 = 2.5; 
    }

    // Tổng điểm cho các tiêu chí trên
    return ( criteria1 + criteria2 + criteria3 + criteria4 );
}

bool second_round_condition ( PI_student student ) {
    double sum = mark_in_second_round ( student );
    // 45,0 điểm trở lên đối với lớp chuyên: Toán, Vật lí, Hóa học, Sinh học, Tiếng Anh và Tin học; 
    for ( int i = 1 ; i < 7 ; i ++ ) {
        if ( student.subject == i ) {
            if ( sum < 45 ) {
                return false;
            }
        }
    }

    // 35,0 điểm trở lên đối với lớp chuyên Ngữ văn, Lịch sử, Địa lí và Tiếng Pháp, Tiếng Nhật. 
    for ( int i = 7 ; i < 12 ; i ++ ) {
        if ( student.subject == i ) {
            if ( sum < 35 ) {
                return false;
            }
        }
    }
    return true;
}

void pass_second_round ( Danhsach &list , Danhsach &failed_list ) {
    pass_first_round ( list ,  failed_list );

    Danhsach passed_list;
    for ( int i = 0 ; i < list.num ; i++ ) {
        if ( second_round_condition ( list.STUDENT[i] ) == true ) {
            add_student ( list.STUDENT[i] , passed_list );
        }
        else {
            add_student ( list.STUDENT[i] , failed_list );
        }
    }
    list = passed_list;
}

void final_round_condition (Danhsach &subject , Danhsach &failed_list , int num_student_subject[] ) {
    pass_second_round ( subject , failed_list );

    if ( subject.num == 0 ) {
        return;
    }
    sort_score ( subject ) ;
    int current_subject = subject.STUDENT[0].subject;
    // Số lượng cần tuyển cho current_subject là current_num_student_subject
    int num_student_current_subject = num_student_subject[current_subject-1];
    Danhsach passed_list;
    for ( int i = 0 ; i < subject.num ; i++ ) {
        if ( i < num_student_current_subject ) {
            add_student ( subject.STUDENT[i] , passed_list );
        }
        else {
            add_student ( subject.STUDENT[i] , failed_list );
        }
    }
    subject = passed_list;
}

void pass_final_round ( Danhsach subject[] , Danhsach &failed_list , int num_student_subject[] ) {
    for ( int i = 0 ; i < 11 ; i++ ) {
        final_round_condition ( subject[i] , failed_list , num_student_subject );
    }
}

float benchmark ( Danhsach &subject , Danhsach &failed_list, int num_student_subject[] ) {
    final_round_condition ( subject , failed_list , num_student_subject);

    if ( subject.num == 0 ) {
        return 0;
    }
    
    sort_score ( subject ) ;
    return subject.STUDENT[subject.num - 1].score;
}

void BENCHMARK ( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [] , char *name_subject[] ) {
    for ( int i = 0 ; i < 11 ; i++ ) {
        float mark = benchmark ( subject[i] , failed_list, num_student_subject );
        cout << "\nBenchmark for "<<name_subject[i]<<" is: " << mark;
    }
}
