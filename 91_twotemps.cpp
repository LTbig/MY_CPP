#include<iostream>
//original template
template <typename T> //or class T
void Swap(T & a, T & b);

//new template
template <typename T>
void Swap(T * a, T * b, int n);


void show(int a[]);
const int Lim = 8;
int main(int argc, char const *argv[])
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j  << ".\n";
    cout << "Using compiler-gernerated int swapper:\n";
    Swap(i, j);//generats void Swap(int &, int &);
    cout << "Now i, j = "  << i << ", " << j << ".\n";

    int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
    cout << "Original arrays:\n";
    show(d1);
    show(d2);
    
    Swap(d1, d2, Lim);
    cout << "Swapped arrays:\n";
    show(d1);
    show(d2);
    //cin.get();
    return 0;

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

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
