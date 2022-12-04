#include <iostream>
#include <string>
#include <iomanip>
#include <numeric>
#include<algorithm>

struct Duomenys {
    std::string Vard, Pav;
    int paz[50] = {0};
    int egz;
    float galut;
    float median;
};

void vid_median(Duomenys studentas[], int i, int paz_sk);

void ivedimas_automatiskai(Duomenys studentas[], int i);

void ivedimas_ranka(Duomenys studentas[], int i);

bool has_digit(std::string s);

bool comparePagalPav(const Duomenys& x, const Duomenys& y);

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
    
    do
    {
        std::cout << "Iveskite studentu kieki:\n";
        std::cin >> studentu_sk;
    } while (int(studentu_sk) < 0 || int(studentu_sk) > 256);
    
    Duomenys * studentai = new Duomenys[studentu_sk];
    
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

    rezultatai(studentai, studentu_sk);
    delete[]studentai;
    studentai = NULL;
    system("pause>0");
    
}

void vid_median(Duomenys studentai[], int i, int paz_sk){

    //suskaiciuoja studento galutini bala:
    float counter = 0;
    for (int x = 0; x < 50; x++)
        if (studentai[i].paz[x] > 0)
        {
            counter++;
        }

    float sum = 0;


    for (int x = 0; x < 50; x++)
    {
        sum += studentai[i].paz[x];
    }

    studentai[i].galut = sum / counter;
    studentai[i].galut = round((studentai[i].galut * 0.4 + 0.6 * studentai[i].egz) * 100) / 100;


    //surusiuoja studento namu darbu pazymius ir randa mediana
    std::sort(studentai[i].paz, studentai[i].paz + 50, [](int& a, int& b) { return a > b; });
    if (paz_sk % 2 == 0)
    {
        studentai[i].median = float((studentai[i].paz[((paz_sk / 2) - 1)] + studentai[i].paz[((paz_sk / 2))]) / 2.0);
    }
    else
    {
        studentai[i].median = float(studentai[i].paz[(paz_sk / 2)]);
    }
}


void ivedimas_automatiskai(Duomenys studentas[], int i){   

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

    for (int x = 0; x < temp; x++)
    {
        studentas[i].paz[x] = rand() % 10 + 1;
    };

    vid_median(studentas, i, temp);

}


void ivedimas_ranka(Duomenys studentas[], int i){

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
        studentas[i].paz[a] = temp2;

    }

    do {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Iveskite egzamino pazymi:\n";
        std::cin >> studentas[i].egz;
    } while (studentas[i].egz < 0 || studentas[i].egz > 10 || std::cin.fail());

    vid_median(studentas, i, temp);

}

bool has_digit(std::string s){
    return (s.find_first_of("0123456789") != std::string::npos);
}

bool comparePagalPav(const Duomenys& x, const Duomenys& y) {
        return x.Pav < y.Pav;
}

void vardas(Duomenys studentas[], int i){

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

void rezultatai(Duomenys studentai[], int studentu_sk){ 

    std::sort(studentai, studentai+studentu_sk, comparePagalPav);
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
        for (int i = 0; i < studentu_sk; i++)
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
        for (int i = 0; i < studentu_sk; i++)
        {
            std::cout << std::setw(20) << std::left << studentai[i].Vard
                << std::setw(20) << std::left << studentai[i].Pav
                << std::setw(18) << std::left << studentai[i].galut << std::endl;

        }

        std::cout << "\n\n";

    }
}
