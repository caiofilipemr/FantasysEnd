#include "randitens.h"

const int RandItens::qtd_itens_rand = 20;

RandItens::RandItens()
{
}
void RandItens::randItensMap()
{
    int k = 0, item_index;
    while( k < qtd_itens_rand) {
            item_index = (random(13));
        switch (item_index) {
        case AGILITY_UP_ID:
            itens_list.push_back(new AgilityUP);
            break;
        case HEAL_HP_ID:
            itens_list.push_back(new HealfHP());
            break;
        case HEAL_MP_ID:
            itens_list.push_back(new HealfMP());
            break;
        case INTELLIGENCE_UP_ID:
            itens_list.push_back(new IntelligenceUP());
            break;
        case STRENGHT_UP_ID:
            itens_list.push_back(new StrengtUP());
            break;
        case AXE_ID:
            itens_list.push_back(new Axe(0));
            break;
        case BOW_ID:
            itens_list.push_back(new Bow(0));
            break;
        case DAGGER_ID:
            itens_list.push_back(new Dagger(0));
            break;
        case MACE_ID:
            itens_list.push_back(new Mace(0));
            break;
        case ROD_ID:
            itens_list.push_back(new Rod(0));
            break;
        case SWORD_ID:
            itens_list.push_back(new Sword(0));
            break;
        case ARMOR_ID:
            itens_list.push_back(new Armor(0));
            break;
        case SHIELD_ID:
            itens_list.push_back(new Shield(0));
            break;
        default:
            break;
        }
        k++;
    }
}
