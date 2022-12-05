#include "Lib.h"
#include "Skaiciavimai.h"


bool comparePagalPav(const Duomenys& x, const Duomenys& y) {

    if (x.Pav.length() == y.Pav.length())
        return x.Pav < y.Pav;
    else
        return x.Pav.length() < y.Pav.length();
}

bool vargsiuku_paz(const Duomenys& x) {
    return x.galut < 5.00;
}

void vid_median(list<Duomenys>& studentas, list<Duomenys>::iterator it, int paz_sk)
{

    //suskaiciuoja studento galutini bala:
   it->galut = accumulate(it->paz.begin(), it->paz.end(), decltype(it->paz)::value_type(0)) / float(paz_sk);
   it->galut = round((it->galut * 0.4 + 0.6 * it->egz) * 100) / 100;


    //surusiuoja studento namu darbu pazymius ir randa mediana
    it->paz.sort();
    list<int>::iterator itP = it->paz.begin();
    paz_sk = (paz_sk / 2) - 1;
    advance(itP, paz_sk);

    if (paz_sk % 2 == 0)
    {
        it->median = float(*itP);
        advance(itP, 1);
        it->median = (it->median + float(*itP))/ 2.0;

    
    }
    else
    {
        advance(itP, 1);
        it->median = float(*itP);
    }

}

