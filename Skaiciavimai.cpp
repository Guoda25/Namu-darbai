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


float mediana(std::vector<int> paz)
{
    std::sort(paz.begin(), paz.end(), [](int& a, int& b) { return a > b; });
    int counter = 0;
    for (int i = 0; i < paz.size(); i++)
    {
            counter++;
    }

    if (counter % 2 == 0)
    {
        return round(float(((paz[(counter / 2) - 1]) + (paz[(counter / 2)])) / 2.0)*100) / 100;
    }
    else
    {
        return round((paz[(counter / 2)])*100) / 100;
    }

}

void vidurkis(Duomenys studentas[], int i)
{

    studentas[i].galut = std::accumulate(studentas[i].paz.begin(),
        studentas[i].paz.end(), decltype(studentas[i].paz)::value_type(0));

    studentas[i].galut = studentas[i].galut / studentas[i].paz.size();
    studentas[i].galut = round((studentas[i].galut * 0.4 + 0.6 * studentas[i].egz)*100)/100;

}

