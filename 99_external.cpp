#include<iostream>
using namespace std;
//external variables
double warming = 0.3;
//function prototypes
void update(double dt);
void local();

int main(int argc, char const *argv[])
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1); //call function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local();//call function with local warming
    return 0;
}
