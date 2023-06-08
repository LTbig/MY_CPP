#include<iostream>
extern double warming; //use warming from another file
//function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()
{
    double warming = 0.8;//new variable hiedes external

    cout << "Local warming = " << warming << ", degrees.\n";

    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}