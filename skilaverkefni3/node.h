#pragma once

#include "umsaekjandi.h"

struct UmsaekjandiNode {
    Umsaekjandi umsaekjandi; // data
    UmsaekjandiNode* next;
    
    
    UmsaekjandiNode(Umsaekjandi umsaekjandi) {
        this->umsaekjandi = umsaekjandi;
        this->next = nullptr;
    }
};