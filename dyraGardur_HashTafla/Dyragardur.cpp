#include "Dyragardur.h"


int Dyragardur::hash(std::string nafn) {
    int hash_gildi = 0;
    for(unsigned int i = 0; i < nafn.length(); i++) {
        hash_gildi += nafn[i];
    }
    return hash_gildi % this->staerd;
}

Dyragardur::Dyragardur() {
    this->staerd = 11;
    this->heads = new DyraNode*[this->staerd]();
}

Dyragardur::Dyragardur(int staerd) {
    this->staerd = staerd;
    this->heads = new DyraNode*[this->staerd]();
}

Dyragardur::Dyragardur(Dyragardur& gamli) {
    this->staerd = gamli.staerd;
    this->heads = new DyraNode*[this->staerd]();
    for (int idx = 0; idx < this->staerd; idx++) {
        DyraNode* gamli_current = gamli.heads[idx];
        while (gamli_current) {
            if (gamli_current->dyrid->getType() == "hundur") {
                Hundur* h = (Hundur*)gamli_current->dyrid;
                this->skraHund(h->getAldur(), h->getNafn(), h->getEinkunn());
            } else if (gamli_current->dyrid->getType() == "köttur") {
                Kottur* k = (Kottur*)gamli_current->dyrid;
                this->skraKott(k->getAldur(), k->getNafn(), k->getEigandi());
            }
            gamli_current = gamli_current->next;
        }
    }
}

Dyragardur& Dyragardur::operator=(Dyragardur& gamli) {
    this->staerd = gamli.staerd;
    this->heads = new DyraNode*[this->staerd]();
    for (int idx = 0; idx < this->staerd; idx++) {
        DyraNode* gamli_current = gamli.heads[idx];
        while (gamli_current) {
            if (gamli_current->dyrid->getType() == "hundur") {
                Hundur* h = (Hundur*)gamli_current->dyrid;
                this->skraHund(h->getAldur(), h->getNafn(), h->getEinkunn());
            } else if (gamli_current->dyrid->getType() == "köttur") {
                Kottur* k = (Kottur*)gamli_current->dyrid;
                this->skraKott(k->getAldur(), k->getNafn(), k->getEigandi());
            }
            gamli_current = gamli_current->next;
        }
    }
    return *this;
}

void Dyragardur::skraDyr(Dyr* dyrid) { // verður raðað
    int idx = this->hash(dyrid->getNafn());
    DyraNode* new_dyr = new DyraNode(dyrid);
    if(!this->heads[idx]) {
        this->heads[idx] = new_dyr;
    } else {
        if (*this->heads[idx]->dyrid >= *dyrid) {
            new_dyr->next = this->heads[idx];
            this->heads[idx] = new_dyr;
        } else {
            DyraNode* current = this->heads[idx];
            DyraNode* prev = this->heads[idx];
            while (current && *current->dyrid <= *dyrid) {
                prev = current;
                current = current->next;
            }
            if (current) {
                new_dyr->next = current;
                prev->next = new_dyr;
            } else {
                prev->next = new_dyr;
            }
        }
    }
}

void Dyragardur::skraHund(int aldur, std::string nafn, int einkunn) {
    this->skraDyr(new Hundur(einkunn, aldur, nafn));
}

void Dyragardur::skraKott(int aldur, std::string nafn, std::string eigandi) {
    this->skraDyr(new Kottur(eigandi, aldur, nafn));
}

bool Dyragardur::eydaDyri(std::string nafn) {
    int idx = this->hash(nafn);
    if (this->heads[idx]) {
        if(this->heads[idx]->dyrid->getNafn() == nafn) {
            DyraNode* new_head = this->heads[idx]->next;
            delete this->heads[idx];
            this->heads[idx] = new_head;
            return true;
        } else {
            DyraNode* current = this->heads[idx];
            DyraNode* prev = this->heads[idx];
            while (current && current->dyrid->getNafn() != nafn) {
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

bool Dyragardur::skodaDyr(std::string nafn) {
    int idx = this->hash(nafn);
    DyraNode* current = this->heads[idx];
    while (current) {
        if (current->dyrid->getNafn() == nafn) {
            current->dyrid->prenta();
            return true;
        }
        current = current->next;
    }
    return false;
}

void Dyragardur::prentaAllt() {
    for (int idx = 0; idx < this->staerd; idx++) {
        DyraNode* current = this->heads[idx];
        std::cout << "Bucket: " << idx << "\n";
        while (current) {
            current->dyrid->prenta();
            current = current->next;
        }
    }
}

void Dyragardur::prentaAkvednaTegund(std::string tegund) {
    for (int idx = 0; idx < this->staerd; idx++) {
        DyraNode* current = this->heads[idx];
        while (current) {
            if (current->dyrid->getType() == tegund) {
                current->dyrid->prenta();
            }
            current = current->next;
        }
    }
}

void Dyragardur::prentaHunda() {
    this->prentaAkvednaTegund("hundur");
}

void Dyragardur::prentaKetti() {
    this->prentaAkvednaTegund("köttur");
}

Dyragardur::~Dyragardur() {
    for (int idx = 0; idx < this->staerd; idx++) {
        while (this->heads[idx]) {
            DyraNode* new_head = this->heads[idx]->next;
            // delete this->heads[idx]->dyrid; þyrfti ef við myndum ekki deletea þessu í DyraNode
            delete this->heads[idx];
            this->heads[idx] = new_head;
        }
    }
    delete [] this->heads;
}
