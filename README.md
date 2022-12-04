# V0.3

Patobulinta V0.2 versija, papildomai leidžia pasirinkti, kad studentų duomenis būtų nuskaityti iš 5 atsitiktinai sugeneruotų failų ("studentai_1000.txt", "studentai_10000.txt", "studentai_100000.txt", "studentai_1000000.txt", "studentai_10000000.txt"), taip pat, suskaičiuoją:

1. Studentų duomenų nuskaitymo iš failo laiką;

2. Studentų padalijimo į dvi kategorijas laiką;

3. Studentų išvedimo į naujus failus pagal kategoriją laiką.

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

