#include "Kottur.h"

Kottur::Kottur() { 
    this->eigandi = ""; 
}

Kottur::Kottur(std::string eigandi, int aldur, std::string nafn) : Dyr(aldur, nafn) {
    this->eigandi = eigandi;
}

std::string Kottur::getEigandi() { 
    return this->eigandi; 
}

void Kottur::setEigandi(std::string eigandi) { 
    this->eigandi = eigandi; 
}

void Kottur::prenta() {
    std::cout << "Köttur, nafn: " << this->nafn << ", aldur: " << this->aldur
            << ", eigandi: " << this->eigandi << std::endl;
}

std::string Kottur::getType() {
    // TODO
    return "köttur";
}