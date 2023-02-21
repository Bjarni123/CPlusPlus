# FORR3CG Vor 2022 - Lokaverkefni (20%)

Áður en lengra er haldið skalt þú stofna nýtt **private** repo á github og bjóða *gestskoli* inn sem samstarfsaðila. Farðu svo inn á Innu og skila slóðinni að repo-inu í annaðhvort **Lokaverkefni** skilahólfið.


  - [Almennar reglur varðandi verkefnið](#almennar-reglur-varðandi-verkefnið)
    - [Skýrsla](#skýrsla)
    - [Námsmat](#námsmat)
  - [Skil verkefnisins](#skil-verkefnisins)
  - [Verkefnið](#verkefnið)
    - [Búnaðarlisti Tækniskólans](#búnaðarlisti-tækniskólans)
    - [Grunnkröfur](#grunnkröfur)
    - [Dæmi um aukakröfur](#dæmi-um-aukakröfur)
  - [Prófunargögn](#prófunargögn)
    - [Prófunargögn í svigum](#prófunargögn-í-svigum)

## Almennar reglur varðandi verkefnið

- Verkefnið er einstaklingsverkefni. Ef tveir eða fleiri nemendur skila sömu lausnunum er gefið 0 (núll) fyrir þær lausnir.
- Ef kóði er tekinn af netinu (eða öðrum álíka stöðum) skal taka það fram, benda á hvaðan hann kemur og skrifa skýringar (e. comment) við hverja línu kóðans. Sé það ekki gert verður gefið 0 (núll) fyrir verkefnið.
- Ekki er heimilt að nota tilbúnar lausnir fyrir listann. Notið ekki auto og allir bendar (e. pointer) skulu vera hráir (e. raw).
- Allur kóði skal skrifaður í C++. Skipta á hverjum klasa í cpp og h skrár (þarf ekki fyrir `node` klasa).
  
### Skýrsla

Halda skal utan um verkefnið á github. Þar á að vera allur kóði ásamt dagbók og skýrslu. Í dagbókinni á að halda utan um hvað er gert og hvenær (ef eitthvað er ekki í dagbókinni þá er það ekki í verkefninu). Skýrslan er svo stutt samantekt á dagbókinni ásamt útskýringum á hvernig forritið ykkar vinnur. Þar eiga líka að vera leiðbeiningar fyrir viðmótið sem þið skrifið. Skilið einnig stuttu myndbandi (screen record) þar sem virkni forritsins er sýnd.

:warning: Ekki er gefin sérstök einkunn fyrir skýrsluna og það sem á að vera í henni en vanti eitthvað af því sem á að vera í skýrslunni eða það ekki vel unnið kemur það til mikillar lækkunar á einkunn verkefnisins.

Sniðmát fyrir skýrsluna má finna [hér](./snidmat.md).

### Námsmat

Við mat á verkefninu er horft til eftirfarandi (ekki tæmandi listi):
- Virkni
- Lýsandi nöfn á:
  - Breytum.
  - Föllum og færibreytum þeirra.
  - Klösum, gagnaklasar heiti eintöluorðum og byrji á stórum staf.
- Snyrtilega upp settur kóði.
- Skýringar (e. comment) notaðar þar sem það á við.
- Verkefnið unnið jafnt og þétt (commit á github).

## Skil verkefnisins

Verkefnið á að skilast í síðasta lagi á miðnætti miðvikudaginn 1. mars. Ekki verður hægt að fá lengri frest.

## Verkefnið

### Búnaðarlisti Tækniskólans

Húsumsjón Tækniskólans hefur beðið þig um skrifa hugbúnað til að halda utan um ýmsan búnað sem skólinn á og hvar sá búnaður er staðsettur. 

Allur búnaður hefur auðkenni, verðmæti og staðsetningu:
- Auðkennið er einkvæm heiltala (ekki sjálfhækkandi (e. auto increment)).
- Verðmætið er í krónum.
- Staðsetningin fimm stafa samsett heiltala sem samanstendur af húsi, hæð og svo herbergi. Dæmi um staðsetningu er 21206 þar sem fyrstu tveir stafirnir (21) merkir Háteigsvegur aðalhús, þriðja talan (2) merkir önnur hæð og svo síðustu tveir stafirnir (06) merkja stofa nr. 6. Staðsetninguna á að geyma í þriggja staka `char` fylki til að spara pláss en það þarf að vera hægt að vinna með staðsetninguna sem eina tölu.
  - Klasinn þarf að geta tekið inn heiltölu og dreift henni svo í þrjú stök fylkisins.
  - Klasinn þarf að geta skilað heiltölu með tölunum úr fylkinu.
  - Klasinn þarf að eiga föll eins og getHus(), getHaed() og getHerbergi() og samsvarandi set föll.

Sá búnaður sem Húsumsjónin vill geta skráð í þessum hugbúnaði eru:
  - Borð, aukalega þarf að skrá hversu margir geta setið við borðið.
  - Stóll, aukalega þarf að skrá hvort stóllinn er snúningsstóll eða ekki.
  - Skjávarpi, aukalega þarf að skrá hversu mörg lumens skjávarpinn er.
  - Tölva, aukalega þarf að skrá kaupár tölvunnar.

### Grunnkröfur

Verkefnið er 100 stig. Fullkomin lausn á grunnkröfum gefur 40 - 60 stig eftir því hvaða leið er valin fyrir listann.

Gagnaklasar:

- Gerðu klasa fyrir hverja gerð búnaðar og svo einn yfirklasi sem heldur utan um gögn sem eru sameiginleg í hinum klösunum.
- Gerðu getters og setters fyrir allar gagnabreytur klasanna. 
- Klasarnir þurfa að geta prentað sjálfa sig snyrtilega á skjáinn.

Listaklasinn:

- Útfærðu þinn eigin listaklasa sem heldur utan um búnað (velja eina útfærslu):
  - Kviklegt fylki (e. dynamic array), gefur engin aukastig ofan á grunnkröfur.
  - Keðjulisti (e. linked list), gefur 10 aukastig ofan á grunnkröfur.
  - Tætitafla (e. hash table, hash map, dictionary), gefur 20 aukastig ofan á grunnkröfur.
- Gerðu notendaviðmót þar sem hægt er að gera eftirfarandi:
  - Það þarf að vera hægt að skrá búnað í listann.
  - Það þarf að vera hægt að sækja búnað úr listanum (án þess að eyða búnaði).
  - Það þarf að vera hægt að eyða búnaði úr listanum.
  - Það þarf að vera hægt að uppfæra staðsetningu búnaðar.
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði.
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði í ákveðnu húsi.
  - Hafðu notendaviðmótið sem svipuðu sniði og [hér](https://gist.github.com/gestskoli/b407cf29d8d3852e0fc0146aead12e61).

### Dæmi um aukakröfur

- Skráavinnsla, hægt er að skrifa listann í skrár og lesa í listann úr skrá. (10 stig)
- Gögnin eru röðuð í listanum. Útheimtir að útfæra samanburðarvirkjana. (5 stig)
- Litir í viðmóti, hér má nota tilbúna lausn t.d. [rlutil](https://github.com/tapio/rlutil). (5 stig)
- Prenta á skjá búnað í ákveðinni stofu og ákveðinni hæð í ákveðnu húsi. (5 stig)
- Prenta á skjá búnað af ákveðinni gerð, t.d. alla stóla. (5 stig)
- Útfæra afritunarsmið (e. copy constructor) og gildisveitingavirkjann (e. assignment operator) fyrir listaklasann. (5 stig)
- Annað sem ykkur dettur í hug í samráði við kennara.

## Prófunargögn

Hafið þessi gögn harðkóðuð í forritinu sem þið skilið.

Ferð | Nr. | Staðsetnign | Verðmæti | Pláss/Snúningur/Lumens/Kaupár
--- | --- | :-: | :-: | ---
Borð | 501 | 21209 | 1000 | 4
Borð | 502 | 10410 | 2000 | 2
Stóll | 503 | 21209 | 4000 | Nei
Stóll | 504 | 21209 | 4000 | Nei
Skjávarpi | 505 | 10410 | 100000 | 4000
Skjávarpi | 506 | 21209 | 100000 | 4000
Tölva | 507 | 21209 | 50000 | 2019
Tölva | 508 | 21209 | 50000 | 2019
Tölva | 509 | 21209 | 50000 | 2019
Tölva | 510 | 21209 | 50000 | 2019

### Prófunargögn í svigum

```c++
Bord(501, 21209, 1000, 4)
Bord(502, 10410, 2000, 2)
Stoll(503, 21209, 4000, 0)
Stoll(504, 21209, 4000, 0)
Skjavarpi(505, 10410, 100000, 4000)
Skjavarpi(506, 21209, 100000, 4000)
Tolva(507, 21209, 50000, 2019)
Tolva(508, 21209, 50000, 2019)
Tolva(509, 21209, 50000, 2019)
Tolva(510, 21209, 50000, 2019)
```