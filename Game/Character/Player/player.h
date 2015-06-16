#ifndef PLAYER_H
#define PLAYER_H

#include "Character/Player/level.h"
#include "Character/character.h"
#include "Item/inventory.h"
#include "Item/weapon.h"
#include "Item/shield.h"
#include "Item/armor.h"

class Armor;
class Shield;
class Weapon;

class Player : public Level, public Character
{
private:
    static const int speed_player, mod_HP, mod_MP, mod_Damage, mod_Guard;
protected:
    Weapon *weapon;
    Inventory *inventory;
    Shield *shield;
    Armor *armor;
    Cordenates back_cordenates;

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
           std::string new_img_way, std::string new_img_battle, Direction new_eye_direction);

    void addStrenght(int strenght_plus);
    void addAgility(int agility_plus);
    void addIntelligence(int intelligence_plus);
    void walk();
    void setWeapon(Weapon * new_weapon);
    void setShield(Shield * new_shield);
    void setArmor(Armor * new_armor);
    void setDirection(Direction new_direction);
    bool canEquipWeapon(int weight);
    bool canEquipShield(int weight);
    bool canEquipArmor(int weight);
    void addItemInventory(Item * new_item);
    Item * removeItemInventory(int item_index);
    Item * removeItemInventory(Item * remove_item);
    std::vector<Commands *> getCommands(int index);
    Weapon * getWeapon();
    Shield * getShield();
    Armor * getArmor();
    void update(Map * my_map);
    void die(Map * my_map);
    Cordenates getBackCordenates();
};

#endif // PLAYER_H
