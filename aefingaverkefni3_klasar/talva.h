// bill.h
#pragma once

#include <iostream>
#include <string>

class Talva {
    private:
        int id;
        std::string orgjorvi;
        int staerd_vinnsluminni;
        int staerd_disks;

    public:
        Talva();
        Talva(int id);
        Talva(int id, std::string orgjorvi, int staerd_vinnsluminni, int staerd_disks);
        int getID();
        void setID(int id);
        std::string get_orgjorvi();
        void set_orgjorvi(std::string orgjorvi);
        int get_staerd_vinnsluminni();
        void set_staerd_vinnsluminni(int staerd_vinnsluminni);
        int get_staerd_disks();
        void set_staerd_disks(int staerd_disks);
        void prenta();
        std::string toString();
        // ~Talva();
};