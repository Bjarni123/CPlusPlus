#pragma once

#include <iostream>
#include <string>

class Bunadur {
    protected:
        int nr;
        char stadsetning[3];
        int verd;
    public:
        Bunadur();
        Bunadur(int nr, int stadsetning, int verd);
        int getNR();
        void setNR(int nr);
        int getStadsetning();
        void setStadsetning(int stadsetning);
        int getVerd();
        void setVerd(int verd);
        virtual void prenta();
        virtual std::string getType();
        virtual ~Bunadur();


        bool operator==(Bunadur& hitt);
        bool operator!=(Bunadur& hitt);
        bool operator<(Bunadur& hitt);
        bool operator>(Bunadur& hitt);
        bool operator<=(Bunadur& hitt);
        bool operator>=(Bunadur& hitt);
};