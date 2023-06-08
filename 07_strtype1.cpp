#include<iostream>
#include<string>

int main(int argc, char const *argv[])
{
    using namespace std;
    char charr1[20];//create an empty array
    char charr2[20] = "jaguar";//create an intialized array
    string str1;//create an empty string object
    string str2 = "panther";//create an intialized string

    cout << "Enter a kind of feline: ";
    // cin >> charr1;
    cin.getline(charr1,20);
    cout << "Enter another kind of feline: ";
    cin >> str1; //use cin for input
    cout << "Here are some felines:\n";
    cout << charr1 << " " << charr2 << " "
         << str1 << " " << str2
         << endl;
    cout << "The third letter in " << charr2 << " is "
         <<charr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
         << str2[2] << endl;

    return 0;
}
