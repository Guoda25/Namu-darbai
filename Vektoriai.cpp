#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

struct Duomenys {
    std::string Vard, Pav;
    std::vector<int> paz = {};
    int egz;
    float galut;
    float median;
};

void vid_median(std::vector<Duomenys>& studentai, int i, int paz_sk);

void ivedimas_automatiskai(std::vector<Duomenys>& studentai, int i);

void ivedimas_ranka(std::vector<Duomenys>& studentai, int i);

bool has_digit(std::string s);

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

void vardas(std::vector<Duomenys>& studentai, int i);

void rezultatai(std::vector<Duomenys>& studentai);


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    std::vector<Duomenys> studentai;

    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\nJeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n";
        std::cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R') { std::cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R');

    do
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Iveskite studentu skaiciu:\n";
        std::cin >> studentu_sk;
    } while (studentu_sk < 0 || studentu_sk > 256 || std::cin.fail());

    studentai.resize(studentai.size() + studentu_sk);
    
    switch (temp) {
    case 'a':
    case 'A':
       

        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_automatiskai(studentai, i);
        }

        break;

    case 'r':
    case 'R':


        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_ranka(studentai, i);
        }

        break;

    }

    rezultatai(studentai);

    system("pause>0");

}


void vid_median(std::vector<Duomenys>& studentai, int i, int paz_sk)
{

    //suskaiciuoja studento galutini bala:

    studentai[i].galut = accumulate(studentai[i].paz.begin(), studentai[i].paz.end(), decltype(studentai[i].paz)::value_type(0)) / float(paz_sk);
    studentai[i].galut = round((studentai[i].galut * 0.4 + 0.6 * studentai[i].egz) * 100) / 100;


    //surusiuoja studento namu darbu pazymius ir randa mediana

    sort(studentai[i].paz.begin(), studentai[i].paz.end(), [](int& a, int& b) { return a > b; });
    if (paz_sk % 2 == 0)
    {
        studentai[i].median = float((studentai[i].paz.at((paz_sk / 2) - 1) + studentai[i].paz.at((paz_sk / 2))) / 2.0);
    }
    else
    {
        studentai[i].median = float(studentai[i].paz.at(paz_sk / 2));
    }

}


void ivedimas_automatiskai(std::vector<Duomenys>& studentas, int i)
{   
    int temp;
    vardas(studentas, i);

    do {

        std::cin.clear();
        std::cin.ignore();
        std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        std::cin >> temp;
        std::cout << std::endl;

    } while (std::cin.fail());

    srand(time(0));
    studentas[i].egz = rand() % 10 + 1;

    do
    {
        studentas[i].paz.push_back(rand() % 10 + 1);
    } while (studentas[i].paz.size() < temp);

    vid_median(studentas, i, temp);
}


void ivedimas_ranka(std::vector<Duomenys>& studentas, int i)
{
    int temp, temp2;
    vardas(studentas, i);

    do {

        std::cin.clear();
        std::cin.ignore();
        std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        std::cin >> temp;
        std::cout << std::endl;

    } while (std::cin.fail());

    for (int a = 0; a < temp; a++) {

        do {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
            std::cin >> temp2;
        } while (temp2 < 0 || temp2 > 10 || std::cin.fail());
        studentas[i].paz.push_back(temp2);

    }

    do {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Iveskite egzamino pazymi:\n";
        std::cin >> studentas[i].egz;
    } while (studentas[i].egz < 0 || studentas[i].egz > 10 || std::cin.fail());

    vid_median(studentas, i, temp);

}

bool has_digit(std::string s)
{
    return (s.find_first_of("0123456789,./;''[]-*") != std::string::npos);
}


void vardas(std::vector<Duomenys>& studentai, int i)
{
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        std::cin >> studentai[i].Vard;
    } while (studentai[i].Vard.length() < 0 || studentai[i].Vard.length() > 25 || has_digit(studentai[i].Vard));
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        std::cin >> studentai[i].Pav;
    } while (studentai[i].Pav.length() < 0 && studentai[i].Pav.length() > 25 || has_digit(studentai[i].Pav));
    std::cout << std::endl;
}


void rezultatai(std::vector<Duomenys>& studentai)
{
    sort(studentai.begin(), studentai.end(), comparePagalPav);
    char temp;
    do {
        std::cout << "Jeigu norite, kad studentu galutinis balas butu ju namu darbu mediana iveskite \"M\"\n"
            << "Jeigu norite, kad studentu galutinis balas butu paskaiciuotas pagal formule iveskite \"F\"\n";
        std::cin >> temp;
    } while (temp != 'm' && temp != 'M' && temp != 'f' && temp != 'F');

    switch (temp) {
    case'm':
    case'M':
        std::cout << "\n\n";
        std::cout << std::setw(20) << std::left << "Vardas"
            << std::setw(20) << std::left << "Pavarde"
            << "Galutinis(med.)\n"
            << "-------------------------------------------------------\n";
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << std::setw(20) << std::left << studentai[i].Vard
                << std::setw(20) << std::left << studentai[i].Pav
                << std::setw(18) << std::left << studentai[i].median << std::endl;

        }

        std::cout << "\n\n";

        break;
    case 'f':
    case 'F':

        std::cout << "\n\n";
        std::cout << std::setw(20) << std::left << "Vardas"
            << std::setw(20) << std::left << "Pavarde"
            << "Galutinis(vid.)\n"
            << "-------------------------------------------------------\n";
        for (int i = 0; i < studentai.size(); i++)
        {
            std::cout << std::setw(20) << std::left << studentai[i].Vard
                << std::setw(20) << std::left << studentai[i].Pav
                << std::setw(18) << std::left << studentai[i].galut << std::endl;

        }

        std::cout << "\n\n";

    }
}

bool comparePagalPav(const Duomenys& x, const Duomenys& y) {
        return x.Pav < y.Pav;

}
