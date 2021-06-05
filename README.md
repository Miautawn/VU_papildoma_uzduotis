# VU_papildoma_užduotis
Ši programa nuskaito jūsų norimą teksto failą ir pateikia visų žodžių dažnio, "cross-reference" lentelės bei išrenka visus URL iš teksto.

## Programos pavyzdys
### teksto failas
```
Iron Wolf
The neighborhoods of Vilnius also have names in other find_me.com languages, which represent the languages spoken by various ethnic groups in the area.

According to legend, Grand Duke Gediminas (c. 1275–1341) was hunting in the sacred forest near the Valley of Šventaragis, near where the Vilnia River flows into the Neris River. Tired after the successful hunt of a wisent, the Grand Duke settled in for the night. He fell soundly asleep and dreamed of a huge Iron Wolf standing on top a hill and howling as strong and loud as a hundred wolves. Upon awakening, the Duke asked the krivis (pagan priest) Lizdeika to interpret the dream. The priest told him,

"What is destined for the ruler and the State of Lithuania, is thus: the Iron Wolf represents a castle and a city which will be established by you on this site. This city will be the capital of the Lithuanian lands and the dwelling of their rulers, and the glory of their deeds shall echo throughout the world."
```
Tai yra vikipedijos straipnio apie Vilnių ištrauka.

### word_table failas (santrauka)
```
word              count
----------------------
A                   4
AK                  2
Act                 3
After               3
Although            2
April               2
Army                12
```
Šiame faile yra pateikti visi žodžiai, kurie pasikartoja daugiau nei 1 kartą ir pateiktas jų skaičius.

### cross_reference_table failas (santaruka)
```
word              1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 
A                       *                                                                                                                                                                                                            *                       *
AK                                                                                                                                                                                                                                                                 *
Act                                                                                                                                                                   *        *                                         *
After                                                        *                                                                                   *                                                                                               *
Although                                                                                                                             *                                                        *
April                                                                                                                                *                                                                                                                             *
Army                                                                                                                                       *                                   *        *     *                                   *  *           *                 *
```
Šiame faile pateikiami visi žodžiai, kurie pasikartojo daugiau nei 1 kartą, ir parodoma, kuriose eilutėse jie buvo.

### url failas
```
www.not_virus_free_money.com
find_me.com
http://www.easter_egg.com
www.hide_and_seek.crypto
```

## Naudojimo instrukcija
1. Programai paprašius, įrašykite tekstinio failo pavadinimą:
```shell
>> Enter the input file: text.txt
```
2. Viskas! Žodžių dažnių lentelė bus `word_table.txt`, "cross-reference" lenelė `cross-reference-table.txt`, o URL `url.txt` failuose.

## Diegimo istrukcija
1. atsisiųsti main.cpp ir main.hpp failus
2. sukompiliuoti juos c++11 kompiliatoriumi:
```
g++ -o program main.cppp
```
3. pasileisti programos failą!
