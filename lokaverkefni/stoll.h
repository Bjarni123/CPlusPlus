#pragma once

#include <iostream>
#include <string>

#include "bunadur.h"

class Stoll : public Bunadur {
    private:
        bool snuningur;
    public:
        Stoll();
        Stoll(int nr, int stadsetning, int verd, bool snuningur);
        bool getSnuningur();
        void setSnuningur(bool snuningur);
        void prenta();
        std::string getType();
};