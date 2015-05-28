#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include "globalfunctions.h"

class Special;
class Weapon;
class Armor;
class Shield;
class Character;
class Player;
class Monster;
class Condition;
class Item;
class Level;
class Potion;
class Inventory;
class Animation;
class Bow;
class Rod;
class Axe;
class Sword;
class Mace;
class Dagger;
class Elf;
class Human;
class Orc;
class Archer;
class Mage;
class Barbaro;
class Rogue;
class Troll;
class Urukhay;

class Object
{
protected:
    int pos_i, pos_j;
    const std::string img_way;
public:
    Object(int new_pos_i, int new_pos_j, std::string new_img_way);
    int getPosI();
    int getPosJ();
    Cordenates getCordenates();
    std::string getImgWay();
};

#endif // OBJECT_H
