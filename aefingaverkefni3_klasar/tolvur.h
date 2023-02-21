#pragma once

#include <iostream>
#include <string>
#include "talva.h"

class Tolvur {
    private:
        Talva *taflan;
        int staerd;

    public:
        Tolvur();
        Tolvur(Tolvur &hinn); // copy constructor
        Tolvur& operator=(Tolvur &hinn); // assignment operator
        void skraTolvu(Talva b);
        void skraTolvu(int id, std::string orgjorvi, int staerd_vinnsluminni, int staerd_disks);
        void eydaTolvu(int id);
        void prentaTolvu(int id);
        void prentaAllarTolvur();
        int finnaLausanIndex();
        ~Tolvur();
};