#include<iostream>
#include "014_dma.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portablelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "Displaying baseDMA object:\n";
    cout << shirt <<endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon <<endl;//派生类使用基类的友元
    cout << "Displaying map object:\n";
    cout << map << endl;

    lacksDMA balloon2(balloon);//隐式复制
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    return 0;
}
