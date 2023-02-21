#include "bord.h"

Bord::Bord() {
    this->plass = -1;
}

Bord::Bord(int nr, int stadsetning, int verd, int plass) : Bunadur(nr, stadsetning, verd) {
    this->plass = plass;
}

int Bord::getPlass() {
    return this->plass;
}

void Bord::setPlass(int plass) {
    this->plass = plass;
}

void Bord::prenta() {
    std::cout << this->getType() << "\t" << std::to_string(this->nr)
    << "\t" << std::to_string(this->getStadsetning())
    << "\t" << std::to_string(this->getVerd())
    << "\t" << std::to_string(this->getPlass()) << "\n";
}

std::string Bord::getType() {
    return "Bord";
}
