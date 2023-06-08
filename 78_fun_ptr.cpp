#include<iostream>
double betsy(int lns);
double pam(int lns);
void estimate(int lines, double (*pf)(int));//double (*pf)(int) 声明函数指针

int main(int argc, char const *argv[])
{
    using namespace std;
    int code;
    cout << "How many lines of code do you need? ";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);

    return 0;
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hours(s)\n";//(*pf)(lines) 使用函数指针
}