#include "Isjaki.h"

Isjaki::Isjaki() {
    this->id = -1;
    this->staerd = 0;
    this->fjarlaegd = 0.f;
}

Isjaki::Isjaki(int id, int staerd, float fjarlaegd) {
    this->id = id;
    this->staerd = staerd;
    this->fjarlaegd = fjarlaegd;
}

int Isjaki::getId() {
    return this->id;
}

void Isjaki::setId(int id) {
    this->id = id;
}

int Isjaki::getStaerd() {
    return this->staerd;
}

void Isjaki::setStaerd(int staerd) {
    this->staerd = staerd;
}

float Isjaki::getFjarlaegd() {
    return this->fjarlaegd;
}

void Isjaki::setFjarlaegd(int fjarlaegd) {
    this->fjarlaegd = fjarlaegd;
}

void Isjaki::prenta() {
    std::cout << this->toString() << std::endl;
}

std::string Isjaki::toString() {
    return "Id: " + std::to_string(this->id) + ", stærð: " 
           + std::to_string(this->staerd) + " fm., fjarlægð: "
           + std::to_string(this->fjarlaegd) + " km.";

}

bool Isjaki::operator==(Isjaki& hinn) {
    return this->staerd == hinn.getStaerd() &&
           this->fjarlaegd == hinn.getFjarlaegd();
}

bool Isjaki::operator!=(Isjaki& hinn) {
    return !(*this == hinn);
}

bool Isjaki::operator<(Isjaki& hinn) {
    if(this->staerd == hinn.getStaerd()) {
        return this->fjarlaegd < hinn.getFjarlaegd();
    }
    return this->staerd < hinn.getStaerd();
}

bool Isjaki::operator>(Isjaki& hinn) {
    return hinn < *this;
}

bool Isjaki::operator<=(Isjaki& hinn) {
    return !(*this > hinn);
}

bool Isjaki::operator>=(Isjaki& hinn) {
    return !(*this < hinn);
}

std::ostream& operator<<(std::ostream& ostr, Isjaki& hinn) {
    return ostr << hinn.toString();
}