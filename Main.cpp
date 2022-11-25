#include "FailoNuskaitymas.h"
#include "tryCatch.h"
void vidurkis(Duomenys studentas[], int i);


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    Duomenys studentas[1];
    std::vector<Duomenys> studentai;
   
 


    do
    {
        std::cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\nJeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\nJeigu norite, kad studentu pazymiai butu nuskaityti is failo, iveskite \"F\"\n";
        std::cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F') { std::cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F');

    if (temp == 'a' || temp == 'A' || temp == 'r' || temp == 'R') {
        do
        {
            std::cout << "Iveskite studentu kieki:\n";
            std::cin >> studentu_sk;
        } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
    }

    switch (temp) {
    case 'a':
    case 'A':
       

        for (int i = 0; i < studentu_sk; i++)
        {   
            
            vardas(studentas, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_automatiskai(studentas, tryCatch(paz_sk));
            vidurkis(studentas, 0);
            studentai.push_back(studentas[0]);

        }
        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        std::cout << std::endl <<"***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << std::endl;
        break;

    case 'r':
    case 'R':
        
        for (int i = 0; i < studentu_sk; i++)
        {
            vardas(studentas, i);
            std::cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
            std::cin >> paz_sk;
            ivedimas_ranka(studentas, tryCatch(paz_sk));
            vidurkis(studentas, i);
            studentai.push_back(studentas[0]);
        }
        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        std::cout << std::endl << "***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << std::endl;
        break;

    case 'f':
    case 'F':
        failo_nuskaitymas(studentai, &paz_sk);
        //rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        std::cout << std::endl << "***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << std::endl;
        break;

    }
    
    system("pause>0");

}


