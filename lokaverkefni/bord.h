#pragma once

#include <iostream>
#include <string>

#include "bunadur.h"

class Bord : public Bunadur {
    private:
        int plass;
    public:
        Bord();
        Bord(int nr, int stadsetning, int verd, int plass);
        int getPlass();
        void setPlass(int plass);
        void prenta();
        std::string getType();
};