# Naudojimosi instrukcija

Paleidus programą galite pasirinkti:
![ins](https://user-images.githubusercontent.com/112932535/206494637-89534a4c-f5df-4440-91b5-9b1bab49d80a.PNG)

Pasirinkus **A**:
  1. Įveskite studentų skaičių;
  2. Įveskite studento vardą;
  3. Įveskite studento pavardę;
  4. Įveskite studento namų darbų pažymių skaičių;
  5. Pasirinke ar norite, kad studento galutinis balas būtų skaičiuojamas pagal formulę, ar, kad tai būtų jo namų darbų pažymių medina.
  
Rezultatai yra išvedami į ekraną.

*Žingsniai 2-4 kartojasi priklausamai nuo studentų skaičiaus.

Pasirinkus **R**:
  1. Įveskite studentų skaičių;
  2. Įveskite studento vardą;
  3. Įveskite studento pavardę
  4. Įveskite studento namų darbų pažymių skaičių.
  5. Įveskite studento namų darbų pažymius;
  6. Įveskite studento egzamino pažymį;
  7. Pasirinke ar norite, kad studento galutinis balas būtų skaičiuojamas pagal formulę, ar, kad tai būtų jo namų darbų pažymių medina.
  
Rezultatai yra išvedami į ekraną.

*Žingsniai 2-6 kartojasi priklausamai nuo studentų skaičiaus.

Pasirinkus **F**:

  Programa automatiškai nuskaito studentų duomenis iš "studentai1000000.txt" failo ir išveda rezultatus į naują tekstinį failą "kursiokai.txt"
  
Pasirinkus **G**:  
  
  Programa automatiškai nuskaito studentų duomenis iš 5 atsitiktinai sugeneruotų failų, atspausdina į ekraną porgramos veikimo spartos rezultatus ir išveda studentų     rezultatus (iš studentai_10000000.txt failo) į du naujus tekstinius failus "vargsiukai.txt" ir "kietiakai.txt" 


# V1.0

Šioje versijoje galima atlikti programos spartos testą, kuris matuoja studentų rūšiavimo į dvi grupes strategijų laiką.
Iš viso programoje yra 4 strategijos. 

**Naudotos startegijos:**

Strategija nr. 1 (naudojama ir _std::list_ tipo konteineriui)
```c++
 for (vector<Duomenys1>::iterator it = studentai.begin(); it != studentai.end(); it++) {

        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);
        }
        else {
            kietiakai.push_back(*it);
        }
    }
    studentai.clear();
```
   
    
Strategija nr. 2 (naudojama ir _std::list_ tipo konteineriui)

```c++
 int a = studentai.size() - 1;
    for (int i = a; i > -1; i--) {

        vector<Duomenys1>::iterator it = studentai.begin();
        advance(it, i);
        if (it->galut < 5.00) {
            vargsiukai.push_back(*it);
            studentai.erase(it);
        }
    } 
 ```
 
 Strategija nr.1 pritaikius **copy_if** algoritmą (naudojama tik _std::vector_ tipo konteineriui)
 
 ```c++
 copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), vargsiuku_paz1);//vargsiuku_paz1 grąžina galutinį balą mažesnį nei 5.00
 copy_if(studentai.begin(), studentai.end(), back_inserter(kietiakai), kietiaku_paz);//kietiaku_paz grąžina galutinį balą didenį arba lygu 5.00
 studentai.clear();
 ```
  Strategija nr.2 pritaikius **copy_if** ir **remove_if** algoritmus (naudojama tik _std::vector_ tipo konteineriui)
  ```c++
  copy_if(studentai.begin(), studentai.end(), back_inserter(vargsiukai), vargsiuku_paz1);
  studentai.erase(remove_if(studentai.begin(), studentai.end(), vargsiuku_paz1), studentai.end());
 ```
# V1.0 gauti rezultatai
Gauti rezultati parodė: 

1. Geriausia strategija ***std::list*** tipo konteineriui yra **strategija nr. 1**. Matome, kad strategija nr. 2 su 100000 įrašų veikė ~1000 kartų lėčiau, todėl ši strategija didesniems failams nebebuvo testuojama. 

2. Geriausia startegija ***std::vector*** tipo konteineriui yra **strategija nr. 2 pritaikius _copy_if_ ir _remove_if_**. Nors strategija nr. 2 _std::vector_ tipo konteineriui veikia greičiau nei _std::list_ tipo koneineriui, tačiau matome, kad strategijos nr. 2 veikimo sparta smarkiai skiriasi nuo kitų strategijų veikimo spartos, todėl ši strategija didesniems failams taip pat nebebuvo testuojama.

![rezultatai_vector_list](https://user-images.githubusercontent.com/112932535/206483283-0ed9d1b5-8df4-4a3d-adc7-1c918a634c30.PNG)

# V0.4
Šioje versijoje naudojamos tos pačios funkcijos kaip ir **V0.3** versijoje, tačiau vietoj **std::vector<Duomenys<Duomenys>>** naudojamas **std::list<Duomenys<Duomenys>>** studentų duomenims saugoti.

**Testavimo sistemos parametrai:** 

Processor	Intel(R) Core(TM) i5-3230M CPU @ 2.60GHz, 2601 Mhz, 2 Core(s), 4 Logical Processor(s)

RAM 8 GB

SDD 237 GB

# V0.4 gauti rezultatai
Atlikus programos spartos testą gauti rezultatai parodė, kad, tekstinio failo nuskaitymui konteinerio tipas didėlės įtakos nedaro, kadangi tai užtrunka beveik tiek pat laiko tiek naudojant _std::vector_, tiek _std::list_, tačiau studentų rūšiavimas į dvi grupes trunka kur kas mažiau laiko, jei yra naudojamas _std::vector_ tipo konteineris.

**std::list programos spartos rezultatai:**
![rezultatai_list1](https://user-images.githubusercontent.com/112932535/206321207-81fc59d2-eeda-47eb-8f3d-00d423a1adbf.PNG)


**std::vector programos spartos rezultatai:**
![rezultatai_vector1](https://user-images.githubusercontent.com/112932535/206321235-f2eab2e8-eda3-4abc-850b-fbce6c4e6ece.PNG)

# V0.3

Patobulinta V0.2 versija, papildomai leidžia pasirinkti, kad studentų duomenis būtų nuskaityti iš 5 atsitiktinai sugeneruotų failų ("studentai_1000.txt", "studentai_10000.txt", "studentai_100000.txt", "studentai_1000000.txt", "studentai_10000000.txt"), taip pat, suskaičiuoją:

1. Studentų duomenų nuskaitymo iš failo laiką;

2. Studentų padalijimo į dvi kategorijas laiką;

3. Studentų išvedimo į naujus failus pagal kategoriją laiką.

Nuo šios versijos programoje yra naudojama `using namespace std`.

Papildomos funkcijos ir jų header failai:

**1. FailoGeneravimas.h**

_failo_generavimas()_ - sugeneruoja pasirinkto dydžio failą su studentų pažymiais.

**2. FailoNuskaitymas.h**

_failo_nuskaitymas1()_ - atlieka tą pačia funkcija kaip ir _failo_nuskaitymas()_, tik iškviečiant šią funkciją galima pasirinkti kokio dydžio failą norėsime, kad funkcija nuskaitytų; 

**3. Ivedimas.h**

_rezultatai_varg_kiet()_ - išveda jau į dvi kategorijas (vargšiukai ir kietiakai) padalintų studentų rezultatus į du atskirus tekstinius failus "vargsiukai.txt" ir "kietiakai.txt";

**4. Lib.h** - saugomos programoje naudojamos bibliotekos, kurios V0.2 versijoje buvo saugomos "Skaiciavimai.h";

**5. Padalinimas.h**

_studentu_isskaidymas()_ - funkcija patikrina studentų galutinį balą, studentai gavę mažiau nei 5.00 keliauja į vargšiukų kategoriją, likę į kietiakų kategoriją.

# V0.3 gauti rezultatai


![rezultatai_vector1](https://user-images.githubusercontent.com/112932535/206320744-5789ed68-308f-417a-af66-2def5e7c9821.PNG)

# V0.2
V0.1.1 patobulinimas.

Programą papildo funkcija, kuri leidžia duomenis apie studentus nuskaityti iš tekstinio failo bei visų studentų rezultatus išveda į nauja tekstinį failą _"kursiokai.txt"_.

Programoje yra 5 cpp failai ir 4 header failai:

**1. FailoNuskaitymas.h**

_failo_nuskaitymas()_ - nuskaito failą, išsaugo studentų duomenis į vektorių ir iškviečia funkciją _vid_median()_.

**2. Ivedimas.h** 

_vardas()_ - leidžia vartotojui įvesti studento vardą ir pavardę;

_ivedimas_automatiskai()_ - iškviečia funkciją _vardas()_, atsitiktinai sugeneruoja studentų egzamino ir namų darbų pažymius, iškviečia funkciją _vid_median()_;

_ivedimas_ranka()_ - iškviečia funkciją _vardas()_, leidžia vartotojui įvesti studentų egzamino ir namų darbų pažymius, iškviečia funkciją _vid_median()_;

_rezultatai()_ - surūšiuoja studentus pagal pavardes ir išveda jų rezultatus į ekraną;

_rezultatau_isvedimas_iFaila()_ - surūšiuoja studentus pasgal pavardes ir išveda jų rezultatus į tekstinį failą _"kursiokai.txt"_.;

**3. Skaiciavimai.h**

_struct Duomenys {}_

_comparePagalPav()_ - palygina studentų pavardes ir grąžina mažesnę reikšmę;

_vid_median()_ - suskaičiuoja studentų galutinį pažymį pagal formulę ir randa namų darbų pažymių medianą;

**4. TryCatch.h** 

_tryCatch()_ - Patikrina ar vartotojas nepadarė klaidų įvesdamas studentų duomenis (pvz. vesdamas studento vardą vietoj raidės įrašė skaičių arba simbolį).

**Dar viena _Try Catch_ funkcijos realizacija programoje:** 
```C++
try {
        if (!myFile)
            throw "NEPAVYKO ATIDARYTI FAILO!\n";
    }
catch (const char* txtException) {
        cout << txtException;
        exit(1);
    }
```
# V0.1.1
Pataisyta (versijos V0.1) versija **V01.1**.
2 cpp failai: _Vektoriai.cpp_ ir _Masyvas.cpp_.
Programa suskaičiuoja studento galutį pažymį.

Programa leidžia pasirinkti:

1. Kad studentų namų darbų pažymiai būtų suvesti ranka arba, kad jie būtų sugeneruoti automatiškai;

2. Studentų skaičių;

3. Kiekvieno studento pažymių skaičių;

4. Kad studentų galutinis balas būtų jų namų darbų pažymių mediana arba, kad galutinis balas būtų suskaičiuotas pagal formulę.

Formulė naudojama galutiniui balui suskaičiuoti:

<img src="https://latex.codecogs.com/svg.image?galutinis&space;=&space;egzaminas&space;*&space;0,6&space;&plus;&space;\frac{\sum_{i=1}^{n}&space;nd_i}{n}&space;*&space;0,4" title="https://latex.codecogs.com/svg.image?galutinis = egzaminas * 0,6 + \frac{\sum_{i=1}^{n} nd_i}{n} * 0,4" />

