#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "Enter the starting countown value: ";
    int limit;
    cin >> limit;
    int i;
    for ( i = limit; i; i--)
    {
        cout << "i = " << i << "\n";
    }
    cout << "Done now that i = " << i << "\n";
    
    return 0;
}
