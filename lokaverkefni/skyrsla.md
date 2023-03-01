## Verkefnið 

Allur búnaður hefur auðkenni, verðmæti og staðsetningu:
- Auðkennið er einkvæm heiltala (ekki sjálfhækkandi (e. auto increment)). :heavy_check_mark:
- Verðmætið er í krónum. :heavy_check_mark:
- Staðsetningin fimm stafa samsett heiltala sem samanstendur af húsi, hæð og svo herbergi. Dæmi um staðsetningu er 21206 þar sem fyrstu tveir stafirnir (21) merkir Háteigsvegur aðalhús, þriðja talan (2) merkir önnur hæð og svo síðustu tveir stafirnir (06) merkja stofa nr. 6. Staðsetninguna á að geyma í þriggja staka `char` fylki til að spara pláss en það þarf að vera hægt að vinna með staðsetninguna sem eina tölu.
  - Klasinn þarf að geta tekið inn heiltölu og dreift henni svo í þrjú stök fylkisins. :heavy_check_mark:
  - Klasinn þarf að geta skilað heiltölu með tölunum úr fylkinu. :heavy_check_mark:
  - Klasinn þarf að eiga föll eins og getHus(), getHaed() og getHerbergi() og samsvarandi set föll. :heavy_check_mark:

Sá búnaður sem Húsumsjónin vill geta skráð í þessum hugbúnaði eru:
  - Borð, aukalega þarf að skrá hversu margir geta setið við borðið. :heavy_check_mark:
  - Stóll, aukalega þarf að skrá hvort stóllinn er snúningsstóll eða ekki. :heavy_check_mark:
  - Skjávarpi, aukalega þarf að skrá hversu mörg lumens skjávarpinn er. :heavy_check_mark:
  - Tölva, aukalega þarf að skrá kaupár tölvunnar. :heavy_check_mark:

### Grunnkröfur

Gagnaklasar:

- Gerðu klasa fyrir hverja gerð búnaðar og svo einn yfirklasi sem heldur utan um gögn sem eru sameiginleg í hinum klösunum. :heavy_check_mark:
- Gerðu getters og setters fyrir allar gagnabreytur klasanna. :heavy_check_mark:
- Klasarnir þurfa að geta prentað sjálfa sig snyrtilega á skjáinn. :heavy_check_mark:
- Útfærðu þinn eigin listaklasa sem heldur utan um búnað (velja eina útfærslu): 
  - Kviklegt fylki (e. dynamic array), gefur engin aukastig ofan á grunnkröfur. :x:
  - Keðjulisti (e. linked list), gefur 10 aukastig ofan á grunnkröfur. :heavy_check_mark:
  - Tætitafla (e. hash table, hash map, dictionary), gefur 20 aukastig ofan á grunnkröfur. :heavy_check_mark:
- Gerðu notendaviðmót þar sem hægt er að gera eftirfarandi:
  - Það þarf að vera hægt að skrá búnað í listann. :heavy_check_mark:
  - Það þarf að vera hægt að eyða búnaði úr listanum. :heavy_check_mark:
  - Það þarf að vera hægt að uppfæra staðsetningu búnaðar. :heavy_check_mark:
  - Það þarf að vera hægt að prenta út ákveðinn búnað útfrá id. :heavy_check_mark:
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði. :heavy_check_mark:
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði í ákveðnu húsi. :heavy_check_mark:

### Dæmi um aukakröfur

- Skráavinnsla, hægt er að skrifa listann í skrár og lesa í listann úr skrá. (10 stig) :heavy_check_mark:
- Gögnin eru röðuð í listanum. Útheimtir að útfæra samanburðarvirkjana. (5 stig) :heavy_check_mark:
- Litir í viðmóti, hér má nota tilbúna lausn t.d. [rlutil](https://github.com/tapio/rlutil). (5 stig) :heavy_check_mark:
- Prenta á skjá búnað í ákveðinni stofu og ákveðinni hæð í ákveðnu húsi. (5 stig) :heavy_check_mark:
- Prenta á skjá búnað af ákveðinni gerð, t.d. alla stóla. (5 stig) :heavy_check_mark:
- Útfæra afritunarsmið (e. copy constructor) og gildisveitingavirkjann (e. assignment operator) fyrir listaklasann. (5 stig) :heavy_check_mark:
- Annað sem ykkur dettur í hug í samráði við kennara. :heavy_check_mark:

### Fleirri Aukakröfur
- Hægt að uppfæra allar upplýsingar nema aukaupplýsingarnar. (snúningur, lumens, pláss og kaupár) :heavy_check_mark:
- help fall sem gefur lýsingar fyrir allar skipanir. :heavy_check_mark:
- Þegar er byrjað forrit þá er prent út öll skjöl sem eru til 
  - Valið er skjal til þess að vinna með þegar er byrjað forritið. :heavy_check_mark:
  - Þegar forritinu er lokað er saveað skjalið fyrir framtíðar notkun. :heavy_check_mark:
- Ég ætlaði að checkea þegar var bætt inn í listann hvort id-ið væri þegar í listanum :x:
- Gerða fallegra hash fall. Náði því ekki því það var viljað að væri hægt að finna eitthvern búnað út frá ID og fann bara fallegri hash föll þegar var notað fleirri en eina breytu. :x: 

### Notkun forrits
- Skráarvinnsla
  - Upphafi forrits er spurt hvaða skjal notandi vill vinna við.
  - Hlaðað er upp skjalinu og í endann er save-að skjalið fyrir framtíðar notkun.
- Skiparnir:
  - save
  - continue
  - Skrá
    - skra bunad nr stadsetning verd auka 
    - skra profunargogn (Skráir inn prófunargognin í 
  - help
  - Uppfæra:
    - uppfaera stadsetningu nr stadsetning
    - uppfaera numer nr nyttNr
    - uppfaera verd nr nyttVerd
  - eyda nr
  - Prenta:
    - prenta nr
    - prenta herbergi stadsetning
    - prenta hus hus
    - prenta allt
    - prenta bord
    - prenta skjavarpa
    - prenta tolvur
    - prenta stola
- Ef maður þarf eitthvern tímann hjálp þá er hægt að skrifa inn "help" og það mun sýna þér allar skiparnir, segja þér hvað þær gera og dæmi um hvernig á að nota þær.
