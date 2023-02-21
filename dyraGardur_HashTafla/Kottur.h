#pragma once

#include <iostream>
#include <string>

#include "Dyr.h"

class Kottur : public Dyr {
    private:
        std::string eigandi;
    public:
        Kottur();
        Kottur(std::string eigandi, int aldur, std::string nafn);
        std::string getEigandi();
        void setEigandi(std::string eigandi);
        void prenta();
        std::string getType();
};