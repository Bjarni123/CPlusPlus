#pragma once

#include "Dyr.h"

struct DyraNode {
    Dyr* dyrid;
    DyraNode* next;

    DyraNode(Dyr* dyrid) {
        this->dyrid = dyrid;
        this->next = nullptr;
    }

    ~DyraNode() {
        delete this->dyrid;
    }
};