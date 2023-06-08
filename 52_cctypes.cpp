#include<iostream>
#include<cctype>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
         << " to terminate input.\n";
    
    char ch;
    int whitspace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);
    while (ch != '@')
    {
        if (isalpha(ch))
        {
            chars++;
        }
        else if (isspace(ch))
        {
            whitspace++;
        }
        else if (isdigit(ch))
        {
            digits++;
        }
        else if (ispunct(ch))
        {
            punct++;
        }
        else
        {
            others++;
        }
        cin.get(ch);
    }
    cout << chars << " letters, "
         << whitspace << " whitespace, "
         << digits << " digits, "
         << punct << " punctuations, "
         << others << " others.\n";
    
    return 0;
}
