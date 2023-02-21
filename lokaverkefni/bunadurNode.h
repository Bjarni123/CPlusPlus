#pragma once

#include "bunadur.h"

struct BunadurNode {
    Bunadur* bunadurinn;
    BunadurNode* next;

    BunadurNode(Bunadur* bunadurinn) {
        this->bunadurinn = bunadurinn;
        this->next = nullptr;
    }

    ~BunadurNode() {
        delete this->bunadurinn;
    }
};