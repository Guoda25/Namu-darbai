#include "Ivedimas.h"


void failo_nuskaitymas(std::vector<Duomenys>& studentai, int* pazymiu_sk)
{
    const char* path = "C:/Users/Guoda/Desktop/studentai10000.txt.txt";
    int i = 0;
    int temp;
    std::ifstream myFile;
    std::string line;
    myFile.open(path);
    if (!myFile) {
        std::cerr << "NEPAVYKO ATIDARYTI FAILO!" << std::endl;
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

    for (int a = 0; a < studentai.size(); a++) {
        vid_median(studentai, a, *pazymiu_sk);
    }
}
