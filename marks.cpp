#ifndef includes
#define includes
//class_inc header
#include "class_inc.h"
//menu include
#include "menu.cpp"
#endif

using namespace std;
void marks_enter()
{
    //declare required int variables
    int r;
    int chk = 0;

    //ifstream object for record file
    fstream sr_i, sr_o;
    sr_i.open("student_details.txt");
    sr_o.open("student_details.txt");
    sr_i.seekg(0, ios :: beg);
    sr_o.seekp(0, ios :: beg);
    //marks class object
    marks m1;

    roll_enter:
    //roll number entering action begins here
    cout << "\nEnter the roll number of the student record to enter marks for: ";
    cin >> r;
    cout << "\nPlease wait while the records are analysed...";
    cout << "\n|==========================";
    
    //checking till eof for record with the entered roll number
    while(!sr_i.eof())
    {
        sr_i.read((char *)&m1, sizeof(m1));
        if(m1.rollchk(r)==1)
        {
            chk=1;
            break;
        }
    }
    cout << "================================|";

    //if else for whether the record was found or not
    if (chk == 1)
    {   
        cout << "\n\nStudent record found!\n\n";
        sr_i.seekg(0, ios :: beg);
        while (!sr_i.eof())
        {
            sr_i.read((char *)&m1, sizeof(m1));
            if (m1.rollchk(r) == 1)
            {
                chk = 1;
                m1.getmarks();
                cout << "\n\nWriting marks into record... Done!";
                sr_o.write((char *)&m1, sizeof(m1));
                break;
            }
            else
            {
                sr_o.seekp(1 * sizeof(m1), ios ::cur);
            }
        }
    }
    else
    {
        cout<<"\nStudent record not found";
    ta:
        char k;
        cout << "\nWould you like to try again? (Y/N)";
        cin >> k;
        if (k == 'n' || k == 'N')           //no for trying again
        {
            sr_i.close();
            system("cls");
            sr_i.close();
            sr_o.close();
        }
        else if (k == 'Y' || k == 'y')      //yes for trying again
        {
            system("cls");
            sr_i.seekg(0, ios :: beg);
            sr_o.seekp(0, ios :: beg);
            goto roll_enter;
        }
        else                                //invalid input
        {
            cout << "\nInvalid input. Try again with a correct input.";
            goto ta;
        }
    }
}