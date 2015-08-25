#include "commands.h"
#include "log.h"

Commands::Commands(std::string new_cmd_name, Item *new_do_in_this_item) : cmd_name(new_cmd_name), do_in_this_item(new_do_in_this_item)
{
}

std::string Commands::getCmdName()
{
    return cmd_name;
}


void EquipWeapon::doThis(Player &player) //Temp int ? Pois para o comando Catch não existiria tal int
{
    if (player.canEquipWeapon((Weapon *)do_in_this_item)) {
        if (!player.getWeapon()) {
            player.setWeapon((Weapon *)do_in_this_item); //Seta a arma do jogador!!!
            player.removeItemInventory(do_in_this_item); //Remove a mesma do inventory do player
        } else {
            Weapon * pt = player.getWeapon(); //Else troca os ponteiros, ou seja, o ponteiro que apontava para arma equipada,
            player.setWeapon((Weapon *)do_in_this_item); //agora aponta para a nova arma a ser equipada e
            player.removeItemInventory(do_in_this_item);
            player.addItemInventory(pt); //o ponteiro do inventory aponta para a antiga arma equipada
        }
    }
}

void EquipShield::doThis(Player &player)
{
    if (player.canEquipShield((Shield *)do_in_this_item)) {
        if (!player.getShield()) {
            player.setShield((Shield *)do_in_this_item); //Seta o escudo do jogador!!!
            player.removeItemInventory(do_in_this_item); //Remove o mesmo do inventory do player
        } else {
            Shield * pt = player.getShield(); //Else troca os ponteiros, ou seja, o ponteiro que apontava para o escudo equipada,
            player.setShield((Shield *)do_in_this_item); //agora aponta para o novo escudo a ser equipado e
            player.removeItemInventory(do_in_this_item);
            player.addItemInventory(pt); //o ponteiro do inventory aponta para o antigo escudo equipada
        }
    }
}


void EquipArmor::doThis(Player &player)
{
    if (player.canEquipArmor((Armor *)do_in_this_item)) {
        if (!player.getArmor()) {
            player.setArmor((Armor *)do_in_this_item); //Seta a armadura do jogador!!!
            player.removeItemInventory(do_in_this_item); //Remove a mesma do inventory do player
        } else {
            Armor * pt = player.getArmor(); //Else troca os ponteiros, ou seja, o ponteiro que apontava para armadura equipada,
            player.setArmor((Armor *)do_in_this_item); //agora aponta para a nova armadura a ser equipada e
            player.removeItemInventory(do_in_this_item);
            player.addItemInventory(pt); //o ponteiro do inventory aponta para a antiga armadura equipada
        }
    }
}

void Consume::doThis(Player &player)
{
     Potion *pt = (Potion *)do_in_this_item;
     pt->doEffect(player);
     player.removeItemInventory(do_in_this_item);
     delete do_in_this_item;
}


void Drop::doThis(Player &player)
{
    player.removeItemInventory(do_in_this_item);
    delete do_in_this_item;
    Log::setLog("ITEM DROPPED");
}


