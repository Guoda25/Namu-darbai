#include "Skaiciavimai.h"
using namespace std;


void failo_nuskaitymas(list<Duomenys>& studentai, int* pazymiu_sk)
{

    const char* path = "C:/Users/Guoda/Desktop/studentai10000.txt.txt";
    Duomenys studentas;
    studentai.push_back(studentas);
    list<Duomenys>::iterator it = studentai.begin();
    int temp;
    ifstream myFile;
    string line;
    myFile.open(path);
    try {
        if (!myFile)
            throw "NEPAVYKO ATIDARYTI FAILO!\n";
    }
    catch (const char* txtException) {
        cout << txtException;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {
            if (myFile.eof()) {
                studentai.pop_back();
                break;
            }

            myFile >> it->Vard;
            myFile >> it->Pav;

            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                it->paz.push_back(temp);
            }

            myFile >> it->egz;
            studentai.push_back(studentas);
            it++;

        }
    }
    myFile.close();

    for (list<Duomenys>::iterator it = studentai.begin(); it != studentai.end(); it++) {
        vid_median(studentai, it, *pazymiu_sk);
    }
}

void failo_nuskaitymas1(list<Duomenys>& studentai, int x, int* pazymiu_sk) {

    auto start = chrono::high_resolution_clock::now();
    string name = "studentai_" + to_string(x) + string(".txt");
    Duomenys studentas;
    studentai.push_back(studentas);
    list<Duomenys>::iterator it = studentai.begin();
    int temp;
    ifstream myFile;
    string line;
    myFile.open(name);
    try {
        if (!myFile)
            throw "NEPAVYKO ATIDARYTI FAILO!\n";
    }
    catch (const char* txtException) {
        cout << txtException;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {
            if (myFile.eof()) { 
                studentai.pop_back();
                break;
            }
            myFile >> it->Vard;
            myFile >> it->Pav;

            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                it->paz.push_back(temp);
            }
            myFile >> it->egz;
            studentai.push_back(studentas);
            it++;

        }

    }
    myFile.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    std::cout << "Failo is " << x << " studentu nuskaitymo laikas : " << diff.count() << endl;

    for (list<Duomenys>::iterator itr = studentai.begin(); itr != studentai.end(); itr++) {
        vid_median(studentai, itr, *pazymiu_sk);
    }
}

