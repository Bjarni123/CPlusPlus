#pragma once

#include <iostream>
#include <string>

#include "bunadur.h"
#include "stoll.h"
#include "skjavarpi.h"
#include "bord.h"
#include "tolva.h"
#include "bunadurNode.h"

class Husgogn {
    private:
        BunadurNode** heads;
        int staerd;
        int hash(int nr);
        void prentaAkvednaTegund(std::string tegund);
    public:
        Husgogn();  
        Husgogn(int staerd);  
        Husgogn(Husgogn& hinn);
        Husgogn& operator=(Husgogn& hinn);

        void skraBunad(Bunadur* nyiBunadur);
        void skraBord(int nr, int stadsetning, int verd, int plass);
        void skraSkjavarpa(int nr, int stadsetning, int verd, int lumens);
        void skraStol(int nr, int stadsetning, int verd, bool snuningur);
        void skraTolvu(int nr, int stadsetning, int verd, int kaupar);

        bool uppfaeraStadsetningu(int nr, int stadsetning);
        bool uppfaeraIndex(int nr, int nyttNr);
        bool uppfaeraVerd(int nr, int verd);

        bool eydaBunadi(int nr);
        bool skodaBunad(int nr);

        void prentaBunadIHusiHaedStofu(int stadsetning);
        void prentaBunadIHusi(int hus);
        void prentaAllt();
        void prentaBord();
        void prentaSkjavarpa();
        void prentaStol();
        void prentaTolvu();

        std::string ollGognIStreng();

        ~Husgogn();
        
};