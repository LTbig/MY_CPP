#include<iostream>
#include<array>
#include<string>
const int Seasons = 4;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};

void show(std::array<double, Seasons> da);
void fill(std::array<double, Seasons> * pa);

int main(int argc, char const *argv[])
{
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);

    return 0;
}
void fill(std::array<double, Seasons> * pa)
{
    using namespace std;
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];//pa指向数组对象,则*pa就是该数组对象
    } 
}

void show(std::array<double, Seasons> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] <<endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total <<endl;
}
