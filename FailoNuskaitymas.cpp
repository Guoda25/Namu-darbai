#include "Ivedimas.h"


void failo_nuskaitymas(std::vector<Duomenys>& studentai, int* pazymiu_sk)
{
    const char* path = "C:/Users/Guoda/Desktop/studentai10000.txt.txt";
    Duomenys studentas;
    studentai.push_back(studentas);
    int i = 0;
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
            myFile >> studentai[i].Vard;
            myFile >> studentai[i].Pav;
            for (int a = 0; a < *pazymiu_sk; a++)
            {
                myFile >> temp;
                studentai[i].paz.push_back(temp);
            }
            myFile >> studentai[i].egz;
            studentai.push_back(studentas);
            i++;
        }
    }
    myFile.close();
    
    for (int a = 0; a < studentai.size(); a++) {
        vid_median(studentai, a, *pazymiu_sk);
    }
}
