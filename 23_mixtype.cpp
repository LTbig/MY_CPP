#include<iostream>
#include<fstream>
using namespace std;
struct antarctica_years_end
{
    int year;
};

int main(int argc, char const *argv[])
{
    antarctica_years_end s01, s02, s03;
    s01.year = 1998;

    antarctica_years_end * pa = &s02;
    pa->year = 1999;

    antarctica_years_end trio[3];//array of 3 structuers
    trio[0].year = 2003;
    std::cout << trio->year << std::endl;

    const antarctica_years_end * arp[3] = {&s01, &s02, &s03};//指针数组
    std::cout << arp[1]->year << std::endl;

    const antarctica_years_end * (* ppa) = arp;//*ppa是一个结构指针; ppa是指向指针的指针; **pa就是数组里面的第一个结构
    auto ppb = arp;//c++11 automatic type deduction or else use const antarctica_years_end ** ppb = year
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb+1))->year << std::endl;

    std::cout << (*(*ppa)).year << std::endl;
    std::cout << (*(*(ppb+1))).year << std::endl;

    return 0;
}

