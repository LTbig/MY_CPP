#ifndef STONEWT1_H
#define STONEWT1_H
class Stonewt
{
private:
    enum {Lbs_per_stn = 14}; // static const int Lbs_per_stn = 14; pounds per stone
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    //conversion functions
    operator int() const;
    operator double() const;
};

#endif