#include "tolva.h"

Tolva::Tolva() {
    this->kaupar = -1;
}

Tolva::Tolva(int nr, int stadsetning, int verd, int kaupar) : Bunadur(nr, stadsetning, verd) {
    this->kaupar = kaupar;
}

int Tolva::getKaupar() {
    return this->kaupar;
}

void Tolva::setKaupar(int kaupar) {
    this->kaupar = kaupar;
}

void Tolva::prenta() {
    std::cout << this->getType() << "\t" << std::to_string(this->nr)
    << "\t" << std::to_string(this->getStadsetning())
    << "\t" << std::to_string(this->getVerd())
    << "\t" << std::to_string(this->getKaupar()) << "\n";
}

std::string Tolva::getType() {
    return "Tolva";
}
