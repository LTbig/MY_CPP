#include<iostream>

int main(int argc, char const *argv[])
{
    using  std::cout;//using declarations
    using  std::cin;
    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);
    while (ch != '.')
    {
        if (ch == ' ')
        {
            ++spaces;
        }
        ++total;
        cin.get(ch);
    }
    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    
    return 0;
}
