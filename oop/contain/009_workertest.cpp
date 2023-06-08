#include<iostream>
#include "007_worker0.h"
const int LIM = 4;
int main(int argc, char const *argv[])
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly", 522L, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};//多态指针数组
    int i;
    for ( i = 2; i < LIM; i++)
    {
        pw[i]->Set();
    }
    for ( i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    
    return 0;
}
