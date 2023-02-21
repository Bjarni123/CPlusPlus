#pragma once

#include <iostream>
#include <string>

class Umsaekjandi {
    private:
        std::string nafn;
        int aldur;
        float medaleinkun;
    public:
        Umsaekjandi();
        Umsaekjandi(std::string nafn, int aldur, float medaleinkun);
        std::string getNafn();
        void setNafn(std::string nafn);
        int getAldur();
        void setAldur(int aldur);
        float getMedaleinkun();
        void setMedaleinkun(float medaleinkun);

        void prenta();
        std::string toString();

        bool operator==(Umsaekjandi& hinn);
        bool operator!=(Umsaekjandi& hinn);
        bool operator<(Umsaekjandi& hinn);
        bool operator>(Umsaekjandi& hinn);
        bool operator<=(Umsaekjandi& hinn);
        bool operator>=(Umsaekjandi& hinn);
};

std::ostream& operator<<(std::ostream& ostr, Umsaekjandi& hinn);