#ifndef includes
#define includes
//class_inc header
#include "class_inc.h"
//menu include
#include "menu.cpp"
#endif

using namespace std;
void disp_src()
{
    //ifstream object
    ifstream sr_i;
    sr_i.open("student_details.txt", ios::in);
    
    //get pointer to 0 position of file
    sr_i.seekg(0, ios::beg);

    //marks object
    marks m1;
    
    while(1)
    {
        sr_i.read((char *)&m1, sizeof(m1));
        if(!sr_i.eof())
        {
            m1.disp_marks();
            getchar();
            cout<<"\n\n\n\n\n\n";
        }
        else
            break;
    }
}