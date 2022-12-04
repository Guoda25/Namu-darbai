#include "Lib.h"


string pazymiai() {

    vector<string> paz;
    for (int i = 0; i < 10; i++) {
        paz.push_back(to_string(rand() % 10 + 1) + "\t");
    }
    string pazm = std::accumulate(paz.begin(), paz.end(), std::string(""));
    return pazm;
};

void failo_generavimas(int x) {


    string name = "studentai_" + to_string(x) + string(".txt");
    ofstream failas(name);
    failas << setw(21) << left << "Vardas " << setw(18) << left << "Pavarde" << setw(9) << left << "ND1" << setw(8)
        << left << "ND2" << setw(8) << left << "ND3" << setw(8) << left << "ND4" << setw(8) << left << "ND5" << setw(8)
        << left << "ND6" << setw(8) << left << "ND7" << setw(8) << left << "ND8" << setw(8) << left << "ND9" << setw(8)
        << left << "Egz" << endl;

    for (int i = 1; i < x + 1; i++) {
        failas << "Vardas" << setw(15) << left << i << "Pavarde" << setw(11) << left << i << pazymiai() << endl;
    }

};