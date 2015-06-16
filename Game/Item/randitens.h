#ifndef RANDITENS_H
#define RANDITENS_H

#include "globalfunctions.h"
#include "Item/weapons/axe.h"
#include "Item/weapons/bow.h"
#include "Item/weapons/dagger.h"
#include "Item/weapons/mace.h"
#include "Item/weapons/rod.h"
#include "Item/weapons/sword.h"
#include "Item/Potion/agilityup.h"
#include "Item/Potion/healfhp.h"
#include "Item/Potion/healfmp.h"
#include "Item/Potion/intelligenceup.h"
#include "Item/Potion/strengtup.h"
#include "Item/armor.h"
#include "Item/shield.h"
#include <vector>

class RandItens
{
private:
    std::vector<Item *> itens_list;
    static const int qtd_itens_rand;
public:
    RandItens();
    void randItensMap();
};

#endif // RANDITENS_H
