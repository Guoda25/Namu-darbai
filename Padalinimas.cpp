#include "Skaiciavimai.h"


void studentu_isskaidymas(vector<Duomenys>& studentai, vector<Duomenys>& vargsiukai, vector<Duomenys>& kietiakai)
{
    auto start = chrono::high_resolution_clock::now();
    int a = studentai.size() - 1;
    for (int i = a; i >= 0; i--) {

        vector<Duomenys>::iterator it = studentai.begin();
        advance(it, i);
        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);
            studentai.erase(it);

        }
        else {
            kietiakai.push_back(*it);
            studentai.erase(it);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu padalijimo i dvi grupes laikas: " << diff.count() << endl;

    sort(vargsiukai.begin(), vargsiukai.end(), comparePagalPav);
    sort(kietiakai.begin(), kietiakai.end(), comparePagalPav);
}

