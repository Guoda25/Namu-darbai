#include "Padalinimas.h"
#include "FailoGeneravimas.h"


int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    Duomenys studentas;
    list<Duomenys> studentai;
    list<Duomenys> vargsiukai;
    list<Duomenys> kietiakai;
    vector<Duomenys1> studentai1;
    vector<Duomenys1> vargsiukai1;
    vector<Duomenys1> kietiakai1;

    do
    {
        cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\n"
            << "Jeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n"
            << "Jeigu norite, kad studentu pazymiai butu nuskaityti is failo, iveskite \"F\"\n"
            << "Jeigu norite nuskaityti duomenis is 5 atsitiktinai sugeneruotu failu ir atlikti programos spartos testa, iveskite \"G\"\n";
        cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F' && temp != 'g' && temp != 'G') {
            cout << "pakartokite, netinkamas simbolis\n";
        }

    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F' && temp != 'g' && temp != 'G');

    if (temp == 'a' || temp == 'A' || temp == 'r' || temp == 'R') {
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Iveskite studentu skaiciu:\n";
            cin >> studentu_sk;
        } while (studentu_sk < 0 || studentu_sk > 256 || cin.fail());
    }

    switch (temp) {
    case 'a':
    case 'A':

        for (int i = 0; i < studentu_sk; i++)
        {
            studentai.push_back(studentas);
            ivedimas_automatiskai(studentai, i);
        }

        rezultatai(studentai);    
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'r':
    case 'R':

        for (int i = 0; i < studentu_sk; i++)
        {
            studentai.push_back(studentas);
            ivedimas_ranka(studentai, i);
        }
            
        rezultatai(studentai);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'f':
    case 'F':

        failo_nuskaitymas(studentai, &paz_sk);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'g':
    case 'G':


        //vector
        cout << "Programos spartos testas" << setw(48) << right << "vector" << endl << endl;
        cout << "1000 irasu" << endl;
        test_V(studentai1, vargsiukai1, kietiakai1, 1000);
        cout << "10000 irasu" << endl;
        test_V(studentai1, vargsiukai1, kietiakai1, 10000);
        cout << "100000 irasu" << endl;
        test_V(studentai1, vargsiukai1, kietiakai1, 100000);
        cout << "1000000 irasu" << endl;
        test_V(studentai1, vargsiukai1, kietiakai1, 1000000);
        cout << "10000000 irasu" << endl;
        test_V(studentai1, vargsiukai1, kietiakai1, 10000000);

        //list
        cout << "Programos spartos testas" << setw(46) << right << "list" << endl << endl;
        cout << "1000 irasu" << endl;
        test_L(studentai, vargsiukai, kietiakai, 1000);
        cout << "10000 irasu" << endl;
        test_L(studentai, vargsiukai, kietiakai, 10000);
        cout << "100000 irasu" << endl;
        test_L(studentai, vargsiukai, kietiakai, 100000);
        cout << "1000000 irasu" << endl;
        test_L(studentai, vargsiukai, kietiakai, 1000000);
        cout << "10000000 irasu" << endl;
        test_L(studentai, vargsiukai, kietiakai, 10000000);
        
        break;
    }

    system("pause>0");

}

