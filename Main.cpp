#include "FailoNuskaitymas.h"
#include "Padalinimas.h"



int main()
{
    int paz_sk;
    int studentu_sk;
    char temp;
    vector<Duomenys> studentai;
    vector<Duomenys> vargsiukai;
    vector<Duomenys> kietiakai;
 
    do
    {
        cout << "Jeigu norite, kad studentu pazymiai butu suvesti automatiskai, iveskite \"A\"\n"
            << "Jeigu studentu pazymius norite suvesti ranka, iveskite \"R\"\n"
            << "Jeigu norite, kad studentu pazymiai butu nuskaityti is failo, iveskite \"F\"\n"
            << "Jeigu norite nuskaityti duomenis is 5 atsitiktinai sugeneruotu failu, iveskite \"G\"\n";
        cin >> temp;
        if (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F' && temp != 'g' && temp != 'G') { cout << "pakartokite, netinkamas simbolis\n"; }
    } while (temp != 'a' && temp != 'A' && temp != 'r' && temp != 'R' && temp != 'f' && temp != 'F' && temp != 'g' && temp != 'G');

    if (temp == 'a' || temp == 'A' || temp == 'r' || temp == 'R') {
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Iveskite studentu skaiciu:\n";
            cin >> studentu_sk;
        } while (studentu_sk < 0 || studentu_sk > 256|| cin.fail());
    }

    switch (temp) {
    case 'a':
    case 'A':

        studentai.resize(studentai.size() + studentu_sk);

        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_automatiskai(studentai, i);          
        }

        rezultatai(studentai);
        break;

    case 'r':
    case 'R':

        studentai.resize(studentai.size() + studentu_sk);

        for (int i = 0; i < studentu_sk; i++)
        {
            ivedimas_ranka(studentai, i);
        }
      
        rezultatai(studentai);
        break;

    case 'f':
    case 'F':
        failo_nuskaitymas(studentai, &paz_sk);
        rezultatau_isvedimas_iFaila(studentai);
        break;

    case 'g':
    case 'G':

        
        //failo_generavimas(1000);
        failo_nuskaitymas1(studentai, 1000, &paz_sk);
        studentu_isskaidymas(studentai, vargsiukai, kietiakai);
        rezultatai_varg_kiet(vargsiukai, kietiakai);
        studentai.clear();
        vargsiukai.clear();
        kietiakai.clear();
        cout << "\n\n";

        //failo_generavimas(10000);
        //failo_nuskaitymas1(studentai, 10000, &paz_sk);
        //studentu_isskaidymas(studentai, vargsiukai, kietiakai);
        //rezultatai_varg_kiet(vargsiukai, kietiakai);
        //studentai.clear();
        //vargsiukai.clear();
        //kietiakai.clear();
        //cout << "\n\n";
        
        //failo_generavimas(100000);
        //failo_nuskaitymas1(studentai, 100000, &paz_sk);
        //studentu_isskaidymas(studentai, vargsiukai, kietiakai);
        //rezultatai_varg_kiet(vargsiukai, kietiakai);
        //studentai.clear();
        //vargsiukai.clear();
        //kietiakai.clear();
        //cout << "\n\n";

        ////failo_generavimas(1000000);
        //failo_nuskaitymas1(studentai, 1000000, &paz_sk);
        //studentu_isskaidymas(studentai, vargsiukai, kietiakai);
        //rezultatai_varg_kiet(vargsiukai, kietiakai);
        //studentai.clear();
        //vargsiukai.clear();
        //kietiakai.clear();
        //cout << "\n\n";

        ////failo_generavimas(10000000);
        //failo_nuskaitymas1(studentai, 10000000, &paz_sk);
        //studentu_isskaidymas(studentai, vargsiukai, kietiakai);
        //rezultatai_varg_kiet(vargsiukai, kietiakai);
        //studentai.clear();
        //vargsiukai.clear();
        //kietiakai.clear();
        break;
    }
 
    system("pause>0");

}
