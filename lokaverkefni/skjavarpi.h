#pragma once

#include <iostream>
#include <string>

#include "bunadur.h"

class Skjavarpi : public Bunadur {
    private:
        int lumens;
    public:
        Skjavarpi();
        Skjavarpi(int nr, int stadsetning, int verd, int lumens);
        int getLumens();
        void setLumens(int lumens);
        void prenta();
        std::string getType();
};