#include<iostream>
#include<cstdlib>
#include <ctime>
#include "04_string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main(int argc, char const *argv[])
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
         << " short sayings < empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for ( i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
        {
            continue;
        }
        if (!cin || temp[0] == '\0')
        {
            break;
        }
        else
        {
            sayings[i] = temp;
        }
    }
    int total = i;

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for ( i = 0; i < total; i++)
        {
            cout << sayings[i] << "\n";
        }
        //use pointers to keep track of shortrst, first strings
        String * shortest = &sayings[0];//initialize to first object
        String * first = &sayings[0];
        for ( i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
            {
                shortest = &sayings[i];//当找到比指向字符串更短的对象时,就把shortest重新设置为指向该对象
            }
            if (sayings[i] < *first)//compare values
            {
                first = &sayings[i];//assign address;fist 跟踪按字母顺序排在最前面的字符串
            }
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(0);
        int choice = rand() % total;//pick index at random
        //use new to create, initialize new String object
        String * favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;

        delete favorite;
    }
    else
    {
        cout << "Not much to say,eh?\n";
    }
    cout << "Bye.\n";

    return 0;
}
