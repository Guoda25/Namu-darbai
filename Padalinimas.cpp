#include "FailoNuskaitymas.h"

//std::list funkcijos
//Sttrategija nr.1
void studentu_isskaidymas1(list<Duomenys> studentai, list<Duomenys> vargsiukai, list<Duomenys> kietiakai)
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
    cout << setw(66) << left << "Strategija nr.1: " << setw(20) << left << diff.count() << endl;

}

//Strategija nr.2
void studentu_isskaidymas2(list<Duomenys> studentai, list<Duomenys> vargsiukai)
{
    auto start = chrono::high_resolution_clock::now();
    int a = studentai.size() - 1;
    for (int i = a; i > -1; i--) {
     
        list<Duomenys>::iterator it = studentai.begin();
        advance(it, i);
        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);
            studentai.erase(it);
        }

    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << setw(66) << left << "Strategija nr.2: " << setw(20) << left << diff.count() << endl;
}


//std::vector funkcijos
//Sttrategija nr.1
void studentu_isskaidymas1(vector<Duomenys1> studentai, vector<Duomenys1> vargsiukai, vector<Duomenys1> kietiakai)
{
    auto start = chrono::high_resolution_clock::now();

    for (vector<Duomenys1>::iterator it = studentai.begin(); it != studentai.end(); it++) {

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
    cout << setw(66) << left << "Strategija nr.1: " << setw(20) << left << diff.count() << endl;
}

void studentu_isskaidymas1_2(vector<Duomenys1> studentai, vector<Duomenys1> vargsiukai, vector<Duomenys1> kietiakai)
{

    auto start = chrono::high_resolution_clock::now();

    copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), vargsiuku_paz1);
    copy_if(studentai.begin(), studentai.end(), back_inserter(kietiakai), kietiaku_paz);
    studentai.clear();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << setw(66) << left << "Strategija nr.1 pritaikius copy_if: " << diff.count() << endl;
}


//Strategija nr.2
void studentu_isskaidymas2(vector<Duomenys1> studentai, vector<Duomenys1> vargsiukai)
{
    auto start = chrono::high_resolution_clock::now();
    int a = studentai.size() - 1;
    for (int i = a; i > -1; i--) {

        vector<Duomenys1>::iterator it = studentai.begin();
        advance(it, i);
        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);
            studentai.erase(it);
        }

    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << setw(66) << left << "Strategija nr.2: " << setw(20) << left << diff.count() << endl;
}

void studentu_isskaidymas2_2(vector<Duomenys1>& studentai, vector<Duomenys1>& vargsiukai)
{
    auto start = chrono::high_resolution_clock::now();

    copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), vargsiuku_paz1);
    studentai.erase(remove_if(studentai.begin(), studentai.end(), vargsiuku_paz1), studentai.end());


    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << setw(66) << left << "Strategija nr.2 pritaikius copy_if ir remove_if: " << diff.count() << endl;
}


//testavimo funkcijos
void test_V(vector<Duomenys1>& studentai, vector<Duomenys1>& vargsiukai, vector<Duomenys1>& kietiakai, int x) {

    int paz_sk;

    failo_nuskaitymas1(studentai, x, &paz_sk);

    if (x < 1000000) {
        studentu_isskaidymas1(studentai, vargsiukai, kietiakai);
        studentu_isskaidymas2(studentai, vargsiukai);
    }
    else {
        studentu_isskaidymas1(studentai, vargsiukai, kietiakai);
    }

    studentu_isskaidymas1_2(studentai, vargsiukai, kietiakai);
    studentu_isskaidymas2_2(studentai, vargsiukai);

    if (x == 10000000) {

        rezultatai_varg_kiet(vargsiukai, studentai);
    }
    

    studentai.clear();
    vargsiukai.clear();
    kietiakai.clear();
    cout << "\n\n";
}

void test_L(list<Duomenys>& studentai, list<Duomenys>& vargsiukai, list<Duomenys>& kietiakai, int x) {

    int paz_sk;

    failo_nuskaitymas1(studentai, x, &paz_sk);
    if (x <= 100000) {
        studentu_isskaidymas1(studentai, vargsiukai, kietiakai);
        studentu_isskaidymas2(studentai, vargsiukai);

    }
    else {
        studentu_isskaidymas1(studentai, vargsiukai, kietiakai);
    }
    


    studentai.clear();
    vargsiukai.clear();
    kietiakai.clear();
    cout << "\n\n";
}