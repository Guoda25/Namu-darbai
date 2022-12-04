#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>

struct Duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = { };
    int egz;
    float galut;
    float median;
};

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

void vid_median(std::vector<Duomenys>& studentai, int i, int paz_sk);
