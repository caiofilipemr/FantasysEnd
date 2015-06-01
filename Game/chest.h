#ifndef CHEST_H
#define CHEST_H

#include "object.h"
#include <vector>

class Chest : public Object
{
private:
    std::vector<Item*> itens_list;
    void randItem(int rand);
    static const int max_item;
public:
    Chest(int new_pos_i, int new_pos_j, std::string new_img_way);
    ~Chest();
    Item *getItem(unsigned int item_index);
    Item *removeItem(unsigned int item_index);
    bool addItem(Item * new_item);
};

#endif // CHEST_H
