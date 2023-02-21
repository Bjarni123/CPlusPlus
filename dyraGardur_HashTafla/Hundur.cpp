#include "Hundur.h"

Hundur::Hundur() {
    this->einkunn = -1;
}

Hundur::Hundur(int einkunn, int aldur, std::string nafn) : Dyr(aldur, nafn) {
    this->einkunn = einkunn;
}

int Hundur::getEinkunn() { 
    return this->einkunn; 
}

void Hundur::setEinkunn(int einkunn) { 
    this->einkunn = einkunn; 
}

void Hundur::prenta() {
    std::cout << "Hundur, nafn: " << this->nafn << ", aldur: " << this->aldur
            << ", einkunn: " << this->einkunn << std::endl;
}
std::string Hundur::getType() {
    // TODO:
    return "hundur";
}