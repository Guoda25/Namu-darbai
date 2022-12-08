#include "Lib.h"

struct Duomenys {
    string Vard, Pav;
    list<int> paz;
    int egz;
    float galut = 0;
    float median = 0;
};

struct Duomenys1 {
    std::string Vard, Pav;
    std::vector<int> paz = { };
    int egz;
    float galut = 0;
    float median = 0;
};

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

bool vargsiuku_paz(const Duomenys& x);

bool comparePagalPav1(const Duomenys1& x, const Duomenys1& y);

bool vargsiuku_paz1(const Duomenys1& x);

bool kietiaku_paz(const Duomenys1& x);

void vid_median(list<Duomenys>& studentai, list<Duomenys>::iterator it, int paz_sk);

void vid_median(vector<Duomenys1>& studentai, int i, int paz_sk);