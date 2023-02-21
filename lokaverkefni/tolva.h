#pragma once

#include <iostream>
#include <string>

#include "bunadur.h"

class Tolva : public Bunadur {
    private:
        int kaupar;
    public:
        Tolva();
        Tolva(int nr, int stadsetning, int verd, int kaupar);
        int getKaupar();
        void setKaupar(int kaupar);
        void prenta();
        std::string getType();
};