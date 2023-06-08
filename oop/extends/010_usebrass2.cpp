#include <iostream>
#include <string>
#include "007_brass.h"
const int CLIENTS = 4;

int main(int argc, char const *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    Brass * p_clients[CLIENTS];//指向Brass的指针数组,由于使用的共有继承模型,因此Brass指针即可指向Brass对象,也可以指向BrassPlus对象
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
             << "2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
        {
            cout << "Enter either 1 or 2: ";
        }
        if (kind == '1')
        {
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        }
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                 << " as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        }
        while (cin.get()!= '\n')
        {
            continue;
        }  
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();//虚函数将根据引用或者指针指向的对象的类型来选择方法;如果Brass::ViewAcct()没有声明为虚函数,则在任何情况下都将调用Brass::ViewAcct()
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];//free
    }
    cout << "Done.\n";
    
    return 0;
}
