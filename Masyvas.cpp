#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
#include<algorithm>


struct Duomenys {
    std::string Vard, Pav;
    int paz[50] = {0};
    int egz;
    float galut = 0;
};

void mediana(int pazymiai[]);

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
    switch (temp) {
    case 'a':
    case 'A':
        do
        {
            std::cout << "Iveskite studentu kieki:\n";
            std::cin >> studentu_sk;
        } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);


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
        do
        {
            std::cout << "Iveskite studentu kieki:\n";
            std::cin >> studentu_sk;
        } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
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

void mediana(int pazymiai[])
{
    
    int counter = 0;
    for (int i = 0; i < 50; i++)
    {
        if (pazymiai[i] > 0)
        {
            counter++;
        }
    }

    std::sort(pazymiai, pazymiai+50, [](int& a, int& b) { return a > b; });

    if (counter % 2 == 0)
    {
        std::cout << round(float(((pazymiai[(counter / 2) - 1]) + (pazymiai[(counter / 2)])) / 2.0) * 100) / 100;
    }
    else
    {
        std::cout << round((pazymiai[(counter / 2)]) * 100) / 100;
    }
    std::cout << std::endl;

    /*for (int x = 0; x < 50; x++) {
        std::cout << pazymiai[x];
    }
    std::cout << std::endl;*/
}

void vidurkis(Duomenys studentas[], int i)

{
    float counter = 0;
    for (int x = 0; x < 50; x++)
        if (studentas[i].paz[x] > 0)
        {
            counter++;
        }
      
    float sum = 0;
   

    for (int x = 0; x < 50; x++)
    {
        sum += studentas[i].paz[x];
    } 
  
    studentas[i].galut = sum / counter;
    studentas[i].galut = round((studentas[i].galut * 0.4 + 0.6 * studentas[i].egz) * 100) / 100;
}



void ivedimas_automatiskai(Duomenys studentas[], int i, int a)
{   
    srand(time(0));
    studentas[i].egz = rand() % 10 + 1;
    for (int x = 0; x < a; x++)
        {
            studentas[i].paz[x] = rand() % 10 + 1;
        };

}


void ivedimas_ranka(Duomenys studentas[], int i, int paz_sk)
{
    
    for (int a = 0; a < paz_sk; a++) {

        std::cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
        std::cin >> studentas[i].paz[a];

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
    do {
        std::cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        std::cin >> studentas[i].Vard;
    } while (studentas[i].Vard.length() < 0 || studentas[i].Vard.length() > 25 || has_digit(studentas[i].Vard));
    do {
        std::cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        std::cin >> studentas[i].Pav;
    } while (studentas[i].Pav.length() < 0 && studentas[i].Pav.length() > 25 || has_digit(studentas[i].Pav));
    std::cout << std::endl;
}

void rezultatai(Duomenys studentas[], int studentu_sk) //atspausdina rezultatus
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