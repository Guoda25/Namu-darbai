#include "Skaiciavimai.h"
using namespace std;


void failo_nuskaitymas(vector<Duomenys>& studentai, int* pazymiu_sk)
{
    auto start = chrono::high_resolution_clock::now();
    const char* path = "C:/Users/Guoda/Desktop/studentai10000.txt.txt";
    int i = 0;
    int temp;
    ifstream myFile;
    string line;
    myFile.open(path);
    if (!myFile) { 
        cerr << "NEPAVYKO ATIDARYTI FAILO!" << endl;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {

            studentai.resize(studentai.size() + 1);
            myFile >> studentai[i].Vard;
            if (myFile.eof()) { studentai.pop_back(); break; }
            myFile >> studentai[i].Pav;
            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                studentai[i].paz.push_back(temp);
            }
            myFile >> studentai[i].egz;

            i++;
           
        }
       
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymo laikas:" << diff.count() << endl;

    for (int a = 0; a < studentai.size(); a++) {
        vid_median(studentai, a, *pazymiu_sk);
    }
    
}

void failo_nuskaitymas1(vector<Duomenys>& studentai, int x, int* pazymiu_sk) {
    
    auto start = chrono::high_resolution_clock::now();
    string name = "studentai_" + to_string(x) + string(".txt");
    int i = 0;
    int temp;
    ifstream myFile;
    string line;
    myFile.open(name);
    if (!myFile) {
        cerr << "NEPAVYKO ATIDARYTI FAILO!" << endl;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');

        while (true)
        {
            if (myFile.eof()) { break; }
            studentai.resize(studentai.size() + 1);
            myFile >> studentai[i].Vard;
  
            myFile >> studentai[i].Pav;
            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                studentai[i].paz.push_back(temp);
            }
            myFile >> studentai[i].egz;

            i++;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    std::cout << "Failo is " << x << " studentu nuskaitymo laikas : " << diff.count() << endl;
    for (int a = 0; a < studentai.size(); a++) {
        vid_median(studentai, a, *pazymiu_sk);
    }
}

