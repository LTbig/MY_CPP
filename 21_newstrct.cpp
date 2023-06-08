#include<iostream>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(int argc, char const *argv[])
{
    using namespace std;
    inflatable * ps = new inflatable;//allot memory for structure
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);
    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;//*ps就是被指向的值(结构本身);即:*ps是一个结构;因此（*ps).price是该结构的price成员
    cout << "Enter price: $";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;
    cout << "Volume: " << ps->volume << " cubic feet\n";
    cout << "Price: $" << ps->price << endl;

    delete ps;
     
    return 0;
}

