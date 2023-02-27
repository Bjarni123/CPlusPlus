#include "husgogn.h"

int Husgogn::hash(int nr) {
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
            if (current->bunadurinn->getType() == "Bord") {
                Bord* b = (Bord*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempVerd = b->getVerd();
                int tempPlass = b->getPlass();
                this->eydaBunadi(nr);
                this->skraBord(tempNr, stadsetning, tempVerd, tempPlass);
            } else if (current->bunadurinn->getType() == "Stoll") {
                Stoll* b = (Stoll*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempVerd = b->getVerd();
                bool tempSnun = b->getSnuningur();
                this->eydaBunadi(nr);
                this->skraStol(tempNr, stadsetning, tempVerd, tempSnun);
            } else if (current->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* b = (Skjavarpi*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempVerd = b->getVerd();
                int tempLumens = b->getLumens();
                this->eydaBunadi(nr);
                this->skraSkjavarpa(tempNr, stadsetning, tempVerd, tempLumens);
            } else if (current->bunadurinn->getType() == "Tolva") {
                Tolva* b = (Tolva*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempVerd = b->getVerd();
                int tempKaupar = b->getKaupar();
                this->eydaBunadi(nr);
                this->skraTolvu(tempNr, stadsetning, tempVerd, tempKaupar);
            } else {
                std::cout << "Villa kom fram. Reyndu aftur\n";
                return false;
            }
            return true;
        }
        current = current->next;
    }
    return false;  
}

bool Husgogn::uppfaeraIndex(int nr, int nyttNr) {
    int idx = this->hash(nr);
    BunadurNode* current = this->heads[idx];
    while (current) {
        if (current->bunadurinn->getNR() == nr) {
            if (current->bunadurinn->getType() == "Bord") {
                Bord* b = (Bord*)current->bunadurinn;
                int tempVerd = b->getVerd();
                int tempStadsetning = b->getStadsetning();
                int tempPlass = b->getPlass();
                this->eydaBunadi(nr);
                this->skraBord(nyttNr, tempStadsetning, tempVerd, tempPlass);
            } else if (current->bunadurinn->getType() == "Stoll") {
                Stoll* b = (Stoll*)current->bunadurinn;
                int tempVerd = b->getVerd();
                int tempStadsetning = b->getStadsetning();
                bool tempSnun = b->getSnuningur();
                this->eydaBunadi(nr);
                this->skraStol(nyttNr, tempStadsetning, tempVerd, tempSnun);
            } else if (current->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* b = (Skjavarpi*)current->bunadurinn;
                int tempVerd = b->getVerd();
                int tempStadsetning = b->getStadsetning();
                int tempLumens = b->getLumens();
                this->eydaBunadi(nr);
                this->skraSkjavarpa(nyttNr, tempStadsetning, tempVerd, tempLumens);
            } else if (current->bunadurinn->getType() == "Tolva") {
                Tolva* b = (Tolva*)current->bunadurinn;
                int tempVerd = b->getVerd();
                int tempStadsetning = b->getStadsetning();
                int tempKaupar = b->getKaupar();
                this->eydaBunadi(nr);
                this->skraTolvu(nyttNr, tempStadsetning, tempVerd, tempKaupar);
            } else {
                std::cout << "Villa kom fram. Reyndu aftur\n";
                return false;
            }
            return true;
        }
        current = current->next;
    }
    return false; 
}

bool Husgogn::uppfaeraVerd(int nr, int verd) {
    int idx = this->hash(nr);
    BunadurNode* current = this->heads[idx];
    while (current) {
        if (current->bunadurinn->getNR() == nr) {
            if (current->bunadurinn->getType() == "Bord") {
                Bord* b = (Bord*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempStadsetning = b->getStadsetning();
                int tempPlass = b->getPlass();
                this->eydaBunadi(nr);
                this->skraBord(tempNr, tempStadsetning, verd, tempPlass);
            } else if (current->bunadurinn->getType() == "Stoll") {
                Stoll* b = (Stoll*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempStadsetning = b->getStadsetning();
                bool tempSnun = b->getSnuningur();
                this->eydaBunadi(nr);
                this->skraStol(tempNr, tempStadsetning, verd, tempSnun);
            } else if (current->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* b = (Skjavarpi*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempStadsetning = b->getStadsetning();
                int tempLumens = b->getLumens();
                this->eydaBunadi(nr);
                this->skraSkjavarpa(tempNr, tempStadsetning, verd, tempLumens);
            } else if (current->bunadurinn->getType() == "Tolva") {
                Tolva* b = (Tolva*)current->bunadurinn;
                int tempNr = b->getNR();
                int tempStadsetning = b->getStadsetning();
                int tempKaupar = b->getKaupar();
                this->eydaBunadi(nr);
                this->skraTolvu(tempNr, tempStadsetning, verd, tempKaupar);
            } else {
                std::cout << "Villa kom fram. Reyndu aftur\n";
                return false;
            }
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

std::string Husgogn::ollGognIStreng(){
    std::string returnGildi = "";
    for (int idx = 0; idx < this->staerd; idx++) {
        BunadurNode* currentStuff = this->heads[idx];
        while (currentStuff) {
            if (currentStuff->bunadurinn->getType() == "Bord") {
                Bord* current = (Bord*)currentStuff->bunadurinn;
                returnGildi += current->getType() + " " + 
                std::to_string(current->getNR()) + " " + 
                std::to_string(current->getStadsetning()) + " " +
                std::to_string(current->getVerd()) + " " + 
                std::to_string(current->getPlass()) + "\n";
            } else if (currentStuff->bunadurinn->getType() == "Stoll") {
                Stoll* current = (Stoll*)currentStuff->bunadurinn;
                returnGildi += current->getType() + " " + 
                std::to_string(current->getNR()) + " " + 
                std::to_string(current->getStadsetning()) + " " +
                std::to_string(current->getVerd()) + " " + 
                std::to_string(current->getSnuningur()) + "\n";
            } else if (currentStuff->bunadurinn->getType() == "Skjavarpi") {
                Skjavarpi* current = (Skjavarpi*)currentStuff->bunadurinn;
                returnGildi += current->getType() + " " + 
                std::to_string(current->getNR()) + " " + 
                std::to_string(current->getStadsetning()) + " " +
                std::to_string(current->getVerd()) + " " + 
                std::to_string(current->getLumens()) + "\n";
            } else if (currentStuff->bunadurinn->getType() == "Tolva") {
                Tolva* current = (Tolva*)currentStuff->bunadurinn;
                returnGildi += current->getType() + " " + 
                std::to_string(current->getNR()) + " " + 
                std::to_string(current->getStadsetning()) + " " +
                std::to_string(current->getVerd()) + " " + 
                std::to_string(current->getKaupar()) + "\n";
            } else {
                std::cout << "Villa kom fram. Reyndu aftur\n";
            }
            currentStuff = currentStuff->next;
        }
    }
    return returnGildi;
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
