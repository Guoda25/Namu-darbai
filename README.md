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

**_Try Catch_ funkcijos realizacija programoje:** 
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
