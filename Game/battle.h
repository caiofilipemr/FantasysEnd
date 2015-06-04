#ifndef BATTLE_H
#define BATTLE_H

#include "Character/character.h"

class Battle
{
private:
    Character *attacker_fighter, *defenser_fighter;
public:
    Battle(Character *fighter_one, Character *fighter_two);
    Exceptions attack();
    void magicSpecial();
    void item();
    void run();
};

#endif // BATTLE_H
