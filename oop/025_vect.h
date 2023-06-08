#ifndef VECTOR_H_
#define Vector_H_
#include<iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode{RECT, POL};//RECT for rectangle,POL for Polar modes
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        //private methods for setting values
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);//这里设置了默认参数
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}//report x value; inline function
        double yval() const {return y;}//report y value
        double magval() const {return mag;}//report mag value
        double angval() const {return ang;}//report ang value
        void polar_mode();
        void rect_mode();
        //operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;//两种不同的定义,因为其特征标不同
        Vector operator-() const;
        Vector operator*(double n) const;
        //friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}//end namespace VECTOR
#endif