#include<iostream>
#include<string>
using namespace std;
const int SIZE = 5;
void display(const string sa[], int n);
int main(int argc, char const *argv[])
{
    string list[SIZE];
    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, list[i]);//list里的每一个元素都是一个string对象
    }
    cout << "Your list:\n";
    display(list, SIZE);

    return 0;
}
void display(const string sa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << sa[i] << endl;
    }
    
}
