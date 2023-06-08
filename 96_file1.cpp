#include<iostream>
#include "95_coordin.h"
using namespace std;

int main(int argc, char const *argv[])
{
    rect replace;
    polar pplace;

    cout << "Enter the x and y value: ";
    while (cin >> replace.x >> replace.y)//slice use of cin
    {
        pplace = rect_to_polar(replace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";

    return 0;
}
