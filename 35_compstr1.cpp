#include<iostream>
#include<cstring>//prototype for strcmp

int main(int argc, char const *argv[])
{
    using namespace std;
    
    char word[5] = "?ate";
    for (char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;

    return 0;
}