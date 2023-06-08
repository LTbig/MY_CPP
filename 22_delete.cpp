#include<iostream>
#include<cstring>//or string.h

using namespace std;

char * getname();
int main(int argc, char const *argv[])
{
    char * name;//careate pointer but no storage

    name = getname();//assign address of string to name
    cout << name << " at " << (int *) name << "\n";
    delete [] name;//memory freed

    name = getname();//reuse freed momory
    cout << name << " at " << (int *) name << "\n";
    delete [] name;//memory freed again

    return 0;
}

char * getname()//retuen pointer to new string
{
    char temp[80];//tempory storage
    cout << "Enter last name: ";
    cin >> temp;
    char * pn = new char(strlen(temp) + 1);
    strcpy(pn, temp);//copy string to a smaller space;string类里面有内置的new和delete

    return pn;
}
