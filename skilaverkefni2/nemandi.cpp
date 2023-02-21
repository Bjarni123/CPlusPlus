#include "nemandi.h"
#include <iomanip>
#include <string>


Nemandi::Nemandi() {
    this->nafn = "";
    this->staerd = 2;
    this->taflan = new Afangi[this->staerd];
    // std::cout << "Nemandi klasi gerður";
}

Nemandi::Nemandi(std::string nafn) {
    this->nafn = nafn;
    this->staerd = 2;
    this->taflan = new Afangi[this->staerd];
    // std::cout << "Nemandi klasi gerður";
}

std::string Nemandi::getNafn() {
    return this->nafn;
}

void Nemandi::setNafn(std::string nafn) {
    this->nafn = nafn;
}

void Nemandi::skraIAfanga(Afangi b) {
    int idx = this->finnaLausanIndex();
    if (idx != -1) {
        this->taflan[idx] = b;
        // std::cout << "Bætt við!\n";
    } else { // idx == -1 -> fullt array
        Afangi *temp = new Afangi[this->staerd + 2];
        for (int i = 0; i < this->staerd; i++) {
            temp[i] = this->taflan[i];
        }
        // std::cout << "Stækkað!\n";
        delete [] this->taflan;
        this->taflan = temp;
        this->taflan[this->staerd] = b;
        this->staerd += 2;
    }
}

void Nemandi::skraIAfanga(int id, std::string nafn, float einkun) {
    this->skraIAfanga(Afangi(id, nafn, einkun));

}

void Nemandi::eydaAfanga(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i] = Afangi();
        }
    }
}

void Nemandi::prentaAfanga(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i].prenta();
        }
    }
}

void Nemandi::uppfaeraEinkunn(int id, float einkun) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i].setEinkun(einkun);
        }
    }
}


void Nemandi::prentaAllaAfanga() {
    std::cout << "Nemandi: " + this->nafn + ", áfangar:\n";
    int count = 0;
    float SamtalsEinkunir = 0;
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() != -1) {
            count++;
            SamtalsEinkunir += this->taflan[i].getEinkun();
            this->taflan[i].prenta();
        }
    }
    std::cout << "Meðaleinkunnin er: " << std::fixed << std::setprecision(2) << SamtalsEinkunir / float(count) << "\n";
}

int Nemandi::finnaLausanIndex() {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == -1) {
            return i;
        }
    }
    return -1;
}

Nemandi::~Nemandi() {
    delete [] this->taflan;
}
