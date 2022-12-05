# V0.4
Šioje versijoje naudojamos tos pačios funkcijos kaip ir **V0.3** versijoje, tačiau vietoj **std::vector<Duomenys<Duomenys>>** naudojamas **std::list<Duomenys<Duomenys>>** studentų duomenims saugoti.

**Testavimo sistemos parametrai:** 

Processor	Intel(R) Core(TM) i5-3230M CPU @ 2.60GHz, 2601 Mhz, 2 Core(s), 4 Logical Processor(s)

RAM 8 GB

SDD 237 GB

# V0.4 gauti rezultatai
Atlikus programos spartos testą gauti rezultatai parodė, kad, apdorojant failus iš 1000 ir 10000 įrašų, duomenų nuskaitymas bei studentų rūšiavimas į dvi grupes trunka mažiau laiko naudojant _std::list_ tipo konteinerį, tačiau kitais atvejais programa veikia greičiau, kai studentų duomenims saugoti yra naudojamas _std::vector_ tipo konteineris.

**std::list programos spartos rezultatai:**
![rezultatai_list](https://user-images.githubusercontent.com/112932535/205741383-6e4f3f85-27e8-49fc-8f2a-2277718c49b4.PNG)

**std::vector programos spartos rezultatai:**
![rezultatai_vector](https://user-images.githubusercontent.com/112932535/205744555-e903eb55-e3ee-4091-87c5-8985d4257717.PNG)
