#include<iostream>
template <typename T> //or class T
void Swap(T & a, T & b);

int main(int argc, char const *argv[])
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << "\n";
    cout << "Using compiler-gernerated int swapper:\n";
    Swap(i, j);//generats void Swap(int &, int &);
    cout << "Now i, j = "  << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", "  << y << "\n" ;
    cout << "Using compiler-gernerated double swapper:\n";
    Swap(x ,y);//generates void Swap(double &, double &);
    cout << "Now x, y = " << x << ", " << y << ".\n";
    //cin.get();

    return 0;
}
//function template definition
template <typename T> //or class T
void Swap(T & a, T & b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
