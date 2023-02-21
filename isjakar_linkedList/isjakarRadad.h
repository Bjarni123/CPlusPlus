#pragma once

#include "isjaki.h"
#include "isjakaNode.h"

class IsjakarRadad {
    private:
        IsjakaNode* head;
    public:
        IsjakarRadad();
        void skraIsjaka(Isjaki k);
        void skraIsjaka(int id, int staerd, float fjarlaegd);
        bool eydaIsjaka(int id);
        void breytaFjarlaegd(int id, int fjarlaegd);
        void prentaEinnIsjaka(int id);
        void prentaAllt();
        ~IsjakarRadad();
};