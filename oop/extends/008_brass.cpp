#include<iostream>
#include"007_brass.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
//formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass methods
Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
    {
        cout << "Negative deposit not allowed; "
             << "deposit is canceled.\n";
    }
    else
    {
        balance += amt;//balace = 4000 + 200
    } 
}

void Brass::Withdraw(double amt)
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
    {
        cout << "withdraw amount must be positive; "
             << "withdraw canceled.\n";
    }
    else if (amt <= balance)
    {
        balance -= amt;//0
    }
    else
    {
        cout << "Withdrawal amount of $ " << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
    
    }
    restore(initialState, prec); 
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}
//brassPlus Methods
BrassPlus::BrassPlus(const string & s,long an, double bal,double ml,double r)
                    : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
                    :Brass(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();//display base portion
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);//###.###format
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}
//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();//bal = 40000
    if (amt <= bal)
    {
        Brass::Withdraw(amt);
    }
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;//4200 - 4000
        owesBank += advance * (1.0 + rate);//200 * (1 + 0.11125) = 222.25
        cout << "Bank advance: $" << advance << endl;//200
        cout << "Friance change: $" << advance * rate << endl;//22.25
        Deposit(advance);//advance = 200
        Brass::Withdraw(amt);//amt =  4200
    }
    else
    {
        cout << "Credit limit exceeded, Transaction canceled.\n";
    }
    restore(initialState, prec);
}
format setFormat()
{
    //set up ###.##
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}