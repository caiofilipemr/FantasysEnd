#include "battle.h"

Battle::Battle(Character **fighter_one, Character **fighter_two) : attacker_fighter(fighter_one), defenser_fighter(fighter_two)
{
}

Exceptions Battle::attack()
{
    try {
        (*defenser_fighter)->defense((*attacker_fighter)->attack());
        Character **change_fighter = defenser_fighter;
        defenser_fighter = attacker_fighter;
        attacker_fighter = change_fighter;
        return HIT;
    } catch (Exceptions exc) {
        if (exc == CHARACTER_DIE) {
            throw defenser_fighter;
        }
        return exc;
    }
}

void Battle::magicSpecial()
{

}

void Battle::item()
{

}

void Battle::run()
{

}
