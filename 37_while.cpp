#include<iostream>
const int ArSize = 20;

int main(int argc, char const *argv[])
{
    using namespace std;
    char name[ArSize];
    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASSIIized:\n";
    int i = 0;
    while (name[i] != '\0')
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
    
    return 0;
}
