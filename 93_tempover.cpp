#include<iostream>
//template A
template <typename T>
void  ShowArray(T arr[], int n);

//template B
template <typename T>
void ShowArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};


int main(int argc, char const *argv[])
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double * pd[3];//声明一个指针数组
    //set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
    cout << "Listening Mr .E's counts of things:\n";
    //things is an array of int
    ShowArray(things, 6);//uses template A
    cout << "Listening Mr .E's debts:\n";
    //pd is an array of pointers to double
    ShowArray(pd, 3);//uses template B (more specialized)
    
    return 0;
}

template <typename T>
void  ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}
