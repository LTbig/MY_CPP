#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char * pData)
{
    if (pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length+1];
        strcpy(m_pData, pData);
    }
    
}
CMyString::CMyString(const CMyString & str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length+1];
    strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString()
{
    delete[] m_pData;
}

// CMyString & CMyString::operator=(const CMyString & str)
// {
//     //判断传入参数和当前的实例是否是同一个实例
//     if (this==&str)
//     {
//         return *this;
//     }
//     // 释放实例自身已有的内存
//     delete [] m_pData;
//     m_pData = nullptr;

//     m_pData = new char[strlen(str.m_pData) + 1];
//     strcpy(m_pData, str.m_pData);

//     return *this;
    
// }

CMyString & CMyString::operator=(const CMyString & str)
{
    if (this != &str)
    {
        //创建一个临时实例
        CMyString strTemp(str); //局部变量,程序运行到if的外面时也就出了该变量的作用域,就会自动调用strTemp的析构函数,将strTemp.m_pData所指向的内存释放掉。

        char * pTemp = strTemp.m_pData;
        //strTemp.m_pData和实例本身的m_pData进行交换
        strTemp.m_pData = m_pData;//由于strTemp.m_pData指向的内存实例就是实例之前的m_pData的内存,这就相当于自动释放实例的内存
        m_pData = pTemp;
    }
    
    return *this;
}

//测试代码
void CMyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char * text = (char *)"hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}
//赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char * text = (char *) "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");

    str1.Print();
    printf(".\n");

}
//连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char * text = (char *) "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}
int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}