#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int higgens = 5;
    int * pt = &higgens;//指针的初始化

    cout << "Value of higgens = " << higgens
         << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
         << "; Value of pt = " << pt << endl;

    return 0;
}
