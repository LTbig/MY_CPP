#include<iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(int argc, char const *argv[])
{
    using namespace std;
    
    inflatable guests[2] = 
    {
        {"Bambi", 0.5, 21.99},//fist structure in array
        {"Godzilla", 2000, 565.99}//next structure in array
    };

    cout << "The guests " << guests[0].name << " and " << guests[1].name
         << "\nhave a combined volume of "
         << guests[0].volume + guests[1].volume << " cubic feet.\n";
         
    return 0;
}

