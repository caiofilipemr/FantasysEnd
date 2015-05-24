#include "commands.h"

Commands::Commands(std::string new_cmd_name, Item *new_do_in_this_item) : cmd_name(new_cmd_name), do_in_this_item(new_do_in_this_item)
{
}

std::string Commands::getCmdName()
{
    return cmd_name;
}


void EquipWeapon::doThis(Player &player) //Temp int ? Pois para o comando Catch não existiria tal int
{
    if (player.canEquipWeapon(do_in_this_item->getWeight())) {
        if (!player.getWeapon()) {
            player.setWeapon((Weapon *)do_in_this_item); //Seta a arma do jogador!!!
            player.removeItemInventory(do_in_this_item); //Remove a mesma do inventory do player
        } else {
            Weapon * pt = player.getWeapon(); //Else troca os ponteiros, ou seja, o ponteiro que apontava arma equipada,
            player.setWeapon((Weapon *)do_in_this_item); //agora aponta para a nova arma a ser equipada e
            do_in_this_item = pt; //o ponteiro do inventory aponta para a antiga arma equipada
        }
    } else throw "Player can't equip the item, is too heavy!";
}


void Consume::doThis(Player &player) //Temp int ? Pois para o comando Catch não existiria tal int
{
     Potion *pt = (Potion *)do_in_this_item;
     pt->doEffect(player);
     player.removeItemInventory(do_in_this_item);
     delete do_in_this_item;
}


void Drop::doThis(Player &player) //Temp int ? Pois para o comando Catch não existiria tal int
{
    player.removeItemInventory(do_in_this_item);
    delete do_in_this_item;
}
