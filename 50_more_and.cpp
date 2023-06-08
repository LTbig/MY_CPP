#include<iostream>
const char * qualify[4] = 
{
    "10,000-meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festive.\n"
};

int main(int argc, char const *argv[])
{
    using namespace std;
    int age;
    cout << "Enter your age in years: ";
    cin >> age;
    int index;

    if (age > 17 && age < 35)
    {
        index = 0;
    }
    else if (age >= 35 &&  age < 50)
    {
        index = 1;
    }
    else
    {
        index = 3;
    }
    
    cout << "You qualify for the " << qualify[index];
    
    return 0;
}
