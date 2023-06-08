#include<string>
//create the pers and debts namespaces
namespace pers
 {
    struct Person
    {
        std::string fname; //声明一个名称可用
        std::string lname;
    };
    void getPerson(Person &);
    void showPerson(const Person &);
 }

 namespace debts
 {
    using namespace pers;//编译指令使pers所有的名称都可用
    struct Debt
    {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n); 
 }