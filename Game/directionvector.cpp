#include "directionvector.h"

DirectionVector::DirectionVector()
{
    directions[0] = directions[1] = directions[2] = directions[3] = false;
}

bool &DirectionVector::operator [](int i)
{
    if (i < 0 || i > 3) throw "Out of range!!";
    return directions[i];
}

void DirectionVector::clear()
{
    directions[0] = directions[1] = directions[2] = directions[3] = false;
}

