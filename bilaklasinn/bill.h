// bill.h
#pragma once

#include <iostream>
#include <string>

class Bill {
    private:
        int id;
        std::string tegund;
        std::string litur;

    public:
        Bill();
        Bill(int id);
        Bill(int id, std::string tegund, std::string litur);
        int getID();
        void setID(int id);
        std::string getTegund();
        void setTegund(std::string tegund);
        std::string getLitur();
        void setLitur(std::string litur);
        void prenta();
        std::string toString();

        // bool erEins(Bill& hinn);
        bool operator==(Bill& hinn);
        bool operator!=(Bill& hinn);
        bool operator<(Bill& hinn);
        bool operator>(Bill& hinn);
        bool operator<=(Bill& hinn);
        bool operator>=(Bill& hinn);
};

std::ostream& operator<<(std::ostream& ostr, Bill& b);