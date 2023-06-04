#include "Menu.h"

using namespace std;

void Output ( Danhsach subject [] , char *name_subject[] ) {
    for ( int i = 0 ; i < 11 ; i++ ) {
        cout << "\n____"<<name_subject[i]<<" includes "<< subject[i].num<<" student____";        
        for ( int j = 0 ; j < subject[i].num ; j++ ) {
            cout << "\n" << j + 1 << "." << subject[i].STUDENT[j];
        }
    }
    cout << "__________________________________________________________\n";
}

void Edit_infor ( Danhsach subject [] ) {
    cout << " Nhap ma so hoc sinh muon chinh sua: ";
    int studentId;
    cin >> studentId;

    bool ok = false;
    PI_student *currentStudent;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < subject[i].num; ++j) {
            if (subject[i].STUDENT[j].ID_student == studentId) {
                currentStudent = &subject[i].STUDENT[j];
                ok = true;
                break;
            } 
        }
    }

    if (!ok) {
        cout << "\nHoc sinh khong ton tai";
        return;
    }

    cin >> *currentStudent;
    cout << "\nHoan tat viec chinh sua thong tin hoc sinh";
}

void Output_alphabet ( Danhsach subject [], char *name_subject[] ) {
    SORT_ALPHABET ( subject );
    Output ( subject, name_subject );
}

void Output_score ( Danhsach subject [], char *name_subject[] ) {
    SORT_SCORE ( subject );
    Output ( subject, name_subject );
}

void Output_passed_list ( Danhsach subject [] , Danhsach &failed_list, char *name_subject[], int num_student_subject[] ) {
    pass_final_round ( subject , failed_list, num_student_subject );
    Output ( subject, name_subject );
}

void Output_failed_list ( Danhsach subject [] , Danhsach &failed_list , int num_student_subject[] ) {
    pass_final_round ( subject , failed_list , num_student_subject );
    for ( int i = 0 ; i < failed_list.num ; i++ ) {
        cout << "\n"<< i + 1 <<". Thong tin hoc sinh thu "<< i + 1 <<" la: " << failed_list.STUDENT[i];
    }
}

void Menu_input( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [], char *name_subject[] ) {
    bool ok = true;
	while ( ok ) {
        cout << "\n\t=================MENU================\n";
        cout << "\t1. NHAP THONG TIN HOC SINH\n";
        cout << "\t2. XUAT THONG TIN HOC SINH DA NHAP\n";
        cout << "\t3. CHINH SUA THONG TIN HOC SINH\n";
        cout << "\t4. HOAN TAT VIEC NHAP THONG TIN\n";
        cout << "\t=====================================\n";
        
        int choice_input;
        cout << "Nhap lua chon: ";
        cin >> choice_input;
        
        switch (choice_input) {
        case 1:	{

            cout << "\tNHAP THONG TIN HOC SINH\n";
            PI_student student; 
            cin >> student;

            add_student(student, subject[student.subject - 1]);
            break;
        }

        case 2:
            cout << "\tXUAT THONG TIN HOC SINH DA NHAP\n";
            Output ( subject , name_subject );

            break;

        case 3:
            cout << "\tCHINH SUA THONG TIN HOC SINH\n";
            Edit_infor ( subject );
            break;

        case 4:
            cout << "\tHOAN TAT VIEC NHAP THONG TIN\n";
            Menu_output ( subject , failed_list, num_student_subject , name_subject );
            ok = false;
            break;
        }
    }
}

void Menu_output ( Danhsach subject[], Danhsach &failed_list, int num_student_subject [] , char *name_subject[] ) {
    bool ok = true;
    while ( ok ) {
        cout << "\n\t=================MENU================\n";
        cout << "\t1. XUAT DANH SACH HOC SINH DANG KI XET TUYEN THEO TUNG MON CHUYEN\n";
        cout << "\t2. XUAT DIEM CHUAN CHO TUNG MON CHUYEN \n";
        cout << "\t3. DANH SACH HOC SINH DAU CHO TUNG MON CHUYEN\n";
        cout << "\t4. DANH SACH HOC SINH ROT XET TUYEN\n";
        cout << "\t5. XUAT DANH SACH HOC SINH DAU VA ROT VAO FILE\n";
        cout << "\t6. THOAT\n";
        cout << "\t=====================================\n";
        
        int choice_output;
        cout << "Nhap lua chon: ";
        cin >> choice_output;
        
        switch (choice_output) {
        case 1:		
            cout << "\tDANH SACH HOC SINH DANG KI XET TUYEN THEO TUNG MON CHUYEN\n";
            Output_alphabet ( subject, name_subject);
            break;
        case 2:
            cout << "\tDIEM CHUAN CHO TUNG MON CHUYEN\n";
            BENCHMARK ( subject , failed_list, num_student_subject, name_subject );
            break;
        case 3:
            cout << "\tDANH SACH HOC SINH DAU CHO TUNG MON CHUYEN\n";
            Output_passed_list ( subject , failed_list, name_subject, num_student_subject );
            break;
        case 4:
            cout << "\tDANH SACH HOC SINH ROT XET TUYEN\n";
            Output_failed_list ( subject , failed_list, num_student_subject );
            break;
        case 5:
            UnloadData(subject, failed_list, num_student_subject, name_subject);
            break;
        case 6:
            ok = false;
            break;
        }
    }
}

void MenuStudent( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [], char *name_subject[], int &currentStudent ) {
    bool ok = true;
    while ( ok ) {
        cout << "\n\t=================MENU================\n";
        cout << "\t1. XUAT THONG TIN HOC SINH\n";
        cout << "\t2. TRA CUU KET QUA TUYEN SINH \n";
        cout << "\t3. THOAT\n";
        cout << "\t=====================================\n";

        int choice; cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 11; ++i) {
                    for (int j = 0; j < subject[i].num; ++j) {
                        if (subject[i].STUDENT[j].ID_student == currentStudent) {
                            cout << subject[i].STUDENT[j];
                            break;
                        } 
                    }
                }

                break;

            case 2: {
                bool ok1 = false;
                pass_final_round(subject, failed_list, num_student_subject);
                for (int i = 0; i < 11; ++i) {
                    for (int j = 0; j < subject[i].num; ++j) {
                        if (subject[i].STUDENT[j].ID_student == currentStudent) {
                            ok1 = true;
                            cout << "CHUC MUNG BAN DA DAU!!" << endl;
                        } 
                    }
                }

                if (!ok1) cout << "RAT TIEC! BAN DA ROT!!" << endl;

                break;
            }

            default:
                ok = false;
                break;
        }
    }
}

void LoginStudent( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [], char *name_subject[], int &currentStudent ) {
    cout << "NHAP MA HOC SINH: ";
    cin >> currentStudent;

    bool ok = false;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < subject[i].num; ++j) {
            if (subject[i].STUDENT[j].ID_student == currentStudent) {
                ok = true;
                break;
            } 
        }
    }

    if (ok) {
        MenuStudent(subject, failed_list, num_student_subject, name_subject, currentStudent);
        return;
    }

    else {
        cout << "MA HOC SINH SAI" << endl;
        return;
    }
}

void MainMenu ( Danhsach subject[] , Danhsach &failed_list , int num_student_subject [], char *name_subject[], int &currentStudent ) {
    bool ok = true; 
    while ( ok ) {
        cout << "\n\tDANG NHAP VOI TU CACH LA\n";
        cout << "\t1. NHA TRUONG\n";
        cout << "\t2. HOC SINH\n";
        cout << "\t3. THOAT CHUONG TRINH\n";
        cout << "\t===============================\n";

        int choice_input;
        cout << "Nhap lua chon: ";
        cin >> choice_input;

        switch (choice_input) {
        case 1:	
            Menu_input ( subject , failed_list , num_student_subject, name_subject );
            break;

        case 2: 
            LoginStudent( subject , failed_list , num_student_subject, name_subject, currentStudent);
            break;            

        default:
            ok = false;
            break;
        }
    }
}

// đọc file data.inp
void LoadData(Danhsach subject[]) {
    freopen("Data.inp", "r", stdin);

    int num; cin >> num;
    for (int i = 0; i < num; ++i) {
        PI_student student;
        fflush(stdin);
        cin.getline(student.name,30);

        cin >> student.gender;

        fflush(stdin);
        cin.getline(student.birthday,30);

        fflush(stdin);
        cin.getline(student.ethnicity,30);

        fflush(stdin);
        cin.getline(student.birthplace,30);

        do {
            cin >> student.permanent_address;
        } while ( student.permanent_address != 1 && student.permanent_address != 2 );
        
        fflush(stdin);
        cin.getline(student.contact_address,30);
            
        fflush(stdin);
        cin.getline(student.phonenumber,30);

        fflush(stdin);
        cin.getline(student.secondary_school_name,30);

        cin >> student.ID_student;

        for ( int i = 6; i <= 9 ; i++ ) {
            cin >> student.conduct[i];

            cin >> student.ranked_acdemic[i];
        }

        do {
            cin >> student.graduation_rate;
        } while ( student.graduation_rate != 1 && student.graduation_rate != 2 && student.graduation_rate != 3);

        cin >> student.subject;

        // Gán giá trị = 0;
        for ( int i = 0; i < 4 ; i++ ) {
            student.prize[i] = 0;
        }
        /*Nhập các giải thưởng đã nhận cấp quốc gia và cấp thành phố các môn chuyên mà mình đã đăng kí*/
        cin >> student.prize[0];

        if ( student.prize[0] == 2 ) {  
            cin >> student.prize[1];
        }
        // Nhập giải thưởng tin học trẻ, KHKT: giải cấp thành phố về Tin học trẻ khi đăng kí vào môn chuyên Tin học và Khoa học kĩ thuật ( đv môn chuyên tương ứng)
        // Xét cả tin học trẻ và KHKT ( chỉ xét đv hs thi chuyên tin )
        if ( student.subject == 6 ) {
            cin >> student.prize[2];

            if ( student.prize[2] == 1) {
                cin >> student.prize[2];
            }
        }
        
        // Xét KHKT (đối vs các môn chuyên trừ chuyên tin)
        else { 
            cin >> student.prize[2];

            if ( student.prize[2] == 1 ) {
                cin >> student.prize[2];
            }
        }

        cin >> student.result[0];
        cin >> student.result[1];
        cin >> student.result[2];
        cin >> student.result[3];

        student.score = student.result[0] + student.result[1] + student.result[2] + 3 * student.result[3];

        add_student(student, subject[student.subject - 1]);
    }
}

// ghi đè dữ liệu từ chương trình vào file data.out
void UnloadData(Danhsach subject[], Danhsach &failed_list, int num_student_subject [], char *name_subject[]) {
    ofstream FileOut;
    FileOut.open( "Data.out" , ios_base::out );

    pass_final_round ( subject , failed_list, num_student_subject );

    FileOut << "\nDANH SACH HOC SINH DAU XET TUYEN: "; 
    for ( int i = 0 ; i < 11 ; i++ ) {
        FileOut << "\n____" << name_subject[i] << " includes " << subject[i].num << " student____";        
        for ( int j = 0 ; j < subject[i].num ; j++ ) {
            FileOut << "\n" << j + 1 << "." << subject[i].STUDENT[j];
        }
    }
    FileOut << "__________________________________________________________\n";

    FileOut << "\nDANH SACH HOC SINH ROT XET TUYEN: ";
    for ( int i = 0 ; i < failed_list.num ; i++ ) {
        FileOut << "\n"<< i + 1 <<". Thong tin hoc sinh thu "<< i + 1 <<" la: " << failed_list.STUDENT[i];
    }
    FileOut << "__________________________________________________________\n";

    FileOut.close();
}