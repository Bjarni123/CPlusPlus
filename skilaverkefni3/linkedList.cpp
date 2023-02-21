#include "linkedList.h"

LinkedList::LinkedList() {
    this->head = nullptr;
}

void LinkedList::skraUmsaekjanda(Umsaekjandi k) {
    UmsaekjandiNode* ny_gogn = new UmsaekjandiNode(k);
    if (!this->head) { // listinn er tómur
        this->head = ny_gogn;
    } else { // listinn er ekki tómur
        if (this->head->umsaekjandi > k) { // Nýi jakinn á að koma fremst
            ny_gogn->next = this->head;
            this->head = ny_gogn;
        } else { // nýi jakinn að koma einhversstaðar annarsstaðar
            UmsaekjandiNode* current = this->head;
            UmsaekjandiNode* prev = this->head;
            while(current && current->umsaekjandi <= k) {
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

void LinkedList::skraUmsaekjanda(std::string nafn, int aldur, float medaleinkun) {
    this->skraUmsaekjanda(Umsaekjandi(nafn, aldur, medaleinkun));
}

bool LinkedList::eydaUmsaekjanda(std::string nafn) {
    if (!this->head) { // listinn er tómur
        return false;
    }
    if (this->head->umsaekjandi.getNafn() == nafn) { // jakinn sem á að eyða er fremst
        UmsaekjandiNode* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        return true;
    } else { // jakinn er eitthversstaðar annarsstaðar
        UmsaekjandiNode* current = this->head;
        UmsaekjandiNode* prev = this->head;
        while (current && current->umsaekjandi.getNafn() != nafn) {
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

Umsaekjandi LinkedList::saekjaNaesta() {
    if (!this->head) { // listinn er tómur
        return Umsaekjandi();
    }
    Umsaekjandi skilaGildi = this->head->umsaekjandi;
    UmsaekjandiNode* newHead = this->head->next;
    delete this->head;
    this->head = newHead;
    return skilaGildi;
}


void LinkedList::prentaEinnUmsaekjanda(std::string nafn) {
    UmsaekjandiNode* current = this->head;
    while (current && current->umsaekjandi.getNafn() != nafn) {
        current = current->next;
    }
    if (current) {
        std::cout << current->umsaekjandi << std::endl;
    }
}

void LinkedList::prentaAllt() {
    UmsaekjandiNode* current = this->head;
    while (current) {
        std::cout << current->umsaekjandi << std::endl;
        current = current->next;
    }
}

LinkedList::~LinkedList() {
    while (this->head) {
        UmsaekjandiNode* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
    }
}

