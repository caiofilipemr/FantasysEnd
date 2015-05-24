#ifndef PLAYER_H
#define PLAYER_H

#include "Character/Player/level.h"
#include "Character/character.h"
#include "Item/inventory.h"
#include "Item/weapon.h"
#include "Item/shield.h"
#include "Item/armor.h"

class Player : public Level, public Character
{
private:
    static const int speed_player, mod_HP, mod_MP, mod_Damage, mod_Guard;
protected:
    Weapon *weapon;
    Inventory *inventory;
    Shield *shield;
    Armor *armor;

    void setHP();
    void setMP();
    void setGuard();
    void setDamage();
    void setStrenght(int new_strenght);
    void setAgility(int new_agility);
    void setIntelligence(int new_intelligence);


public:
    Player(Weapon * new_weapon,
           int new_accuracy, int new_dodge,
           int new_range_damage, int new_critical,
           int new_pos_i, int new_pos_j,
           std::string new_img_way, Direction new_eye_direction);

    void addStrenght(int strenght_plus);
    void addAgility(int agility_plus);
    void addIntelligence(int intelligence_plus);
    void walk();
    void setWeapon(Weapon * new_weapon);
    bool canEquipWeapon(int weight);
    bool canEquipShield(int weight);
    bool canEquipArmor(int weight);
    void addItemInventory(Item * new_item);
    Item* removeItemInvetory(int item_index);
    Weapon * getWeapon();
};

#endif // PLAYER_H
