#include<iostream>
#include "004_stock10.h"

int main(int argc, char const *argv[])
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0);//syntax 1
        stock1.show();
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);//syntax 2
        stock2.show();

        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listening stock2 and stock2:\n";
        stock1.show();
        stock2.show();

        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);//赋值语句 会创建一个temp object
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done.\n";
    }
    
    return 0;
}
