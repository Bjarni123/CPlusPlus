// bilar.h

#pragma once

#include <iostream>
#include <string>
#include "bill.h"

class Bilar {
    private:
        Bill *taflan;
        int staerd;

    public:
        Bilar();
        void skraBil(Bill b);
        void skraBil(int id, std::string tegund, std::string litur);
        void eydaBil(int id);
        void prentaBil(int id);
        void prentaAllaBila();
        int finnaLausanIndex();
        ~Bilar();
};