#include<iostream>

template<class T> //or template<typename T>
T lessor(T a, T b)//#1
{
    return a < b ? a : b;
}

int lessor(int a, int b)//#2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    return a < b ? a : b;
}
int main(int argc, char const *argv[])
{
    using namespace std;
    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lessor(m, n) << endl;//use #2
    cout << lessor(x, y) << endl;// use #1 with double
    cout << lessor<>(m, n) << endl;//use #1 with int
    cout << lessor<int>(m, m) <<endl;//usr #1 with int

    return 0;
}
