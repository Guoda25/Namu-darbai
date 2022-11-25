
#include "Ivedimas.h"





void failo_nuskaitymas(std::vector<Duomenys>& studentas, int* pazymiu_sk)
{
    const char* path = "C:/Users/Guoda/Desktop/studentai1000000.txt.txt";
    int student_counter = 0;
    int temp;
    std::ifstream myFile;
    std::string line;
    myFile.open(path);
    if (!myFile) { // file couldn't be opened
        std::cerr << "Error: file could not be opened" << std::endl;
        exit(1);
    }
    if (myFile.is_open())
    {
        getline(myFile, line);
        *pazymiu_sk = count(line.begin(), line.end(), 'N');
        while (true)
        {

            studentas.resize(studentas.size() + 1);
            myFile >> studentas.at(student_counter).Vard;
            if (myFile.eof()) { studentas.pop_back(); break; }
            myFile >> studentas.at(student_counter).Pav;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                myFile >> temp;
                studentas.at(student_counter).paz.push_back(temp);
            }
            myFile >> studentas.at(student_counter).egz;
            //std::cout << Eil.at(student_counter).Vard;
            studentas[student_counter].galut = std::accumulate(studentas[student_counter].paz.begin(),
                studentas[student_counter].paz.end(), decltype(studentas[student_counter].paz)::value_type(0));
            studentas.at(student_counter).galut = studentas.at(student_counter).galut / *pazymiu_sk;
            studentas.at(student_counter).galut = round((studentas.at(student_counter).galut * 0.4 + 0.6 * studentas.at(student_counter).egz)*100)/100;
            student_counter++;
        }
    }
    else { std::cout << "-\n"; }
}