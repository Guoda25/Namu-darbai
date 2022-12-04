#include "Skaiciavimai.h"
#include "tryCatch.h"


void vardas(vector<Duomenys>& studentas, int i)
{
    do
    {
        cout << "Iveskite studento nr. " << i + 1 << " varda:\n";
        cin >> studentas[i].Vard;
        cout << endl;
    } while (studentas[i].Vard.length() < 0 || studentas[i].Vard.length() > 25 || tryCatch(studentas[i].Vard) != true);
    do
    {
        cout << "Iveskite studento nr. " << i + 1 << " pavarde:\n";
        cin >> studentas[i].Pav;
        cout << endl;
    } while (studentas[i].Pav.length() < 0 && studentas[i].Pav.length() > 25 || tryCatch(studentas[i].Pav) != true);

}


void ivedimas_automatiskai(vector<Duomenys>& studentas, int i)
{
    int temp;
    vardas(studentas, i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    studentas[i].paz.clear();
    srand(time(0));
    studentas[i].egz = rand() % 10 + 1;

    do
    {
        studentas[i].paz.push_back(rand() % 10 + 1);
    } while (studentas[i].paz.size() < temp);
    
    vid_median(studentas, i, temp);
}


void ivedimas_ranka(vector<Duomenys>& studentas, int i)
{
    int temp, temp2;
    vardas(studentas, i);

    do {

        cin.clear();
        cin.ignore();
        cout << "Iveskite " << i + 1 << "-ojo studento pazymiu skaiciu: ";
        cin >> temp;
        cout << endl;

    } while (cin.fail());

    studentas[i].paz.clear();
    for (int a = 0; a < temp; a++) {

        do {
            cin.clear();
            cin.ignore();
            cout << "Iveskite studento " << a + 1 << "-aji pazymi: ";
            cin >> temp2;
        } while (temp2 < 0 || temp2 > 10 || cin.fail());
        studentas[i].paz.push_back(temp2);

    }

    do {
        cin.clear();
        cin.ignore();
        cout << "Iveskite egzamino pazymi:\n";
        cin >> studentas[i].egz;
    } while (studentas[i].egz < 0 || studentas[i].egz > 10 || cin.fail());

    vid_median(studentas, i, temp);
    
}

void rezultatai(std::vector<Duomenys> studentai) //atspausdina rezultatus
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

void rezultatau_isvedimas_iFaila(vector<Duomenys> studentai)
{
    ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < studentai.size(); i++)
    {
        output << setw(20) << left << studentai[i].Vard
            << setw(20) << left << studentai[i].Pav
            << setw(18) << left << studentai[i].galut
            << studentai[i].median << endl;

    }
    output << "\n\n";

    cout << endl << "***STUDENTU REZULTATUS RASITE FAILE 'kursiokai.txt'***" << endl;
}

void rezultatai_varg_kiet(vector<Duomenys> vargsiukai, vector<Duomenys> kietiakai) {

    auto start = chrono::high_resolution_clock::now();
    ofstream output;
    output.open("vargsiukai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < vargsiukai.size(); i++)
    {
        output << setw(20) << left << vargsiukai[i].Vard
            << setw(20) << left << vargsiukai[i].Pav
            << setw(18) << left << vargsiukai[i].galut
            << vargsiukai[i].median << endl;

    }

    output << "\n\n";

    ofstream output1;
    output1.open("kietiakai.txt");
    output1 << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(18) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n"
        << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < kietiakai.size(); i++)
    {
        output1 << setw(20) << left << kietiakai[i].Vard
            << setw(20) << left << kietiakai[i].Pav
            << setw(18) << left << kietiakai[i].galut
            << kietiakai[i].median << endl;

    }

    output1 << "\n\n";

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Studentu isvedimo i du failus laikas : " << diff.count() << endl;
    cout << endl << "***STUDENTU REZULTATUS RASITE FAILUOSE 'vargsiukai.txt' ir 'kietiakai.txt'***" << endl;
}
