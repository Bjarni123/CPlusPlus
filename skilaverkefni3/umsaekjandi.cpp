#include "umsaekjandi.h"

Umsaekjandi::Umsaekjandi() {
    this->nafn = "";
    this->aldur = 0;
    this->medaleinkun = 0.f;
}

Umsaekjandi::Umsaekjandi(std::string nafn, int aldur, float medaleinkun) {
    this->nafn = nafn;
    this->aldur = aldur;
    this->medaleinkun = medaleinkun;
}

std::string Umsaekjandi::getNafn() {
    return this->nafn;
}

void Umsaekjandi::setNafn(std::string nafn) {
    this->nafn = nafn;
}

int Umsaekjandi::getAldur() {
    return this->aldur;
}

void Umsaekjandi::setAldur(int aldur) {
    this->aldur = aldur;
}

float Umsaekjandi::getMedaleinkun() {
    return this->medaleinkun;
}

void Umsaekjandi::setMedaleinkun(float medaleinkun) {
    this->medaleinkun = medaleinkun;
}


void Umsaekjandi::prenta() {
    std::cout << this->toString() << std::endl;

}

std::string Umsaekjandi::toString() {
    return "Nafn: " + this->nafn + ", aldur: " 
           + std::to_string(this->aldur) + ", meðaleinkun: "
           + std::to_string(this->medaleinkun);
}


bool Umsaekjandi::operator==(Umsaekjandi& hinn) {
    return this->aldur == hinn.getAldur() &&
           this->medaleinkun == hinn.getMedaleinkun();
}

bool Umsaekjandi::operator!=(Umsaekjandi& hinn) {
    return !(*this == hinn);
}

bool Umsaekjandi::operator<(Umsaekjandi& hinn) {
    if (this->aldur < 18 || hinn.getAldur() < 18) {
        if (this->aldur == hinn.getAldur()) {
            return this->medaleinkun > hinn.getMedaleinkun();
        }
        return this->aldur < hinn.getAldur();
    }
    if (this->medaleinkun == hinn.getMedaleinkun()) {
        return this->aldur < hinn.getAldur();
    }
    return this->medaleinkun > hinn.getMedaleinkun();
}

bool Umsaekjandi::operator>(Umsaekjandi& hinn) {
    return hinn < *this;
}

bool Umsaekjandi::operator<=(Umsaekjandi& hinn) {
    return !(*this > hinn);
}

bool Umsaekjandi::operator>=(Umsaekjandi& hinn) {
    return !(*this < hinn);
}

std::ostream& operator<<(std::ostream& ostr, Umsaekjandi& hinn) {
    return ostr << hinn.toString();
}
