#include<iostream>
#include "019_mytime2.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;//use operator+()
    total.Show();
    cout << endl;

    diff = weeding - waxing;//use operator-()
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;//use operator*()
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;

    
    return 0;
}
