#include "cordenates.h"

Cordenates Cordenates::operator+(Direction dir)
{
    Cordenates cord = *this;
    switch (dir) {
    case UP:
        cord.i--;
        break;

    case DOWN:
        cord.i++;
        break;

    case LEFT:
        cord.j--;
        break;

    case RIGHT:
        cord.j++;
        break;

    default:
        break;
    }
    return cord;
}

Cordenates Cordenates::operator-(Direction dir)
{
    Cordenates cord = *this;
    switch (dir) {
    case UP:
        cord.i++;
        break;

    case DOWN:
        cord.i--;
        break;

    case LEFT:
        cord.j++;
        break;

    case RIGHT:
        cord.j--;
        break;

    default:
        break;
    }
    return cord;
}

bool Cordenates::operator==(Cordenates cord)
{
    return (i == cord.i && j == cord.j);
}
