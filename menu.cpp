#ifndef includes
#define includes
//class_inc header
#include "class_inc.h"
//include our files
#include "creation.cpp"
#include "del.cpp"
#include "marks.cpp"
#include "ssrc.cpp"
#include "src.cpp"
#endif

using namespace std;

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
    system("cls");
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
        marks_enter();
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
        return 0;
        break;
    default:
        cout << "\nYou have entered an invalid option number.";
        break;
    }

    return 0;
}