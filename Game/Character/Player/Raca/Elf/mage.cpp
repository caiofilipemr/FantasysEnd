#include "mage.h"

const int Mage::mage_strenght = 4;
const int Mage::mage_agility = 5;
const int Mage::mage_intelligence = 18;
const int Mage::mage_strenght_level = 1;
const int Mage::mage_agility_level = 0;
const int Mage::mage_intelligence_level = 2;
const int Mage::mage_bonus = AGILITY;
std::string Mage::mage_img_way = "Images/characters_1.png";
std::string Mage::mage_img_battle = "";

Mage::Mage(int new_pos_i, int new_pos_j,
           Direction new_eye_direction = DOWN) : Elf(new Rod(1),
                                               new_pos_i, new_pos_j,
                                               mage_img_way,
                                               mage_img_battle,
                                               new_eye_direction)
{
    this->setStrenght(mage_strenght);
    this->setAgility(mage_agility);
    this->setIntelligence(mage_intelligence);
    this->setStrenghtLevel(mage_strenght_level);
    this->setAgilityLevel(mage_agility_level);
    this->setIntelligencetLevel(mage_intelligence_level);
    this->setBonusLevel(mage_bonus);
}

void Mage::setImgWay(std::string new_img_way)
{
    mage_img_way = new_img_way;
}

void Mage::setImgBattle(string new_img_battle)
{
    mage_img_battle = new_img_battle;
}
