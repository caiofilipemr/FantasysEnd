#ifndef ENUMS_H
#define ENUMS_H

enum Direction { UP, DOWN, LEFT, RIGHT, SLEEP };
enum Atributes { STRENGHT, AGILITY, INTELLIGENCE };
enum Exceptions { PLAYER_DIE, MONSTER_DIE,
                  MISS, DODGE, BROKEN_STONE};
enum Base_Item_ID { AGILITY_UP, HEAL_HP, HEAL_MP, INTELLIGENCE_UP,
               STRENGHT_UP, BOW, ROD, DAGGER, MACE, SWORD, AXE };

enum Item_ID { ARMOR, SHIELD, WEAPON, POTION};

#endif // ENUMS_H
