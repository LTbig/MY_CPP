#include<iostream>
#include<cstring>

int main(int argc, char const *argv[])
{
    using namespace std;
    const int Size = 15;
    char name1[Size];//empty array
    char name2[Size] = "C++owboy";//initialized array

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << " in array of " << sizeof(name1) << "bytes.\n";
    cout << " Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';//使用'\0'截断字符串
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;

    return 0;
}
