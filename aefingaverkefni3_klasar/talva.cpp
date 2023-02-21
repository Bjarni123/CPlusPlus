#include "talva.h"

Talva::Talva() {
    this->id = -1;
    this->orgjorvi = ""; 
    this->staerd_vinnsluminni = -1;
    this->staerd_disks = -1;
    // std::cout << "Talva gerð!\n";
}

Talva::Talva(int id) {
    this->id = id;
    this->orgjorvi = ""; 
    this->staerd_vinnsluminni = -1;
    this->staerd_disks = -1;
}

Talva::Talva(int id, std::string orgjorvi, int staerd_vinnsluminni, int staerd_disks) {
    this->id = id;
    this->orgjorvi = orgjorvi; 
    this->staerd_vinnsluminni = staerd_vinnsluminni;
    this->staerd_disks = staerd_disks;
}

int Talva::getID() {
    return this->id;
}

void Talva::setID(int id) {
    this->id = id;
}

std::string Talva::get_orgjorvi() {
    return this->orgjorvi;
}

void Talva::set_orgjorvi(std::string orgjorvi) {
    this->orgjorvi = orgjorvi;
}

int Talva::get_staerd_vinnsluminni() {
    return this->staerd_vinnsluminni;
}

void Talva::set_staerd_vinnsluminni(int staerd_vinnsluminni) {
    this->staerd_vinnsluminni = staerd_vinnsluminni;
}

int Talva::get_staerd_disks() {
    return this->staerd_disks;
}

void Talva::set_staerd_disks(int staerd_disks) {
    this->staerd_disks = staerd_disks;
}

void Talva::prenta() {
    std::cout << this->toString();
}

std::string Talva::toString() {
    return "ID: " + std::to_string(this->id) +
        ", orgjorvi: " + this->orgjorvi +
        ", Stærð Vinnsluminnis: " + std::to_string(this->staerd_vinnsluminni) +
        ", Stærð disks: " + std::to_string(this->staerd_disks) + "\n";
}
/* 
Talva::~Talva() {
    std::cout << "Destroctor!!\n";
}
 */