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
    float galut = 0;
};

float mediana(std::vector<int> paz);

void vidurkis(Duomenys studentas[], int i);