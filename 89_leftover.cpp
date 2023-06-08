#include<iostream>
unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n);
int main(int argc, char const *argv[])
{
    using namespace std;
    char * trip = (char *)"Havaii!!";//test value
    unsigned long n = 12345678;//test value
    int i;
    char * temp;

    for ( i = 1; i < 10; i++)
    {
        cout << left(n, i) <<endl;//函数重载
        temp = left(trip, i);
        cout << temp <<endl;
        delete [] temp;
    }
    
    return 0;
}
//this function returns the first ct digits of the number num
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
    {
        return 0;//return 0 if no digits
    }
    while (n /= 10)
    {
        digits++;
    }
    if (digits > ct)
    {
        ct = digits - ct;
        while (ct--)
        {
            num /= 10;
        }
        return num;//return left ct digits
    }
    else
    {
        return num;// if ct >= number of digits; return the whole number
    }
}

char * left(const char * str, int n)
{
    if (n < 0)
    {
        n = 0;
    }
    char * p = new char[n+1];
    int i;
    for ( i = 0; i < n && str[i]; i++)
    {
        p[i] = str[i];//copy characters
    }
    while (i <= n)
    {
        p[i++] = '\0';
    }

    return p;
}