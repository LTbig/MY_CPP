#include<iostream>

struct inflatable
{
    char name[20];
    float colume;
    double price;
};

int main(int argc, char const *argv[])
{
    using namespace std;

    inflatable guest = 
    {
        "Glorious Gloria",//name value
        1.88,//volume value
        29.99//price value
    };//guest is a structure variable of type inflatable

    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    };//pal is a second structure variable of type inflatable
    // NOTE: some implementations requaire 
    // using static inflatable guest = 

    cout << "Expand your guest list with " << guest.name;
    cout << " add " << pal.name << "!\n";
    //pal.name is the name of member of the pal variable
    
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";

    return 0;
}

