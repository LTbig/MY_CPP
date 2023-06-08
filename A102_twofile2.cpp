#include<iostream>
extern int tom;//tom defined elsewhere
static int dick = 10;//overrdies external dick
int harry = 200;//no conflict with twofile harry

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}