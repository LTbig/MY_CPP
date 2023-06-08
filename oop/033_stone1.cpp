#include <iostream>
#include "031_stonewt1.h"

int main(int argc, char const *argv[])
{
    using std::cout;
    Stonewt poppins(9, 2.8);
    //定义了其与此匹配的转换函数
    double p_t = poppins;//隐式转换 ;double p_t = (double) poppins;double p_t = double (poppins)
    cout << "Convert to double => ";
    cout << "Poppins: " << p_t << "pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << "pounds.\n";
    cout << int (129.3) << std::endl;

    return 0;
}
