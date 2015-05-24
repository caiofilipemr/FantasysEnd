#ifndef COMMANDS_H
#define COMMANDS_H

#include "Character/Player/player.h"
#include "Item/item.h"
#include "Item/Potion/potion.h"

class Commands
{
private:
    const std::string cmd_name;
public:
    Commands(std::string new_cmd_name);
    virtual Log doThis(Player & player, Item * &do_in_this_item, int pos_item_in_invetory) = 0; //Temp int ? Pois para o comando Catch não existiria tal int
    std::string getCmdName();
};

class EquipWeapon : public Commands {
public:
    EquipWeapon() : Commands("Equip weapon") { }
    Log doThis(Player &player, Item * &do_in_this_item, int pos_item_in_invetory);
};

class Consume : public Commands {
public:
    Consume() : Commands("Use") { }
    Log doThis(Player &player, Item * &do_in_this_item, int pos_item_in_invetory);
};

class Drop : public Commands {
public:
    Drop() : Commands("Drop item") { }
    Log doThis(Player &player, Item * &do_in_this_item, int pos_item_in_invetory);
};

#endif // COMMANDS_H
