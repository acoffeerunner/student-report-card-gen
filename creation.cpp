#ifndef  includes
#define includes
//class_inc header
#include "class_inc.h"
//menu include
#include "menu.cpp"
#endif

using namespace std;
void cr_sr()
{
    //ofstream object here
    ofstream sr;
    sr.open("student_details.txt", ios :: app);
    //marks class object here
    marks m1;
    m1.get_info();

    //boring re-enter details part
    char l;
l_ladder:
    cout << "Would you like to re-enter the student record? (Y/N)   ";
    cin >> l;

    //if else for l
    if (l == 'y' || l == 'Y') //when the user wants to re-enter
    {
        system("cls");
        cout << "Re-enter student details:\n";
        m1.get_info();
        sr.write((char *)&m1, sizeof(m1));
    }

    else if (l == 'n' || l == 'N') //when the user doesn't want to re-enter
    {
        system("cls");

        //ugly progress bar stuff
        cout << "Writing records to file...\n";
        cout << "|=========";
        cout << "========";
        cout << "========|";
        sr.write((char *)&m1, sizeof(m1));
        cout << "\n\nWrite operation successful!";
        cout << "\n\nWritten record: \n";
        m1.disp_marks();
        getchar();
    }

    else //invalid case
    {
        system("cls");
        cout << "Invalid option selected!\n";
        goto l_ladder;
    }
}