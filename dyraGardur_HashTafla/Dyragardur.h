#pragma once

#include <iostream>
#include <string>

#include "Dyr.h"
#include "Hundur.h"
#include "Kottur.h"
#include "DyraNode.h"

class Dyragardur {
    private:
        DyraNode** heads;
        int staerd;
        int hash(std::string nafn);
        void prentaAkvednaTegund(std::string tegund);
    public:
        Dyragardur();
        Dyragardur(int staerd);
        Dyragardur(Dyragardur& hinn);
        Dyragardur& operator=(Dyragardur& hinn);
        void skraDyr(Dyr* dyrid);
        void skraHund(int aldur, std::string nafn, int einkunn);
        void skraKott(int aldur, std::string nafn, std::string eigandi);
        bool eydaDyri(std::string nafn);
        bool skodaDyr(std::string nafn);
        void prentaAllt();
        void prentaHunda();
        void prentaKetti();
        ~Dyragardur();
};