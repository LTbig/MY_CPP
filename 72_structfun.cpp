#include<iostream>
#include<cmath>

struct polar
{
    double distance;
    double angel;
};

struct rect
{
    double x;
    double y;
};
polar react_to_polar(rect xpos);
void show_polar(polar dapos);

int main(int argc, char const *argv[])
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        pplace = react_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    
    return 0;
}

polar react_to_polar(rect xpos)
{
    using namespace std;
    polar answer;

    answer.distance = sqrt(xpos.x * xpos.x + xpos.y * xpos.y);
    answer.angel = atan2(xpos.y, xpos.x);

    return answer;
}

void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.2977951;

    cout << "distance = " << dapos.distance;
    cout << ", angel = " << dapos.angel * Rad_to_deg;
    cout << " degrees\n";
}
