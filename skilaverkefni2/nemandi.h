#pragma once

#include <iostream>
#include <string>
#include "afangi.h"

class Nemandi {
    private:
        std::string nafn;
        Afangi *taflan;
        int staerd;

    public:
        Nemandi();
        Nemandi(std::string nafn);
        std::string getNafn();
        void setNafn(std::string nafn);
        void skraIAfanga(Afangi b);
        void skraIAfanga(int id, std::string, float einkun);
        void eydaAfanga(int id);
        void prentaAfanga(int id);
        void uppfaeraEinkunn(int id, float Einkun);
        void prentaAllaAfanga();
        int finnaLausanIndex();
        ~Nemandi();
};