#include<iostream>
#include<string>
struct free_thows
{
    std::string name;
    int made;
    int attempts;
    float percent;
};
void display(const free_thows & ft);
void set_pc(free_thows & ft);
free_thows & accumulate(free_thows & target, const free_thows & source);

int main(int argc, char const *argv[])
{
    //partical initializations - remaining members set to 0
    free_thows one = {"Ifelsa Branch", 13, 14};
    free_thows two = {"Andor Knott", 10, 16};
    free_thows three = {"Minnie Max", 7, 9};
    free_thows four = {"Whily Looper", 5, 9};
    free_thows five = {"Long Long", 6, 14};
    free_thows team = {"Throwgoods", 0, 0};
    //no initialization
    free_thows dup;

    set_pc(one);
    display(one);
    accumulate(team,one);
    display(team);
    //use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    //use return value in assignment
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(dup);
    set_pc(four);
    //ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);

    return 0;
}

void display(const free_thows & ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << " Made: " << ft.made << "\t";
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n'; 
}

void set_pc(free_thows & ft)
{
    if (ft.attempts != 0)
    {
        ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
    }
    else
    {
        ft.percent = 0;
    }
}

free_thows & accumulate(free_thows & target, const free_thows & source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);

    return target;
}