// bilar.cpp
#include "bilar.h"

Bilar::Bilar() {
    this->staerd = 5;
    this->taflan = new Bill[this->staerd];
}

void Bilar::skraBil(Bill b) {
    int idx = this->finnaLausanIndex();
    if (idx != -1) {
        this->taflan[idx] = b;
    } else { // idx == -1 -> fullt array
        Bill *temp = new Bill[this->staerd + 1];
        for (int i = 0; i < this->staerd; i++) {
            temp[i] = this->taflan[i];
        }
        delete [] this->taflan;
        this->taflan = temp;
        this->taflan[this->staerd] = b; // this->taflan[this->staerd++] = b; og sleppa línunni fyrir neðan
        this->staerd++;
    }

}

void Bilar::skraBil(int id, std::string tegund, std::string litur) {
    // Bill b = Bill(id, tegund, litur);
    // this->skraBil(b); 
    this->skraBil(Bill(id, tegund, litur));
}

void Bilar::eydaBil(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i] = Bill();
        }
    }
}

void Bilar::prentaBil(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i].prenta();
        }
    }
}

void Bilar::prentaAllaBila() {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() != -1) {
            this->taflan[i].prenta();
        }
    }
}

int Bilar::finnaLausanIndex() {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == -1) {
            return i;
        }
    }
    return -1;
}

Bilar::~Bilar() {
    delete [] this->taflan;
}
