#include "Lib.h"

struct Duomenys {
    string Vard, Pav;
    list<int> paz;
    int egz;
    float galut = 0;
    float median = 0;
};

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

bool vargsiuku_paz(const Duomenys& x);

void vid_median(list<Duomenys>& studentai, list<Duomenys>::iterator it, int paz_sk);