#ifndef ENUMS_H
#define ENUMS_H

enum Direction { DOWN, LEFT, RIGHT, UP, SLEEP };
enum Atributes {AGILITY, STRENGHT, INTELLIGENCE };
enum Exceptions { CHARACTER_DIE, MISS, DODGE, BROKEN_STONE, HIT, GAME_OVER, CRITICAL, OPEN_CHEST, BUFFER};
enum Base_Item_ID { AGILITY_UP_ID, HEAL_HP_ID, HEAL_MP_ID, INTELLIGENCE_UP_ID,
               STRENGHT_UP_ID, AXE_ID, BOW_ID, DAGGER_ID, MACE_ID, ROD_ID, SWORD_ID, ARMOR_ID, SHIELD_ID };
enum Item_ID { ARMOR, SHIELD, WEAPON, POTION};
enum BattleOptions { ATTACK, MAGIC_SPECIAL, ITEM, RUN };
enum Button { PRESS, RELEASE };
enum Colision_Number{PLAYER = 2, MONSTER, OBJECT};
enum PlayerClass{ ARCHER, BARBARO, MAGE, ROGUE, TROLL, URUKHAY };
enum ButtonCursor { BUTTON_LEFT, BUTTON_RIGHT, BC_NONE };
enum doThis { EQUIP_USE, DROP };
enum InventorySelection { IS_INVENTORY, IS_CHEST, IS_WEAPON, IS_SHIELD, IS_ARMOR, IS_NONE };

#endif // ENUMS_H
