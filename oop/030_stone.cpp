#include<iostream>
using std::cout;
#include "028_stonewt.h"
void display(const Stonewt & st, int n);
int main(int argc, char const *argv[])
{
    Stonewt incognito = 275;//uses constructor to initialize
    Stonewt wolfe(285.7);//same as Stonewt wolfe = 285.7
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    incognito = 276.8; //use constructor for conversion
    taft = 325;//same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighted ";
    incognito.show_stn();
    cout << "After dinner, the President weighted ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);//这里的第一个参数是Stonewt对象,遇到int参数时,编译器查找构造函数Stonewt(int),一遍将int转换为Stonewt类型。
    // 由于没有找到这样的构造函数,因此将int转换为doubel,然后使用Stonewt(double)将其转换为Stonewt对象
    cout << "No stone left unearned\n";

    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
    
}
