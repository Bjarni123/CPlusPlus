#include "skjavarpi.h"

Skjavarpi::Skjavarpi() {
    this->lumens = -1;
}

Skjavarpi::Skjavarpi(int nr, int stadsetning, int verd, int lumens) : Bunadur(nr, stadsetning, verd) {
    this->lumens = lumens;
}

int Skjavarpi::getLumens() {
    return this->lumens;
}

void Skjavarpi::setLumens(int lumens) {
    this->lumens = lumens;
}

void Skjavarpi::prenta() {
    std::cout << this->getType() << "\t" << std::to_string(this->nr)
    << "\t" << std::to_string(this->getStadsetning())
    << "\t" << std::to_string(this->getVerd())
    << "\t" << std::to_string(this->getLumens()) << "\n";
}

std::string Skjavarpi::getType() {
    return "Skjavarpi";
}
