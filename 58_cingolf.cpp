#include<iostream>
const int Max = 5;
int main(int argc, char const *argv[])
{
    using namespace std;

    int golf[Max];
    cout << "Please enter your golf scores.\n";\
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for ( i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i]))
        {
            cin.clear();//重置输入
            while (cin.get() != '\n')//读取行尾之前的所有输入,从而删除这一行中的所有的错误输入
            {
                continue;
            }
            cout << "Please enter a number: ";
        }
    }
    
    double total = 0.0;
    for (i = 0; i < Max; i++)
    {
        total += golf[i];
    }
    cout << total / Max << "average score "
         << Max << " rounds\n";
    
    return 0;
}
