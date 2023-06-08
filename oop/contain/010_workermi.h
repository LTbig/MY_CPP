#ifndef WORKERMI_H_
#define WORKERMI_H_
#include<string>
//an abstrct base worker
class Worker
{
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L){}
    Worker(const std::string & s, long n)
            :fullname(s), id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};
class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(),panache(0){}
    Waiter(const std::string & s, long n, int p = 0)
            : Worker(s, n),panache(p){}
    Waiter(const Worker & wk, int p = 0)
            : Worker(wk), panache(p){}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum{other, alto, contralto, soprano, bass, baritone, tenor};
    enum{Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char * pv[Vtypes];//string aquivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other){}
    Singer(const std::string & s, long n, int v = other)
            : Worker(s, n), voice(v){}
    Singer(const Worker & wk, int v = other)
            :Worker(wk), voice(v){}
    void Set();
    void Show() const;
};
//multiple inheritence
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
                    :Worker(s, n), Waiter(s, n, p),Singer(s, n, v){}
    //     SingingWaiter(const Worker & wk, int p = 0, int v = other)
    //                          : Waiter(wk, p), Singer(wk, v){}
    //上述函数存在问题的是,如果 Worker是虚基类将通过两条不同的途径（Waiter和Singer）将wk传递给Worker对象
    //为了避免冲突,c++在基类是虚的时,禁止信息通过中间类自动传递给基类,因此上述构造函数将初始化成员pancha和vocie
    //但wk参数中的信息将不会传递给子对象Waiter或者Singer。
    //然而编译器必须在创造派生对象之前构造基类对象组件;在上述情况下编译器将使用Worker的默认构造函数
    //如果不希望默认构造函数来构造虚基类对象,则需要显示地调用所需的基类构造函数(如下面的函数所示)
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
                    :Worker(wk), Waiter(wk, p), Singer(wk, v){}
    //上述的代码显式地调用构造函数Worker(const Worker &);
    SingingWaiter(const Waiter & wt, int v = other)
                    :Worker(wt), Waiter(wt), Singer(wt, v){}
    SingingWaiter(const Singer & wt, int p = 0)
                    :Worker(wt), Waiter(wt, p),Singer(wt){}
    void Set();
    void Show() const;
};

#endif