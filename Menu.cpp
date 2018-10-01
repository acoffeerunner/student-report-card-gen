//include header files
#include <iostream>
#include <conio.h>
#include <fstream.h>
#include <chrono>

//include our files
#include "creation.cpp"
#include "del.cpp"
#include "marks.cpp"
#include "ssrc.cpp"
#include "src.cpp"

using namespace std;

//our classes
class person
{
    int roll;
    char name[1000];
    int dob_d, dob_m, dob_y;

  public:
    void get_info()
    {
        cout << "Enter roll no. of student: ";
        cin >> roll;
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter date of birth: ";
        cin >> dob_d >> dob_m >> dob_y;
    }

    void disp()
    {
        cout << "\nRoll no. of student: " << roll;
        cout << "\nName: " << name;
        cout << "\tDate of birth: " << dob_d << "/" << dob_m << "/" << dob_y;
    }

    int rollchk(int chk)
    {
        if(chk==roll)
            return 1;
        else
            return 0;
    }
};

class marks:public person
{
    float e, m, s, cs, sst;
    char grade;
    float perc;

  public:
    marks()
    {
        e=0; m=0; s=0; cs=0; sst=0; grade='0'; perc=0;
    }
    void getperc()
    {
        perc = e + m + s + cs + sst;
        perc = perc / 5 * 100;
    }
    void getmarks()
    {
        cout << "Enter English marks: ";
        cin >> e;
        cout << "Enter Mathematics marks: ";
        cin >> m;
        cout << "Enter Science marks: ";
        cin >> s;
        cout << "Enter Computer Science marks: ";
        cin >> cs;
        cout << "Enter Social Studies marks: ";
        cin >> sst;
        getperc();
    }
    void disp_marks()
    {
        cout << "\nEnglish            \t" << e;
        cout << "\nMathematics        \t" << m;
        cout << "\nScience            \t" << s;
        cout << "\nComputer Science   \t" << cs;
        cout << "\nSocial Studies     \t" << ss;
        cout << "==============================\n\n";
        cout << "Percentage:          \t" << perc << "\n";
        cout << "Grade:               \t"; << grade << "\n";
        cout << "==============================\n\n";
    }
}

//main()
int main()
{
    int c;

    //options
    cout << "Choose an option from below:\n";
    cout << "1. Create new student records.\n";
    cout << "2. Delete student records.\n";
    cout << "3. Enter marks for subjects.\n";
    cout << "4. Show a specific student's report card.\n";
    cout << "5. Show all students' report cards one by one.\n";
    cout << "0. Exit.";
    cin >> c;
    clrscr();

    //after choice
    cout << "You chose " << c << ".\n";

    //switch case statements
    switch (c)
    {
    case 1:
        cout << "============================= Creation of new student records =============================\n";
        cr_sr();
        break;
    case 2:
        cout << "=============================== Deletion of student records ===============================\n";
        del_sr();
        break;
    case 3:
        cout << "===================================== Entering of marks ===================================\n";
        marks();
        break;
    case 4:
        cout << "========================= Display specific student's report card ==========================\n";
        disp_ssrc();
        break;
    case 5:
        cout << "============================ Display all students' report cards ============================\n";
        disp_src();
        break;
    case 0:
        cout << "Exiting...\n";
        getchar();
        exit();
        break;
    default:
        cout << "\nYou have entered an invalid option number.";
        break;
    }

    return 0;
}