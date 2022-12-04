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
    std::vector<int> paz = {};
    int egz;
    float galut;
    float median;
};



bool comparePagalPav(const Duomenys& x, const Duomenys& y) {
    if (x.Pav.length() == y.Pav.length())
        return x.Pav < y.Pav;
    else
        return x.Pav.length() < y.Pav.length();
}

void vid_median(std::vector<Duomenys>& studentai, int i, int paz_sk)
{

    //suskaiciuoja studento galutini bala:

    studentai[i].galut = accumulate(studentai[i].paz.begin(), studentai[i].paz.end(), decltype(studentai[i].paz)::value_type(0)) / float(paz_sk);
    studentai[i].galut = round((studentai[i].galut * 0.4 + 0.6 * studentai[i].egz) * 100) / 100;


    //surusiuoja studento namu darbu pazymius ir randa mediana

    sort(studentai[i].paz.begin(), studentai[i].paz.end(), [](int& a, int& b) { return a > b; });
    if (paz_sk % 2 == 0)
    {
        studentai[i].median = float((studentai[i].paz.at((paz_sk / 2) - 1) + studentai[i].paz.at((paz_sk / 2))) / 2.0);
    }
    else
    {
        studentai[i].median = float(studentai[i].paz.at(paz_sk / 2));
    }

}

