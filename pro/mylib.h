#include<iostream>
#include <limits>
#include <windows.h>
using namespace std;
void color(int color)
{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

short chose()

{	
    int Choice = 0;
    do
    {
       cin >> Choice;
        if (cin.fail())
        {	
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\t\t   ! Invalid input... !\n";
        }
        else if(Choice<0||Choice>4)
        {
        cout << "\t\t\t! THE CHOSE NUMBER IS ARROR !\n";
        }
    } while (Choice < 1 || Choice > 4);
    return Choice;   
}
