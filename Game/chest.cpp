#include "chest.h"
const int Chest::max_item = 5;
std::string Chest::chest_img_way = "Images/new_chest.png";

void Chest::randItem(int rand)
{

}

Chest::Chest(int new_pos_i, int new_pos_j) : Object(new_pos_i, new_pos_j, chest_img_way)
{

}

Chest::Chest(int new_pos_i, int new_pos_j, std::string new_img_way,std::vector<Item*> new_item_list) : Object(new_pos_i,new_pos_j,new_img_way)
{
    itens_list = new_item_list;
}

Chest::~Chest()
{

}

Item *Chest::getItem(unsigned int item_index)
{
    if(itens_list.size() < item_index) throw "Item not found";
    return itens_list[item_index];
}

Item *Chest::removeItem(unsigned int item_index)
{
    if(itens_list.size() < item_index) throw "Out of Range! (CHEST)!";
    Item * temp_item = itens_list[item_index];
    itens_list.erase(itens_list.begin() + item_index);
    return temp_item;
}

bool Chest::addItem(Item *new_item)
{
    if(itens_list.size() < max_item) {
        itens_list.push_back(new_item);
        return true;
    }
    return false;
}

void Chest::interate(Player *interate_player)
{
    throw OPEN_CHEST;
}

bool Chest::canAddItem()
{
    return (itens_list.size() + 1) < max_item;
}

void Chest::setImgWay(std::string new_img_way)
{
    chest_img_way = new_img_way;
}

Chest *Chest::getChest()
{
    return this;
}

int Chest::getSize()
{
    return itens_list.size();
}

