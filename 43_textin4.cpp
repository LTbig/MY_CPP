#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    char ch;
    int count = 0;
    cin.get(ch);//attempt to read a char
    while ((ch = cin.get()) != EOF)
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << "characters read\n";

    return 0;
}
