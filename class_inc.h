//include header files
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdio>
#include <cstdlib>

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
        if (chk == roll)
            return 1;
        else
            return 0;
    }
};

class marks : public person
{
    float e, m, s, cs, sst;
    char grade;
    float perc;

  public:
    marks()
    {
        e = 0;
        m = 0;
        s = 0;
        cs = 0;
        sst = 0;
        grade = '0';
        perc = 0;
    }
    void getperc()
    {
        perc = e + m + s + cs + sst;
        perc = perc / 5;
    }
    void getgrade()
    {
        if(perc<45)
            	grade='F';
        else if(perc==45)
                grade='P';
        else if(perc>45 && perc<=55)
                grade='E';
        else if(perc>55 && perc<=65)
                grade='D';
        else if(perc>65 && perc<=75)
                grade='C';        
        else if(perc>75 && perc<=85)
                grade='B';
        else if(perc>85 && perc<=95)
                grade='A';           
        else
                grade='O';            
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
        getgrade();
    }
    void disp_marks()
    {
        disp();
        cout << "\n\nEnglish            \t" << e;
        cout << "\nMathematics        \t" << m;
        cout << "\nScience            \t" << s;
        cout << "\nComputer Science   \t" << cs;
        cout << "\nSocial Studies     \t" << sst;
        cout << "\n\n==============================\n\n";
        cout << "Percentage:          \t" << perc << "\n";
        cout << "Grade:               \t" << grade << "\n";
        cout << "\n==============================\n\n";
    }
};