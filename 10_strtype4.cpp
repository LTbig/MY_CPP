#include<iostream>
#include<string>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
         << strlen(charr) << endl;//对于未初始化的数据第一个空字符出现的位置是随机的
    cout << "Length of string in str before input: "
         << str.size() << endl;
    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length
    cout << "You entered another line of text:\n";
    getline(cin,str); // cin now an argument; no length specifier
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: "
         << strlen(charr) << endl;
    cout << "Length of string in str after input: "
         << str.size() << endl;

    return 0;
}
