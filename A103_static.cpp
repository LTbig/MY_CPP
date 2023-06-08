#include<iostream>

const int AriSize = 10;

void strcount(const char * str);

int main(int argc, char const *argv[])
{
    using namespace std;
    char input[AriSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, AriSize);
    while (cin)
    {
        cin.get(next);//读取行输入后的字符;如果next是换行符,则说明cin.get(input, AriSize)读取了整行,否则说明行中还有字符没有被读取
        while (next != '\n')//string didn't fit!
        {
            cin.get(next);//dispose of remainder 丢弃剩余的字符
        }
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        cin.get(input, AriSize);
    }
    cout << "Bye\n";

    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0;//静态变量total只在程序运行时被设置成0,以后的函数调用,其值将保持不变,因此能够记录读取字符的总数
    int count = 0;//自动变量,每次启动调用都会被初始化

    cout << "\"" << str << "\"contains ";
    while (*str++)
    {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
    
}
