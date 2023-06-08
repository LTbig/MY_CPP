#include<iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;//rodents is a reference;必须在声明时将其初始化
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    //some inplementions require type casting the following address to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}
