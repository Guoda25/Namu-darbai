#include "FailoNuskaitymas.h"


//Sttrategija nr.1
void studentu_isskaidymas(list<Duomenys>& studentai, list<Duomenys>& vargsiukai, list<Duomenys>& kietiakai)
{
    auto start = chrono::high_resolution_clock::now();
    for (list<Duomenys>::iterator it = studentai.begin(); it != studentai.end(); it++) {

        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);

        }
        else {
            kietiakai.push_back(*it);
        }
    }
    studentai.clear();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu padalijimo i dvi grupes laikas: " << diff.count() << endl;
}


