#include "Dyr.h"

Dyr::Dyr() {
    this->aldur = -1;
    this->nafn = "";
}
Dyr::Dyr(int aldur, std::string nafn) {
    this->aldur = aldur;
    this->nafn = nafn;
}
int Dyr::getAldur() { 
    return this->aldur; 
}

void Dyr::setAldur(int aldur) { 
    this->aldur = aldur;
}

std::string Dyr::getNafn() { 
    return this->nafn; 
}

void Dyr::setNafn(std::string nafn) { 
    this->nafn = nafn; 
}

void Dyr::prenta() { // athuga ekkert virtual hér, bara í .h skránni
    std::cout << "Dýr, nafn: " << this->nafn << ", aldur: " 
            << this->aldur << std::endl;
}

std::string Dyr::getType() { 
    // TODO, fallið skilar af hvaða tagi dýrið er
    return "dýr";
}

bool Dyr::operator<(Dyr& hitt) {
    return this->nafn < hitt.getNafn();
}

bool Dyr::operator>(Dyr& hitt) {
    return hitt < *this;
}

bool Dyr::operator<=(Dyr& hitt) {
    return !(*this > hitt);
}

bool Dyr::operator>=(Dyr& hitt) {
    return !(*this < hitt);
}
