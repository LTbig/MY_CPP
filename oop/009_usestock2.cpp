#include<iostream>
#include "007_stock20.h"
const int STKS = 4;
int main(int argc, char const *argv[])
{
    //create an array of initialized objects 创建对象数组
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),// Most valuable holding
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock holdings:\n";
    int st;
    for ( st = 0; st < STKS; st++)
    {
        stocks[st].show();
    }
    //set pointer to first element
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++)
    {
        //topval每次只检查两个对象,因此程序使用for循环来检查整个数组;另外还使用stock指针来跟踪最高的元素
        top = &top->topval(stocks[st]);//更新top指针
    }
    //new top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    top->show();//通过指针来访问类成员函数
    
    return 0;
}
