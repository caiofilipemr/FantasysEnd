#ifndef COMMANDS_H
#define COMMANDS_H

#include "Character/Player/player.h"
#include "Item/Potion/potion.h"

class Commands
{
protected:
    const std::string cmd_name;
    Item * do_in_this_item;
public:
    Commands(std::string new_cmd_name, Item * new_do_in_this_item);
    virtual void doThis(Player & player) = 0; //Temp int ? Pois para o comando Catch não existiria tal int
    std::string getCmdName();
};

class EquipWeapon : public Commands {
public:
    EquipWeapon(Item * new_do_in_this_item) : Commands("Equip weapon", new_do_in_this_item) { }
    void doThis(Player &player);
};

class EquipShield: public Commands {
public:
    EquipShield(Item * new_do_in_this_item) : Commands("Equip weapon", new_do_in_this_item) { }
    void doThis(Player &player);
};

class EquipArmor : public Commands {
public:
    EquipArmor(Item * new_do_in_this_item) : Commands("Equip weapon", new_do_in_this_item) { }
    void doThis(Player &player);
};

class Consume : public Commands {
public:
    Consume(Item * new_do_in_this_item) : Commands("Consume", new_do_in_this_item) { }
    void doThis(Player &player);
};

class Drop : public Commands {
public:
    Drop(Item * new_do_in_this_item) : Commands("Drop item", new_do_in_this_item) { }
    void doThis(Player &player);
};

#endif // COMMANDS_H
