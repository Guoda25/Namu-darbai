#include "FailoNuskaitymas.h"
#include "tryCatch.h"


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    std::vector<Duomenys> studentai;

    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\n"
            << "Jeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n"
            << "Jeigu norite, kad studentu pazymiai butu nuskaityti is failo, iveskite \"F\"\n";
        std::cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F') { 
            std::cout << "pakartokite, netinkamas simbolis\n"; }

    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F');

    if (temp == 'a' || temp == 'A' || temp == 'r' || temp == 'R') {
        do
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Iveskite studentu skaiciu:\n";
            std::cin >> studentu_sk;
        } while (studentu_sk < 0 || studentu_sk > 256 || std::cin.fail());
    }

    switch (temp) {
    case 'a':
    case 'A':
       
        studentai.resize(studentai.size() + studentu_sk);

        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_automatiskai(studentai, i);
        }

        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'r':
    case 'R':
        
        studentai.resize(studentai.size() + studentu_sk);

        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_ranka(studentai, i);
        }
        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'f':
    case 'F':
        failo_nuskaitymas(studentai, &paz_sk);
        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    }
    
    system("pause>0");

}


