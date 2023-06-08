#include<iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;//rodents is a reference

    cout << "rats = " << rats;
    cout << ", rotents = " << rodents <<endl;

    cout << "rats address =" << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;//can we change the reference? no! 这里等价于 rats = bunnies； 这样的赋值语句
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    
    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}
