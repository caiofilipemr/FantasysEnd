#include "archer.h"

const int Archer::arc_strenght = 4;
const int Archer::arc_agility = 13;
const int Archer::arc_intelligence = 10;
const int Archer::arc_strenght_level = 1;
const int Archer::arc_agility_level = 2;
const int Archer::arc_intelligence_level = 0;
const int Archer::arc_bonus = INTELLIGENCE;
std::string Archer::archer_img_way = "Images/characters_1.png";

Archer::Archer(int new_pos_i, int new_pos_j,
               Direction new_eye_direction = DOWN) : Elf(new Bow(1),
                                                   new_pos_i, new_pos_j, archer_img_way,
                                                   new_eye_direction)
{
    this->setStrenght(arc_strenght);
    this->setAgility(arc_agility);
    this->setIntelligence(arc_intelligence);
    this->setStrenghtLevel(arc_strenght_level);
    this->setAgilityLevel(arc_agility_level);
    this->setIntelligencetLevel(arc_intelligence_level);
    this->setBonusLevel(arc_bonus);
}

void Archer::setImgWay(std::string new_img_way)
{
    archer_img_way = new_img_way;
}
