#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include<algorithm>



struct Duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = {};
    int egz;
    float galut;
};

void mediana(std::vector<int> paz);

void vidurkis(Duomenys studentas[], int i);

void ivedimas_automatiskai(Duomenys studentas[], int i, int a);

void ivedimas_ranka(Duomenys studentas[], int i, int paz_sk);

bool has_digit(std::string s);

void vardas(Duomenys studentas[], int i);

void rezultatai(Duomenys studentas[], int studentu_sk);


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;

    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\nJeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n";
        std::cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R') { std::cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R');
    Duomenys stud[100]{};

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

            vardas(stud, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_automatiskai(stud, i, paz_sk);
            vidurkis(stud, i);
        }

        break;

    case 'r':
    case 'R':

        for (int i = 0; i < studentu_sk; i++)
        {
            vardas(stud, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_ranka(stud, i, paz_sk);
            vidurkis(stud, i);
        }

        break;

    }
    rezultatai(stud, studentu_sk);

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
    int counter = 0;
    for (int x = 0; x < studentas[i].paz.size(); x++)
        if (studentas[i].paz.at(counter) != 0) {
            counter++;
        }
        else {
            studentas[i].paz.at(counter) = 0;
        }

    studentas[i].galut = std::accumulate(studentas[i].paz.begin(),
        studentas[i].paz.end(), decltype(studentas[i].paz)::value_type(0));

    studentas[i].galut = studentas[i].galut / counter;
    studentas[i].galut = round((studentas[i].galut * 0.4 + 0.6 * studentas[i].egz) * 100) / 100;
}   


void ivedimas_automatiskai(Duomenys studentas[], int i, int a)
{   
    srand(time(0));
    studentas[i].egz = rand() % 10 + 1;
    for (int x = 0; x < a; x++);
    do
    {
        studentas[i].paz.push_back(rand() % 10 + 1);
    } while (studentas[i].paz.size() < a);
}


void ivedimas_ranka(Duomenys studentas[], int i, int paz_sk)
{
    int temp;

    for (int a = 0; a < paz_sk; a++) {

        std::cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
        std::cin >> temp;
        studentas[i].paz.push_back(temp);

    }

    do {
        std::cout << "Iveskite egzamino pazymi:\n";
        std::cin >> studentas[i].egz;
    } while (studentas[i].egz < 0 || studentas[i].egz > 10);
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
        std::cin >> studentas[i].Vard;
    } while (studentas[i].Vard.length() < 0 || studentas[i].Vard.length() > 25 || has_digit(studentas[i].Vard));
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        std::cin >> studentas[i].Pav;
    } while (studentas[i].Pav.length() < 0 && studentas[i].Pav.length() > 25 || has_digit(studentas[i].Pav));
    std::cout << std::endl;
}


void rezultatai(Duomenys studentas[], int studentu_sk)
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