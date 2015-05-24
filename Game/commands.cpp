#include "commands.h"

Commands::Commands(std::string new_cmd_name) : cmd_name(new_cmd_name)
{
}

std::string Commands::getCmdName()
{
    return cmd_name;
}


Log EquipWeapon::doThis(Player &player, Item *&do_in_this_item, int pos_item_in_invetory) //Temp int ? Pois para o comando Catch não existiria tal int
{
    if (player.canEquip()) {
        if (!player.getWeapon()) {
            player.setWeapon(do_in_this_item);

            player.removeItemInventory(pos_item_in_invetory);

            //Problema: Vai existir uma ponteiro no inventario para a arma equipada, ou seja, duplicando o mesmo,
            //se apontar para NULL vai dar problema pois não irá remover do inventário!
            //Problema resolvido com um int, mas provavelmente não é a melhor solução
        } else {
            Weapon * pt = player.getWeapon();
            player.setWeapon(do_in_this_item);
            do_in_this_item = pt;
        }
        return Log(true, "Weapon equiped");
    }
    return Log(false, "Player can't equip the item, is too heavy!");
}


Log Consume::doThis(Player &player, Item *&do_in_this_item, int pos_item_in_invetory) //Temp int ? Pois para o comando Catch não existiria tal int
{
     Potion *pt = (Potion *)do_in_this_item;
     pt->doEffect(player);
     player.removeItemInvetory(pos_item_in_invetory);
}


Log Drop::doThis(Player &player, Item *&do_in_this_item, int pos_item_in_invetory) //Temp int ? Pois para o comando Catch não existiria tal int
{
    player.removeItemInvetory(pos_item_in_invetory);
    delete
}
