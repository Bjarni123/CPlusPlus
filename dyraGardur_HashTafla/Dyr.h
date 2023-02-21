#pragma once

#include <iostream>
#include <string>

class Dyr {
    protected:
        int aldur;
        std::string nafn;
    public:
        Dyr();
        Dyr(int aldur, std::string nafn);
        int getAldur();
        void setAldur(int aldur); 
        std::string getNafn();
        void setNafn(std::string nafn);
        virtual void prenta();
        virtual std::string getType();
        virtual ~Dyr() {}

        bool operator<(Dyr& hitt);
        bool operator>(Dyr& hitt);
        bool operator<=(Dyr& hitt);
        bool operator>=(Dyr& hitt);
};