#ifndef DIRECTIONVECTOR_H
#define DIRECTIONVECTOR_H

#include "globalfunctions.h"

class DirectionVector
{
private:
    bool directions[4];
public:
    DirectionVector();
    bool & operator [](int i);
    void clear();
};

#endif // DIRECTIONVECTOR_H
