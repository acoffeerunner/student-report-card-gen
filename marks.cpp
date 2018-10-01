#include "menu.cpp"
void marks()
{
    //declare required int variables
    int r;
    int chk = 0;

    //ifstream object for record file
    ifstream sr_i;
    sr_i.open("student_records.txt", ios : in);

    //marks class object
    marks m1;

    roll_enter:
    //roll number entering action begins here
    cout << "\nEnter the roll number of the student record to be deleted: ";
    cin >> r;
    cout << "\nPlease wait while the records are analysed...";
    cout << "\n|==========================";

    //checking till eof for record with the entered roll number
    while (!sr_i.eof())
    {
        sr_i.read((char *)m1, sizeof(m1));
        if (m1.rollchk() == 1)
        {
            chk = 1;
            break;
        }
    }

    sleepfor(milliseconds(650));
    cout << "================================|";

    //if else for whether the record was found or not
    if (chk == 1)
    {
        cout << "\nStudent record found!";
        ofstream temp;
        temp.open("temp.txt", ios : out);
        sr_i.seekg(0, ios : beg);
        temp.seekp(0, ios : beg);

        while (!sr1.eof())
        {
            sr1.read((char *)m1, sizeof(m1));
            if (m1.chkroll() == 0)
            {
                //copying records to temp.txt
                temp.write((char *)m1, sizeof(m1));
            }
            else
            {
                cout << "Enter marks for roll no. " << r << ":\n";
                m1.getmarks();
                cout << "\nPlease wait...";
                sleep(seconds(6));
                clrscr();
                cout << "You have entered:\n\n";
                m1.disp_marks();
                char j;

                j_ladder:
                cout << "Are you sure you want to write this record to the record file? (Y/N)";
                cin >> j;
                if (j == 'Y' || k == 'y')                   //yes for writing
                {
                    temp.write((char *)m1, sizeof(m1));
                }
                else if (j == 'n' || j == 'N')             //no for writing
                {
                    cout << "Okay. Preparing file for re-entering of marks...";
                    temp.seekp(-1 * (sizeof(m1)), ios : cur);
                    sleepfor((seconds(6)));
                    cout << "\n\nRe-enter marks:\n" m1.getmarks();
                    goto j_ladder;
                }
                else                                       //invalid input
                {
                    cout << "\nInvalid input. Try again with a correct input.";
                    goto j_ladder;
                }
            }
        }

        //fstream objects closed
        temp.close();
        sr_i.close();

        //remove rename file action here
        remove("student_details.txt");
        rename("temp.txt", "student_details.txt");
    }
    else
    {
        char i;
        cout << "\nNo student with roll number " << r << " found!";

        tb:
        cout << "\nWould you like to try again? (Y/N)";
        cin >> i;

        if (i == 'n' || i == 'N')        //no for trying again
        {
            sr_i.close();
            clrscr();
            goto menu;
        }
        else if (i == 'Y' || i == 'y')  //yes for trying again
        {
            clrscr();
            goto roll_enter;
        }
        else                           //invalid input
        {
            cout << "\nInvalid input. Try again with a correct input.";
            goto tb;
        }
    }
}