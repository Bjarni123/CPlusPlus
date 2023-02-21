#include "tolvur.h"

Tolvur::Tolvur() {
    this->staerd = 5;
    this->taflan = new Talva[this->staerd];
    std::cout << "Tolvur Klasi gerður!\n";
}

Tolvur::Tolvur(Tolvur &hinn) {
    this->staerd = hinn.staerd;
    this->taflan = new Talva[this->staerd];
    for (int i = 0; i < this->staerd; i++) {
        this->taflan[i] = hinn.taflan[i];
    }
}

Tolvur& Tolvur::operator=(Tolvur &hinn) {
    this->staerd = hinn.staerd;
    this->taflan = new Talva[this->staerd];
    for (int i = 0; i < this->staerd; i++) {
        this->taflan[i] = hinn.taflan[i];
    }
    return *this;
}

void Tolvur::skraTolvu(Talva b) {
    int idx = this->finnaLausanIndex();
    if (idx != -1) {
        this->taflan[idx] = b;
        // std::cout << "Bætt við!\n";
    } else { // idx == -1 -> fullt array
        Talva *temp = new Talva[this->staerd + 5];
        for (int i = 0; i < this->staerd; i++) {
            temp[i] = this->taflan[i];
        }
        // std::cout << "Stækkað!\n";
        delete [] this->taflan;
        this->taflan = temp;
        this->taflan[this->staerd] = b;
        this->staerd += 5;
    }
}

void Tolvur::skraTolvu(int id, std::string orgjorvi, int staerd_vinnsluminni, int staerd_disks) {
    this->skraTolvu(Talva(id, orgjorvi, staerd_vinnsluminni, staerd_disks));
}

void Tolvur::eydaTolvu(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i] = Talva();
        }
    }
}

void Tolvur::prentaTolvu(int id) {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == id) {
            this->taflan[i].prenta();
        }
    }
}

void Tolvur::prentaAllarTolvur() {
    for (int i = 0; i < this->staerd; i++) {
            if (this->taflan[i].getID() != -1) {
                this->taflan[i].prenta();
            }
        }
}

int Tolvur::finnaLausanIndex() {
    for (int i = 0; i < this->staerd; i++) {
        if (this->taflan[i].getID() == -1) {
            return i;
        }
    }
    return -1;
}

Tolvur::~Tolvur() {
    delete [] this->taflan;
    std::cout << "Eytt Tolvur klasa!\n";
}
