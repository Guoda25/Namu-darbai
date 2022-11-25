#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include<algorithm>
#include <ctype.h>



struct Duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = {};
    int egz;
    float galut;
};

void mediana(std::vector<int> paz);

void vidurkis(Duomenys studentas[], int i);

void ivedimas_automatiskai(Duomenys studentas[], int a);

void ivedimas_ranka(Duomenys studentas[], int paz_sk);

bool has_digit(std::string s);

bool has_letter(int s);

void vardas(Duomenys studentas[], int i);

void rezultatai(std::vector<Duomenys> studentas, int studentu_sk);


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    Duomenys studentas[1];
    std::vector<Duomenys> studentai;

    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\nJeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n";
        std::cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R') { std::cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R');

    do
    {
        std::cout << "Iveskite studentu kieki:\n";
        std::cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);

    
    switch (temp) {
    case 'a':
    case 'A':
       
        for (int i = 0; i < studentu_sk; i++)
        {
            
            vardas(studentas, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_automatiskai(studentas, paz_sk);
            vidurkis(studentas, 0);
            studentai.push_back(studentas[0]);
           
        }

        break;

    case 'r':
    case 'R':

        for (int i = 0; i < studentu_sk; i++)
        {
            vardas(studentas, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_ranka(studentas, paz_sk);
            vidurkis(studentas, 0);
            studentai.push_back(studentas[0]);
        }

        break;

    }
    rezultatai(studentai, studentu_sk);

    system("pause>0");

}


void mediana(std::vector<int> paz)
{
    std::sort(paz.begin(), paz.end(), [](int& a, int& b) { return a > b; });
    int counter = 0;
    for (int i = 0; i < paz.size(); i++){
            
        counter++;   
    }

    if (counter % 2 == 0)
    {
        std::cout << round(float(((paz[(counter / 2) - 1]) + (paz[(counter / 2)])) / 2.0) * 100) / 100;
    }
    else
    {
        std::cout << round((paz[(counter / 2)]) * 100) / 100;
    }
    std::cout << std::endl;
   
    //for (int a=0; a< paz.size(); a++){std::cout << paz[a];}
    //std::cout << std::endl;
}

void vidurkis(Duomenys studentas[], int i)
{
    studentas[i].galut = std::accumulate(studentas[i].paz.begin(),
        studentas[i].paz.end(), decltype(studentas[i].paz)::value_type(0));

    studentas[i].galut = studentas[i].galut / counter;
    studentas[i].galut = round((studentas[i].galut * 0.4 + 0.6 * studentas[i].egz) * 100) / 100;
}   


void ivedimas_automatiskai(Duomenys studentas[], int a)
{   
    studentas[0].paz.clear();
    int x = 0;
    srand(time(0));
    studentas[0].egz = rand() % 10 + 1;
    do{
       
        studentas[0].paz.push_back(rand() % 10 + 1);
        x++;

    } while (x < a);
}


void ivedimas_ranka(Duomenys studentas[], int paz_sk)
{
    studentas[0].paz.clear();
    int temp;
    for (int a = 0; a < paz_sk; a++) {

        std::cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
        std::cin >> temp;
        studentas[0].paz.push_back(temp);

    }

    do {
        std::cout << "Iveskite egzamino pazymi: ";
        std::cin >> studentas[0].egz;
    } while (studentas[0].egz < 0 || studentas[0].egz > 10);
}

bool has_digit(std::string s)
{
    return (s.find_first_of("0123456789") != std::string::npos);
}


void vardas(Duomenys studentas[], int i)
{
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        std::cin >> studentas[0].Vard;
    } while (studentas[0].Vard.length() < 0 || studentas[0].Vard.length() > 25 || has_digit(studentas[0].Vard));
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        std::cin >> studentas[0].Pav;
    } while (studentas[0].Pav.length() < 0 && studentas[0].Pav.length() > 25 || has_digit(studentas[0].Pav));
    std::cout << std::endl;
}


void rezultatai(std::vector<Duomenys> studentas, int studentu_sk)
{
    std::cout << "\n\n";
    std::cout << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        std::cout << std::setw(20) << std::left << studentas[i].Vard
            << std::setw(20) << std::left << studentas[i].Pav
            << std::setw(18) << std::left << studentas[i].galut;
            mediana(studentas[i].paz);

    }

    std::cout << "\n\n";
}
