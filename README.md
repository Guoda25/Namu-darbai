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
