#include "bunadur.h"

Bunadur::Bunadur() {
    this->nr = -1;
    this->stadsetning[0] = -1;
    this->verd = -1;
}

Bunadur::Bunadur(int nr, int stadsetning, int verd) {
    // 21209
    this->stadsetning[0] = stadsetning / 1000;
    this->stadsetning[1] = (stadsetning - this->stadsetning[0] * 1000) / 100;
    this->stadsetning[2] = stadsetning % 100;
    this->nr = nr;
    this->verd = verd;
}

int Bunadur::getNR() {
    return this->nr;
}

void Bunadur::setNR(int nr) {
    this->nr = nr;
}

int Bunadur::getStadsetning() {
    return int(std::to_string(this->stadsetning[0]) + 
    std::to_string(this->stadsetning[1]) + 
    std::to_string(this->stadsetning[2]));
}

void Bunadur::setStadsetning(int stadsetning) {

}

int Bunadur::getVerd() {

}

void Bunadur::setVerd(int verd) {

}

void Bunadur::prenta() {

}

Bunadur::~Bunadur() {

}

bool Bunadur::operator==(Bunadur& hitt) {

}

bool Bunadur::operator!=(Bunadur& hitt) {

}

bool Bunadur::operator<(Bunadur& hitt) {

}

bool Bunadur::operator>(Bunadur& hitt) {

}

bool Bunadur::operator<=(Bunadur& hitt) {

}

bool Bunadur::operator>=(Bunadur& hitt) {

}
