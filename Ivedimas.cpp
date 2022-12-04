#include "Skaiciavimai.h"
#include "tryCatch.h"


void vardas(std::vector<Duomenys>& studentai, int i)
{
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        std::cin >> studentai[i].Vard;
    } while (studentai[i].Vard.length() < 0 || studentai[i].Vard.length() > 25 || tryCatch(studentai[i].Vard) != true);
    do
    {
        std::cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        std::cin >> studentai[i].Pav;
    } while (studentai[i].Pav.length() < 0 && studentai[i].Pav.length() > 25 || tryCatch(studentai[i].Vard) != true);
    std::cout << std::endl;
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

    studentas[i].paz.clear();
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

    studentas[i].paz.clear();
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

void rezultatai(std::vector<Duomenys> studentai)
{   
    char temp;
    sort(studentai.begin(), studentai.end(), comparePagalPav);
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

void rezultatau_isvedimas_iFaila(std::vector<Duomenys> studentai)
{
    sort(studentai.begin(), studentai.end(), comparePagalPav);
    std::ofstream output;
    output.open("kursiokai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentai.size(); i++)
    {
        output << std::setw(20) << std::left << studentai[i].Vard
            << std::setw(20) << std::left << studentai[i].Pav
            << std::setw(18) << std::left << studentai[i].galut
            << studentai[i].median << std::endl;

    }
    output << "\n\n";

    std::cout << std::endl << "***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << std::endl;
}

