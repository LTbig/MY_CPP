#include<iostream>
using std::cout;
#include "01_strngbad.h"

void callme1(StringBad & rsb);//pass oy reference
void callme2(StringBad  sb);//pass by value

int main(int argc, char const *argv[])
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headlene2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailer = sports;
        cout << "sailor: " << sailer << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
            
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << " \"" <<  rsb << "\"\n";
}

void callme2(StringBad  sb)
{
    cout << "String passed by value:\n";
    cout << "\"" << sb << "\"\n";
}
