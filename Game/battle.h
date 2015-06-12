#ifndef BATTLE_H
#define BATTLE_H

#include "Character/character.h"

class Battle
{
private:
    Character *attacker_fighter, *defenser_fighter;
    static std::string img_monster;
public:
    Battle(Character *fighter_one, Character *fighter_two);
    int attack();
    void magicSpecial();
    void item();
    void run();
    static std::string getImgWayMonster();
    static const std::string background_img_way, cursor_img_way, cursor_change_sound, options_sounds[4];
};

#endif // BATTLE_H
