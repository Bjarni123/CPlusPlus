#include "isjakarRadad.h"

IsjakarRadad::IsjakarRadad() {
    this->head = nullptr;
}

void IsjakarRadad::skraIsjaka(Isjaki k) {
    IsjakaNode* ny_gogn = new IsjakaNode(k);
    if (!this->head) { // listinn er tómur
        this->head = ny_gogn;
    } else { // listinn er ekki tómur
        if (this->head->jaki > k) { // Nýi jakinn á að koma fremst
            ny_gogn->next = this->head;
            this->head = ny_gogn;
        } else { // nýi jakinn að koma einhversstaðar annarsstaðar
            IsjakaNode* current = this->head;
            IsjakaNode* prev = this->head;
            while(current && current->jaki <= k) {
                prev = current;
                current = current->next;
            }
            if (current) { // Nýi jakinn á að ekki að koma aftast
                ny_gogn->next = current;
                prev->next = ny_gogn;
            } else { // nýi jakinn á að koma aftast
                prev->next = ny_gogn;
            }
        }
    }
}

void IsjakarRadad::skraIsjaka(int id, int staerd, float fjarlaegd) {
    this->skraIsjaka(Isjaki(id, staerd, fjarlaegd));
}

// skila true ef tekst að eyða annars er skilað false
bool IsjakarRadad::eydaIsjaka(int id) {
    if (!this->head) { // listinn er tómur
        return false;
    }
    if (this->head->jaki.getId() == id) { // jakinn sem á að eyða er fremst
        IsjakaNode* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        return true;
    } else { // jakinn er eitthversstaðar annarsstaðar
        IsjakaNode* current = this->head;
        IsjakaNode* prev = this->head;
        while (current && current->jaki.getId() != id) {
            prev = current;
            current = current->next;
        }
        if (current) {
            prev->next = current->next;
            delete current;
            return true;
        } 
        return false;
    }

}

void IsjakarRadad::breytaFjarlaegd(int id, int fjarlaegd) {
    IsjakaNode* current = this->head;
    while (current) {
        if (current->jaki.getId() == id) {
            current->jaki.setFjarlaegd(fjarlaegd);
            return;
        }
        current = current->next;
    }
}

void IsjakarRadad::prentaEinnIsjaka(int id) {
    IsjakaNode* current = this->head;
    while (current && current->jaki.getId() != id) {
        current = current->next;
    }
    if (current) {
        std::cout << current->jaki << std::endl;
    }
}

void IsjakarRadad::prentaAllt() {
    IsjakaNode* current = this->head;
    while (current) {
        std::cout << current->jaki << std::endl;
        current = current->next;
    }
}

IsjakarRadad::~IsjakarRadad() {
    while (this->head) {
        IsjakaNode* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
    }
}
