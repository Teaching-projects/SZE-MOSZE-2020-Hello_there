# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Tálos Botond | @Holdmedve | +1 | 50-60 | Lehetett rá számítani. |
| Gfellner Máté | @gfellnerm | 0 | 20-30 | Kutatási munkában sokat segített. |
| Bakos Dániel | @BakiHUN | +1 | 50-60 | Szépen csinálta a dolgát. |


# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | -2 | 2 | @hegyhati | 
| Feladat 2 | -1 | 1 | @hegyhati |
| jsonparser | -3 | 2 | @wajzy |
| levelup | +3 | 3 | @oliverosz |
| attackspeed | -3 | 0 | @vizvezetek |
| documentation | +2 | 0 | @Bukottak_busszuja / @tothi517,@HabanAndras |
| unittest | -1 | 0 | @Bukottak_busszuja  / @tothi517, @HabanAndras |
| makefile | +2 | 1 | @hegyhati |
| refactor | +4 | 0 | @hegyhati |
| docker | +11 | 1 | @hegyhati |
| jsonpimp | Merge: 11.26 | 0 | @Bukottak_busszuja / @HabanAndras |
| map | Merge: 11.25 | 1 | @Bukottak_busszuja / @HabanAndras |
| game | Merge: 11.30 | 0 | @Bukottak_busszuja / @tmate93 |
| defense | Merge: 11.28 | 0 | @Bukottak_busszuja / @tmate93 |
| damage | Nem készült el | Valahogy kifelejtettük? | - |
| markedmap | Merge: 12.01 | 0 | @Bukottak_busszuja / @HabanAndras |
| preparedgame | Merge: 12.04 | 0 | @Bukottak_busszuja / @HabanAndras |
| light radius | Merge: 12.05 | 0 | @Bukottak_busszuja / @HabanAndras |
| rendering | Merge: mm.dd | ... | @Bukottak_busszuja / @tothi517 |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Monster` | 16 | 5 | 3 |
| `Hero` | 7 | 3 | 5 | 
| `Game` | 21 | 4 | 3 |
| `PreparedGame` | 1 | 1 | 2 |
| `Map` | 4 | 2 | 4 |
| `MarkedMap` | 4 | 4 | 7 |
| `JSON` | 8 | 5 | 6 |
| `Renderer` | 1 | 1 | 8 |
| `TextRenderer` | 4 | 2 | 4 |
| `SVGRenderer` | 2 | 2 | 4 |
| `HeroTextRenderer` | 3 | 3 | 2 |
| `ObserverTextRenderer` | 3 | 3 | 2 |
| `HeroSVGRenderer` | 2 | 2 | 2 |
| `ObserverSVGRenderer` | 2 | 2 | 2 |

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- | 
| `Monster` | ... | `JSON` | 
| `Hero` | ... | ... |  
| `Game` | ... | ... |
| `PreparedGame` | ... | ... |
| `HeroSVGRenderer` | ... | ... |
| `HeroTextRenderer` | ... | ... |
| `Map` | ... | ... |
| `MarkedMap` | ... | ... |
| `ObserverSVGRenderer` | ... | ... |
| `ObserverTextRenderer` | ... | ... |


# Mindenféle számok

 - Összes cpp kódsor : 1640
 - Egyéb kódsor (make,doxyfile,shellscript,header,cmake,json,docker) : 1024
 - cppcheck
   - warning : 0
   - style : 0
   - performance : 0
   - unusedFunction : 0
   - missingInclude : 1
 
# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető shell/python scripting
 - `std::variant`
 - `std::regex`
 - `std::Csapatmunka::összedolgozás`