#pragma once

#include "umsaekjandi.h"
#include "node.h"

class LinkedList {
    private:
        UmsaekjandiNode* head;
    public:
        LinkedList();
        void skraUmsaekjanda(Umsaekjandi k);
        void skraUmsaekjanda(std::string nafn, int aldur, float medaleinkun);
        bool eydaUmsaekjanda(std::string nafn);
        Umsaekjandi saekjaNaesta();
        void prentaEinnUmsaekjanda(std::string nafn);
        void prentaAllt();
        ~LinkedList();
};