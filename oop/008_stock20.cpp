#include<iostream>
#include "007_stock20.h"

//constructors （verbose version)
Stock::Stock()
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = co;

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
    
}

//class destructor
Stock::~Stock()
{
    std::cout << "Bye, " << company << "!\n";
}

//other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be nagative."
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of share sold can't be negative. "
             <<  "Transaction is oborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec =cout.precision(3);

    cout << "Company: " << company << " Shares: " << shares << '\n';
    cout << " Share Price: $" << share_val;

    //set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';

    //restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
    
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val) //这里的total_val 相当于 this->total_val
    {
        return s;//显式的访问对象
    }
    else
    {
        return *this;//隐式的对象,也就是自己本身自己这个对象;其中this是指向自己的指针
    }
    
}