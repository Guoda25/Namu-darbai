#include "Lib.h"

struct Duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = { };
    int egz;
    float galut = 0;
    float median = 0;
};

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

void vid_median(vector<Duomenys>& studentai, int paz_sk, int a);