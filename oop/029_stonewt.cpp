#include <iostream>
using std::cout;
#include "028_stonewt.h"

//construct Stonewt objrct from  double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;//integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{

}
//show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}
//show weight ini pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}