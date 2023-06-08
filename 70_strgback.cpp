#include<iostream>
char * buildstr(char c, int n);
int main(int argc, char const *argv[])
{
    using namespace std;
    int times;
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char * ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps;//free memory
    ps = buildstr('+', 20);
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps;

    return 0;
}

char * buildstr(char c, int n)
{
    char * pstr = new char[n + 1];
    pstr[n] = '\0';
    while (n-- > 0)
    {
        pstr[n] = c;//fill rest of string
    }
    return pstr;
}
