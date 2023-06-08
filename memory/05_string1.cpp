#include<cstring>
#include "04_string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

//static method
int String::HowMany()
{
    return num_strings;//只能访问静态成员
}
//class methods
String::String(const char * s)
{
    len = std::strlen(s);//set size
    str = new char[len + 1];//allot storage
    std::strcpy(str, s);//intialize pointer
    num_strings++;
    cout << num_strings << ": \"" << str << "\" object created\n";
}

String::String()
{
    len = 4;
    str = new char[4];
    str[0] = '\0';
    num_strings++;
}
//显示的复制构造函数
String::String(const String & st)
{
    num_strings++;
    len = st.len;//same length
    str = new char [len + 1];//allot space
    std::strcpy(str, st.str);//copy string to new location
}
//necessary destructor
String::~String()
{
    num_strings--;
    delete [] str;
}
//overloaded operator methods
    //assign a String to a String
String & String::operator=(const String & st)
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
    //assign a C string to a string
String & String::operator=(const char * s)
{

    delete [] str;//free old string
    len = std::strlen(s);
    str = new char [len+1];
    std::strcpy(str, s);

    return *this; 
}
    //read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}
    //read-only char access for non-const String
const char & String::operator[](int i) const
{
    return str[i];
}
//overloaded operator friends
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String & st1, const String & st2)
{
    return st2 < st1;
}
bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}
    //simple String optput
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;

    return os;
}
    //quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
    {
        st = temp;
    }
    while (is && is.get() != '\n')
    {
        continue;
    }
    
    return is;
}
