#ifndef includes
#define includes
//class_inc header
#include "class_inc.h"
//menu include
#include "menu.cpp"
#endif

void disp_ssrc()
{
    ifstream sr_i;
    sr_i.open("student_details.txt", ios::in);
    sr_i.seekg(0, ios::beg);
    marks m1;
    
    int r, chk=0;
    //roll number entering action begins here
    roll_enter:
    cout << "\nEnter the roll number of the student record to be displayed: ";
    cin >> r;
    cout << "\nPlease wait while the records are analysed...";
    cout << "\n|==========================";

    //checking till eof for record with the entered roll number
    while (!sr_i.eof())
    {
        sr_i.read((char *)&m1, sizeof(m1));
        if (m1.rollchk(r) == 1)
        {
            chk = 1;
            break;
        }
    }
    cout << "================================|";

    if(chk==1)
    {
        cout<<"\n\nStudent record found! Displaying from file...\n\n";
        m1.disp_marks();
        getchar();
    }
    
    else
    {
        char i;
        cout << "\nNo student with roll number " << r << " found!";

        tb:
        cout << "\nWould you like to try again? (Y/N)";
        cin >> i;

        if (i == 'n' || i == 'N') //no for trying again
        {
            sr_i.close();
            system("cls");
            //goto menu;
        }
        else if (i == 'Y' || i == 'y') //yes for trying again
        {
            system("cls");
            sr_i.seekg(0, ios::beg);
            goto roll_enter;
        }
        else //invalid input
        {
            cout << "\nInvalid input. Try again with a correct input.";
            goto tb;
        }
    }
}