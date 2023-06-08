#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void file_it(ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main(int argc, char const *argv[])
{
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ".Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your "
            "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);//将数据写入到文件中
    file_it(cout, objective, eps, LIMIT);//将数据打印到屏幕上
    cout << "Done\n";
    
    
    return 0;
}
//ostream是基类,ofstream是ostream的派生类,派生类继承了基类的方法
void file_it(ostream & os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed);//save initial formatting state;setf(ios_base::fixed）将对象置于使用定点表示法的模式
    os.precision(0);//设置对象显示多少位小数
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);//将对象置于使用小数点的模式,即使小数部分为0
    os.precision(1);
    os.width(12);//设置下一次输出操作使用的字段宽度,这种设置只在显示下一个值时有效
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);    
}
