#include "menu.cpp"
void cr_sr()
{
    ofstream sr;
    sr.open("student_records.txt", ios:out);
    marks m1;
    m1.get_info();
    char l; 
    l_ladder:
    cout<<"Would you like to re-enter the student record? (Y/N)   ";
    cin>>l;
    if(l=='y' || l=='Y')
    {
        clrscr();
        cout<<"Re-enter student details:\n";
        m1.get_info();
    }
    else if(l=='n' || l=='N')
    {
        clrscr();
        cout<<"Writing records to file...\n";
        cout<<"|=========";
        sleepfor(milliseconds(600));
        cout<<"========";
        sleepfor(milliseconds(500));
        cout<<"========|";
        sr.write((char*)&m1, sizeof(m1));
        cout<<"\nWrite operation successful!";
    }
    else
    {   
        clrscr();
        cout<<"Invalid option selected!\n";
        goto l_ladder;
}