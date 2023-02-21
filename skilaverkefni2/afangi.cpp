#include "afangi.h"
#include <iomanip>
#include <iostream>
#include <string>


Afangi::Afangi() {
    this->id = -1;
    this->nafn = "";
    this->einkun = 0;
}

Afangi::Afangi(int id) {
    this->id = id;
    this->nafn = "";
    this->einkun = 0;
}

Afangi::Afangi(int id, std::string nafn, float einkun) {
    this->id = id;
    this->nafn = nafn;
    this->einkun = einkun;
}

int Afangi::getID() {
    return this->id;
}

void Afangi::setID(int id) {
    this->id = id;
}

std::string Afangi::getNafn() {
    return this->nafn;
}

void Afangi::setNafn(std::string nafn) {
    this->nafn = nafn;
}

float Afangi::getEinkun() {
    return this->einkun;
}

void Afangi::setEinkun(float einkun) {
    this->einkun = einkun;
}

void Afangi::prenta() {
    std::cout << "ID: " << std::to_string(this->id) <<
        ", Nafn Áfanga: " << this->nafn <<
        ", Einkun: " << std::fixed << std::setprecision(2) << this->einkun << "\n";
}

std::string Afangi::toString() {
    return "ID: " + std::to_string(this->id) +
        ", Nafn Áfanga: " + this->nafn +
        ", Einkun: " + std::to_string(this->einkun) + "\n";
}

// Afangi::~Afangi() {}
