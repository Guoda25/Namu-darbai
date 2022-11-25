#include "Skaiciavimai.h"




void ivedimas_automatiskai(Duomenys studentas[], int a)
{
    studentas[0].paz.clear();
    srand(time(0));
    studentas[0].egz = rand() % 10 + 1;
    for (int x = 0; x < a; x++);
    do
    {
        studentas[0].paz.push_back(rand() % 10 + 1);
    } while (studentas[0].paz.size() < a);

}


void ivedimas_ranka(Duomenys studentas[], int paz_sk)
{
    studentas[0].paz.clear();
    int temp;
    
    for (int a = 0; a < paz_sk; a++) {

        do {
            std::cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
            std::cin >> temp;
        } while (temp <= 0 || temp > 10);
        studentas[0].paz.push_back(temp);

    }

    do {
        std::cout << "Iveskite egzamino pazymi:\n";
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





void rezultatai(std::vector<Duomenys> studentas) //atspausdina rezultatus
{
    {

        std::cout << std::setw(20) << std::left << "Vardas"
            << std::setw(20) << std::left << "Pavarde"
            << std::setw(18) << std::left << "Galutinis(vid.)/"
            << std::left << "Galutinis(med.)\n"
            << "--------------------------------------------------------------------------\n";
        for (int i = 0; i < studentas.size(); i++)
        {
            std::cout << std::setw(20) << std::left << studentas[i].Vard
                << std::setw(20) << std::left << studentas[i].Pav
                << std::setw(18) << std::left << studentas[i].galut
                << mediana(studentas[i].paz) << std::endl;

        }
        std::cout << "\n\n";
    }
}

void rezultatau_isvedimas_iFaila(std::vector<Duomenys> studentas)
{
    std::ofstream output;
    output.open("kursiokai.txt");
    output << std::setw(20) << std::left << "Vardas"
        << std::setw(20) << std::left << "Pavarde"
        << std::setw(18) << std::left << "Galutinis(vid.)/"
        << std::left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentas.size(); i++)
    {
        output << std::setw(20) << std::left << studentas[i].Vard
            << std::setw(20) << std::left << studentas[i].Pav
            << std::setw(18) << std::left << studentas[i].galut
            << mediana(studentas[i].paz) << std::endl;
        

    }

    output << "\n\n";
}

