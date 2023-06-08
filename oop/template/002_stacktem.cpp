#include<iostream>
#include<cctype> // or ctype.h
#include "001_stacktp.h"
using std::cin;
using std::cout;
int main(int argc, char const *argv[])
{

    Stack<std::string> st;//create an empty stack
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')//省略后面没用的字符
        {
            continue;
        }
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A':
            case 'a':
                    cout << "Enter a PO number to add: ";
                    cin >> po;
                    if (st.isfull())
                    {
                        cout << "Stack areadly full\n";
                    }
                    else
                    {
                        st.push(po);
                    }
                    break;
            case 'p':
            case 'P':
                    if (st.isempty())
                    {
                        cout << "Stack alreadly empty\n";
                    }
                    else
                    {
                        st.pop(po);
                        cout << "PO #" << po << " popped\n";
                    }
                    break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye.\n";
    
    return 0;
}
