#include "husgogn.h"

int Husgogn::hash(int nr) {
    // int hash_gildi = 0;
    return nr % this->staerd;
}

void Husgogn::prentaAkvednaTegund(std::string tegund) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* current = this->heads[idx];
        while (current) {
            if (current->bunadurinn->getType() == tegund) {
                current->bunadurinn->prenta();
            }
            current = current->next;
        }
    }
}

Husgogn::Husgogn() {
    this->staerd = 10;
    this->heads = new BunadurNode*[this->staerd]();
}  

Husgogn::Husgogn(int staerd) {
    this->staerd = staerd;
    this->heads = new BunadurNode*[this->staerd]();
}  

Husgogn::Husgogn(Husgogn& hinn) {
    this->staerd = hinn.staerd;
    this->heads = new BunadurNode*[this->staerd]();
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* hinn_current = hinn.heads[idx];
        while (hinn_current) {
            if (hinn_current->bunadurinn->getType() == "Bord") {
                Bord* b = (Bord*)hinn_current->bunadurinn;
                this->skraBord(b->getNR(), b->getStadsetning(), b->getVerd(), b->getPlass());
            } else if (hinn_current->bunadurinn->getType() == "Stoll") {
                Stoll* st = (Stoll*)hinn_current->bunadurinn;
                this->skraStol(st->getNR(), st->getStadsetning(), st->getVerd(), st->getSnuningur());
            } else if (hinn_current->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* sk = (Skjavarpi*)hinn_current->bunadurinn;
                this->skraSkjavarpa(sk->getNR(), sk->getStadsetning(), sk->getVerd(), sk->getLumens());
            } else if (hinn_current->bunadurinn->getType() == "Tolva") {
                Tolva* t = (Tolva*)hinn_current->bunadurinn;
                this->skraBord(t->getNR(), t->getStadsetning(), t->getVerd(), t->getKaupar());
            }
            hinn_current = hinn_current->next;
        }
    }
}

Husgogn& Husgogn::operator=(Husgogn& hinn) {
    this->staerd = hinn.staerd;
    this->heads = new BunadurNode*[this->staerd]();
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* hinn_current = hinn.heads[idx];
        while (hinn_current) {
            if (hinn_current->bunadurinn->getType() == "Bord") {
                Bord* b = (Bord*)hinn_current->bunadurinn;
                this->skraBord(b->getNR(), b->getStadsetning(), b->getVerd(), b->getPlass());
            } else if (hinn_current->bunadurinn->getType() == "Stoll") {
                Stoll* st = (Stoll*)hinn_current->bunadurinn;
                this->skraStol(st->getNR(), st->getStadsetning(), st->getVerd(), st->getSnuningur());
            } else if (hinn_current->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* sk = (Skjavarpi*)hinn_current->bunadurinn;
                this->skraSkjavarpa(sk->getNR(), sk->getStadsetning(), sk->getVerd(), sk->getLumens());
            } else if (hinn_current->bunadurinn->getType() == "Tolva") {
                Tolva* t = (Tolva*)hinn_current->bunadurinn;
                this->skraBord(t->getNR(), t->getStadsetning(), t->getVerd(), t->getKaupar());
            }
            hinn_current = hinn_current->next;
        }
    }
    return *this;
}

void Husgogn::skraBunad(Bunadur* nyiBunadur) {
    int idx = this->hash(nyiBunadur->getNR());
    BunadurNode* new_bunadur = new BunadurNode(nyiBunadur);
    if(!this->heads[idx]) {
        this->heads[idx] = new_bunadur;
    } else {
        if (*this->heads[idx]->bunadurinn >= *nyiBunadur) {
            new_bunadur->next = this->heads[idx];
            this->heads[idx] = new_bunadur;
        } else {
            BunadurNode* current = this->heads[idx];
            BunadurNode* prev = this->heads[idx];
            while (current && *current->bunadurinn <= *nyiBunadur) {
                prev = current;
                current = current->next;
            }
            if (current) {
                new_bunadur->next = current;
                prev->next = new_bunadur;
            } else {
                prev->next = new_bunadur;
            }
        }
    }
}

void Husgogn::skraBord(int nr, int stadsetning, int verd, int plass) {
    this->skraBunad(new Bord(nr, stadsetning, verd, plass));
}

void Husgogn::skraSkjavarpa(int nr, int stadsetning, int verd, int lumens) {
    this->skraBunad(new Skjavarpi(nr, stadsetning, verd, lumens));
}

void Husgogn::skraStol(int nr, int stadsetning, int verd, bool snuningur) {
    this->skraBunad(new Stoll(nr, stadsetning, verd, snuningur));
}

void Husgogn::skraTolvu(int nr, int stadsetning, int verd, int kaupar) {
    this->skraBunad(new Tolva(nr, stadsetning, verd, kaupar));
}

bool Husgogn::uppfaeraStadsetningu(int nr, int stadsetning) {
    int idx = this->hash(nr);
    BunadurNode* current = this->heads[idx];
    while (current) {
        if (current->bunadurinn->getNR() == nr) {
            current->bunadurinn->setStadsetning(stadsetning);
            return true;
        }
        current = current->next;
    }
    return false; 
}



bool Husgogn::eydaBunadi(int nr) {
    int idx = this->hash(nr);
    if (this->heads[idx]) {
        if(this->heads[idx]->bunadurinn->getNR() == nr) {
            BunadurNode* new_head = this->heads[idx]->next;
            delete this->heads[idx];
            this->heads[idx] = new_head;
            return true;
        } else {
            BunadurNode* current = this->heads[idx];
            BunadurNode* prev = this->heads[idx];
            while (current && current->bunadurinn->getNR() != nr) {
                prev = current;
                current = current->next;
            }
            if (current) {
                prev->next = current->next;
                delete current;
                return true;
            }
        }
    }
    return false;
}

bool Husgogn::skodaBunad(int nr) {
    int idx = this->hash(nr);
    BunadurNode* current = this->heads[idx];
    while (current) {
        if (current->bunadurinn->getNR() == nr) {
            current->bunadurinn->prenta();
            return true;
        }
        current = current->next;
    }
    return false;
}

void Husgogn::prentaBunadIHusiHaedStofu(int stadsetning) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* current = this->heads[idx];
        while (current) {
            if (current->bunadurinn->getStadsetning() == stadsetning) {
                current->bunadurinn->prenta();
            }
            current = current->next;
        }
    }
}


void Husgogn::prentaBunadIHusi(int hus) {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* current = this->heads[idx];
        while (current) {
            if (current->bunadurinn->getHus() == hus) {
                current->bunadurinn->prenta();
            }
            current = current->next;
        }
    }
}

void Husgogn::prentaAllt() {
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* current = this->heads[idx];
        while (current) {
            current->bunadurinn->prenta();
            current = current->next;
        }
    }
}

void Husgogn::prentaBord() {
    this->prentaAkvednaTegund("Bord");
}

void Husgogn::prentaSkjavarpa() {
    this->prentaAkvednaTegund("Skjavarpi");
}

void Husgogn::prentaStol() {
    this->prentaAkvednaTegund("Stoll");
}

void Husgogn::prentaTolvu() {
    this->prentaAkvednaTegund("Tolva");
}

Husgogn::~Husgogn() {
    for (int idx = 0; idx < this->staerd; idx++) {
        while (this->heads[idx]) {
            BunadurNode* new_head = this->heads[idx]->next;
            delete this->heads[idx];
            this->heads[idx] = new_head;
        }
    }
    delete [] this->heads;
}
