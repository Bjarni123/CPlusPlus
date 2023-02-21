#pragma once

#include <iostream>
#include <string>

#include "Dyr.h"

class Hundur : public Dyr { 
    private: 
        int einkunn;
    public:
        Hundur();
        Hundur(int einkunn, int aldur, std::string nafn);
        int getEinkunn();
        void setEinkunn(int einkunn);
        void prenta();
        std::string getType();
};