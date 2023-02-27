## Verkefnið

### Búnaðarlisti Tækniskólans

Húsumsjón Tækniskólans hefur beðið þig um skrifa hugbúnað til að halda utan um ýmsan búnað sem skólinn á og hvar sá búnaður er staðsettur. 

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
  - Kviklegt fylki (e. dynamic array), gefur engin aukastig ofan á grunnkröfur.
  - Keðjulisti (e. linked list), gefur 10 aukastig ofan á grunnkröfur. :heavy_check_mark:
  - Tætitafla (e. hash table, hash map, dictionary), gefur 20 aukastig ofan á grunnkröfur. :heavy_check_mark:
- Gerðu notendaviðmót þar sem hægt er að gera eftirfarandi:
  - Það þarf að vera hægt að skrá búnað í listann. :heavy_check_mark:
  - Það þarf að vera hægt að eyða búnaði úr listanum. :heavy_check_mark:
  - Það þarf að vera hægt að uppfæra staðsetningu búnaðar. :heavy_check_mark:
  - Það þarf að vera hægt að prenta út ákveðinn búnað útfrá id. :heavy_check_mark:
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði. :heavy_check_mark:
  - það þarf að vera hægt að prenta á skjá lista með öllum búnaði í ákveðnu húsi. :heavy_check_mark:
  - Hafðu notendaviðmótið sem svipuðu sniði og [hér](https://gist.github.com/gestskoli/b407cf29d8d3852e0fc0146aead12e61).

### Dæmi um aukakröfur

- Skráavinnsla, hægt er að skrifa listann í skrár og lesa í listann úr skrá. (10 stig) :heavy_check_mark:
- Gögnin eru röðuð í listanum. Útheimtir að útfæra samanburðarvirkjana. (5 stig) :heavy_check_mark:
- Litir í viðmóti, hér má nota tilbúna lausn t.d. [rlutil](https://github.com/tapio/rlutil). (5 stig) :heavy_check_mark:
- Prenta á skjá búnað í ákveðinni stofu og ákveðinni hæð í ákveðnu húsi. (5 stig) :heavy_check_mark:
- Prenta á skjá búnað af ákveðinni gerð, t.d. alla stóla. (5 stig) :heavy_check_mark:
- Útfæra afritunarsmið (e. copy constructor) og gildisveitingavirkjann (e. assignment operator) fyrir listaklasann. (5 stig) :heavy_check_mark:
- Annað sem ykkur dettur í hug í samráði við kennara. :heavy_check_mark:
