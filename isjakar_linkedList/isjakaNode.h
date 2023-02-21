#pragma once

#include "isjaki.h"

struct IsjakaNode {
    Isjaki jaki; // data
    IsjakaNode* next;
    
    
    IsjakaNode(Isjaki jaki) {
        this->jaki = jaki;
        this->next = nullptr;
    }
};