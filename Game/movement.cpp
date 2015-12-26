#include "movement.h"
#include "cordenates.h"


Movement::Movement()
{

}

Movement::Movement(Cordenates departure, Cordenates arrival) : std::pair<Cordenates, Cordenates>(departure, arrival)
{

}

bool Movement::operator==(Movement mov)
{
    return (this->first == mov.first && this->second == mov.second);
}

bool Movement::operator!=(Movement mov)
{
    return !(operator ==(mov));
}

