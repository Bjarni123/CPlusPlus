#pragma once

#include <iostream>
#include <string>

class Isjaki {
    private:
        int id;
        int staerd;
        float fjarlaegd;
    public:
        Isjaki();
        Isjaki(int id, int staerd, float fjarlaegd);
        int getId();
        void setId(int id);
        int getStaerd();
        void setStaerd(int staerd);
        float getFjarlaegd();
        void setFjarlaegd(int fjarlaegd);

        void prenta();
        std::string toString();

        bool operator==(Isjaki& hinn);
        bool operator!=(Isjaki& hinn);
        bool operator<(Isjaki& hinn);
        bool operator>(Isjaki& hinn);
        bool operator<=(Isjaki& hinn);
        bool operator>=(Isjaki& hinn);
};

std::ostream& operator<<(std::ostream& ostr, Isjaki& hinn);