#include<iostream>
#include "A105_namesp.h"
void other(void);
void another();
int main(int argc, char const *argv[])
{
    using debts::Debt;
    using debts::showDebt;
 
    Debt golf = {{"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();
    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;
    using namespace debts;//使用编译指令导入整个名称空间（不大好）
    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];
    int i;
    for ( i = 0; i < 3; i++)
    {
        getDebt(zippy[i]);
    }

    for ( i = 0; i < 3; i++)
    {
        showDebt(zippy[i]);
    }
    cout << "Total debt: $" << sumDebts(zippy, 3) <<endl;

    return;
}

void another()
{
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}
