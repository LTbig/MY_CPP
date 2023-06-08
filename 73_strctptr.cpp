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
void show_polar(const polar * pda);
void react_to_polar(const rect * pxy, polar * pda);

int main(int argc, char const *argv[])
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        react_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    
    return 0;
}

void react_to_polar(const rect * pxy, polar * pda)
{
    using namespace std;

    pda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
    pda->angel = atan2(pxy->y, pxy->x);
}

void show_polar(const polar * pda)
{
    using namespace std;
    const double Rad_to_deg = 57.2977951;

    cout << "distance = " << pda->distance;
    cout << ", angel = " << pda->angel * Rad_to_deg;
    cout << " degrees\n";
}
