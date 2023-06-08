#include<iostream>
#include "016_mytime1.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;//重定向 +; 其中coding位调用对象,而fixing为参数被传递对象
    //operator notation
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    //function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    
    return 0;
}
