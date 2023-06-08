#ifndef STOCK20_H_
#define STOCK20_H_

#include<string>

class Stock //class declaration;其中声明类只是描述了对象的形式,并没有创建对象,因此在创建对象之前,将没有用于存储值的空间
{
private://私有成员(数据、函数)

    std::string company;
    // const long shares = 10; Fails!
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}
public:
    //two constructors
    Stock();//default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.5);
    ~Stock();// noisy destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};

#endif
