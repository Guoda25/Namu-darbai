#include "Skaiciavimai.h"
#include "tryCatch.h"


void vardas(list<Duomenys>& studentas, list<Duomenys>::iterator it, int i)
{

    do{
        cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        cin >> it->Vard;
        
        cout << endl;
    } while (it->Vard.length() < 0 || it->Vard.length() > 25 || tryCatch(it->Vard) != true);

    do{
        cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        cin >> it->Pav;
        cout << endl;
    } while (it->Pav.length() < 0 && it->Pav.length() > 25 || tryCatch(it->Pav) != true);

}


void ivedimas_automatiskai(list<Duomenys>& studentas, int i)
{   
    list<Duomenys>::iterator it = studentas.begin();
    advance(it, i);
    int temp;
    vardas(studentas, it, i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    srand(time(0));
    it->egz = rand() % 10 + 1;

    do
    {
        it->paz.push_back(rand() % 10 + 1);
    } while (it->paz.size() < temp);

    vid_median(studentas, it, temp);

}


void ivedimas_ranka(list<Duomenys>& studentas, int i)
{

    list<Duomenys>::iterator it = studentas.begin();
    advance(it, i);
    int temp, temp2;
    vardas(studentas, it, i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    for (int a = 0; a < temp; a++) {

        do {
            cin.clear();
            cin.ignore();
            cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
            cin >> temp2;
        } while (temp2 < 0 || temp2 > 10 || cin.fail());
        it->paz.push_back(temp2);

    }

    do {
        cin.clear();
        cin.ignore();
        cout << "Iveskite egzamino pazymi:\n";
        cin >> it->egz;
    } while (it->egz < 0 || it->egz > 10 || cin.fail());

    vid_median(studentas, it, temp);

}

void rezultatai(list<Duomenys> studentai)
{
    char temp;
    studentai.sort(comparePagalPav);

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
        for (list<Duomenys>::iterator it = studentai.begin(); it != studentai.end(); it++)
        {
            std::cout << std::setw(20) << std::left << it->Vard
                << std::setw(20) << std::left << it->Pav
                << std::setw(18) << std::left << it->median << std::endl;

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
        for (list<Duomenys>::iterator it = studentai.begin(); it != studentai.end(); it++)
        {
            std::cout << std::setw(20) << std::left << it->Vard
                << std::setw(20) << std::left << it->Pav
                << std::setw(18) << std::left << it->galut << std::endl;

        }

        std::cout << "\n\n";

    }
}

void rezultatau_isvedimas_iFaila(list<Duomenys> studentai)
{
    studentai.sort(comparePagalPav);
    ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/ Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (list<Duomenys>::iterator it = studentai.begin(); it != studentai.end(); it++)
    {
        output << setw(20) << left << it->Vard
            << setw(20) << left << it->Pav
            << setw(18) << left << it->galut
            << it->median << endl;

    }
    output << "\n\n";

    cout << endl << "***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << endl;
}

void rezultatai_varg_kiet(list<Duomenys> vargsiukai, list<Duomenys> kietiakai) {
    
    vargsiukai.sort(comparePagalPav);
    kietiakai.sort(comparePagalPav);
    ofstream output;
    output.open("vargsiukai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/ Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (list<Duomenys>::iterator itV = vargsiukai.begin(); itV != vargsiukai.end(); itV++)
    {
        output << setw(20) << left << itV->Vard
            << setw(20) << left << itV->Pav
            << setw(18) << left << itV->galut
            << itV->median << endl;

    }

    output << "\n\n";

    ofstream output1;
    output1.open("kietiakai.txt");
    output1 << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/ Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (list<Duomenys>::iterator itK = kietiakai.begin(); itK != kietiakai.end(); itK++)
    {
        output1 << setw(20) << left << itK->Vard
            << setw(20) << left << itK->Pav
            << setw(18) << left << itK->galut
            << itK->median << endl;

    }
    output1 << "\n\n";

    //cout << endl << "***STUDENTU REZULTATUS RASITE FAILUOSE 'vargsiukai.txt' ir 'kietiakai.txt'***" << endl;
}



