#include<iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad();
    StringBad(const StringBad &);//显示得复制构造函数
    ~StringBad();
    StringBad & operator=(const StringBad &);//显示定制赋值运算符
    //friend function
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);

};
#endif
