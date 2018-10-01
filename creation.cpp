#include "menu.cpp"
void cr_sr()
{
    //ofstream object here
    ofstream sr;
    sr.open("student_records.txt", ios : out);

    //marks class object here
    marks m1;
    m1.get_info();

    //boring re-enter details part
    char l;
    l_ladder:
    cout << "Would you like to re-enter the student record? (Y/N)   ";
    cin >> l;

    //if else for l
    if (l == 'y' || l == 'Y')           //when the user wants to re-enter
    {
        clrscr();
        cout << "Re-enter student details:\n";
        m1.get_info();
    }

    else if (l == 'n' || l == 'N')      //when the user doesn't want to re-enter
    {
        clrscr();

        //ugly progress bar stuff
        cout << "Writing records to file...\n";
        cout << "|=========";
        sleepfor(milliseconds(600));
        cout << "========";
        sleepfor(milliseconds(500));
        cout << "========|";
        sr.write((char *)&m1, sizeof(m1));
        cout << "\nWrite operation successful!";
        getchar();

        //redirect to menu.cpp
        cout << "\nPlease wait while you're redirected to the main menu...";
        sleepfor(seconds(5));
        clrscr();
        goto menu;
    }
    
    else        //invalid case
    {
        clrscr();
        cout << "Invalid option selected!\n";
        goto l_ladder;
    }