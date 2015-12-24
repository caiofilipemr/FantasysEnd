#ifndef CORDENATES_H
#define CORDENATES_H

#include "Enums.h"

struct Cordenates {
    int i, j;
    Cordenates(int new_i, int new_j): i(new_i), j(new_j) {}
    Cordenates() { }
    Cordenates operator+ (Direction dir);
    Cordenates operator- (Direction dir);
    bool operator== (Cordenates cord);
    bool operator!= (Cordenates cord);
};

#endif // CORDENATES_H
