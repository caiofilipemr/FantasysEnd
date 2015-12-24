#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <utility>

class Cordenates;
class Movement : public std::pair<Cordenates, Cordenates>
{
public:
    Movement(Cordenates departure, Cordenates arrival);
    bool operator==(Movement mov);
    bool operator!=(Movement mov);
};

#endif // MOVEMENT_H
