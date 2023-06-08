#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    char ch;
    int count = 0;
    cin.get(ch);//attempt to read a char
    while (cin.fail() == false)
    {
        cout << ch;//echo character
        ++count;
        cin.get(ch);//attempt to read another char
    }
    cout << endl << count << "characters read\n";

    return 0;
}
