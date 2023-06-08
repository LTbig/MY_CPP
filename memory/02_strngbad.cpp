#include<cstring>
#include "01_strngbad.h"
using std::cout;

int StringBad::num_strings = 0;

StringBad::StringBad(const char * s)
{
    len = std::strlen(s);//set size
    str = new char[len + 1];//allot storage
    std::strcpy(str, s);//intialize pointer
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");//default string
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}
//显示的复制构造函数
StringBad::StringBad(const StringBad & st)
{
    num_strings++;
    len = st.len;//same length
    str = new char [len + 1];//allot space
    std::strcpy(str, st.str);//copy string to new location
    cout << num_strings << ": \"" << str << "\" object created\n";//For Your Information
}
//necessary destructor
StringBad::~StringBad()
{
    cout << "\"" << str << "\" object deleted, ";
    num_strings--;
    cout << num_strings << " left\n";
    delete [] str;
}
//显示定制赋值运算符
StringBad & StringBad::operator=(const StringBad & st)
{
    if (this == &st)
    {
        return *this;
    }

    delete [] str;//free old string
    len = st.len;
    str = new char [len+1];
    std::strcpy(str, st.str);

    return *this;
    
}
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;

    return os;
}