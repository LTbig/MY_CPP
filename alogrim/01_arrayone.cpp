#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    int yames[3];
    yames[0] = 7;
    yames[1] = 8;
    yames[2] = 6;

    int yamcosts[3] = {20, 30, 5};
    
    cout << "Total yams = ";
    cout << yames[0] + yames[1] + yames[2] << endl;
    cout << "The pakages with" << yames[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yames[0] * yamcosts[0] + yames[1] * yamcosts[1];
    total = total + yames[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yames;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yames[0];
    cout << " bytes.\n";

    return 0;
}

