#include<iostream>
using::std::cout;
using::std::endl;
//template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

//template class
template<typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) :item(i){ct++;}
    ~HasFriendT(){ct--;}
    //模板类的约束模板友元函数
    friend void counts<TT>();//没有可被编译器用来推断出所需具体化的参数,所以这些调用使用count<int>和count<double>()指明其具体化
    friend void report<>(HasFriendT<TT> &);//可以从参数推断出要使用的具体化
};
//each specialization has its own static data member
template <typename T>
int HasFriendT<T>::ct = 0;

//template friend fucntions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}
template <typename T>
void report(T & hf)
{
   cout << hf.item << endl;
}
int main(int argc, char const *argv[])
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);//generated report(HasFriendT<int> &)
    report(hfi2);//generated report(HasFriendT<int> &)
    report(hfdb);//generated report(HasFriendT<double> &)

    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();

    return 0;
}

