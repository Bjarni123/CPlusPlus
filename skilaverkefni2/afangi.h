#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <iostream>

class Afangi {
    private:
        int id;
        std::string nafn;
        float einkun;

    public:
        Afangi();
        Afangi(int id);
        Afangi(int id, std::string nafn, float einkun);
        int getID();
        void setID(int id);
        std::string getNafn();
        void setNafn(std::string nafn);
        float getEinkun();
        void setEinkun(float einkun);
        void prenta();
        std::string toString();
        // ~Afangi();
};