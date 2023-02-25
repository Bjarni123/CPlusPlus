#include "stoll.h"

Stoll::Stoll() {
    this->snuningur = false;
}

Stoll::Stoll(int nr, int stadsetning, int verd, bool snuningur) : Bunadur(nr, stadsetning, verd) {
    this->snuningur = snuningur;
}

bool Stoll::getSnuningur() {
    return this->snuningur;
}

void Stoll::setSnuningur(bool snuningur) {
    this->snuningur = snuningur;
}

void Stoll::prenta() {
    std::string jaEdaNei;
    if (this->getSnuningur()) {
        jaEdaNei = "Já";
    } else {
        jaEdaNei = "Nei";
    }
    std::cout << this->getType() << "\t\t" << std::to_string(this->nr)
    << "\t" << std::to_string(this->getStadsetning())
    << "\t" << std::to_string(this->getVerd())
    << "\t" << jaEdaNei << "\n";
}

std::string Stoll::getType() {
    return "Stoll";
}
