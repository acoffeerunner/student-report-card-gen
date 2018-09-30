#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int c;
    cout<<"Choose an option from below:\n";
    cout<<"1. Create new student records.\n";
    cout<<"2. Delete student records.\n";
    cout<<"3. Enter marks for subjects.\n";
    cout<<"4. Show a specific student's report card.\n";
    cout<<"5. Show all students' report cards one by one.\n";
    cout<<"0. Exit.";
    cin>>c;
    clrscr();
    cout<<"You chose "<<c<<".";
    return 0;
}