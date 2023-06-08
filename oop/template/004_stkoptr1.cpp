#include <iostream>
#include <cstdlib>
#include <ctime>
#include "003_stacktp1.h"
const int Num = 10;
int main(int argc, char const *argv[])
{
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    //create an empty stack with stacksize slots
    Stack<const char *> st(stacksize);
    //in basket
    const char * in[Num] = {
        " 1: Hank", " 2: Kiki ",
                " 3: Tank", " 4: Fiki ",
                        " 5: Dnk", " 6: Wiki ",
                                " 7: Pank", " 8: Oiki ",
                                        " 9: Sank", " 10: Riki ",
    };
    //out basket
    const char * out[Num];

    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isempty())
        {
            st.push(in[nextin++]);
        }
        else if (st.isfull())
        {
            st.pop(out[processed++]);
        }
        else if (std::rand() % 2 && nextin < Num)
        {
            st.push(in[nextin++]);
        }
        else
        {
            st.pop(out[processed++]);
        }
    }
    for (int i = 0; i < Num; i++)
    {
        std::cout << out[i] << std::endl;
    }
    std::cout << "Bye\n";
    
    return 0;
}
