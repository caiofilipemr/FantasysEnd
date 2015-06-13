#include "troll.h"

const int Troll::troll_strenght = 20;
const int Troll::troll_agility = 5;
const int Troll::troll_intelligence = 2;
const int Troll::troll_strenght_level = 2;
const int Troll::troll_agility_level = 1;
const int Troll::troll_intelligence_level = 0;
const int Troll::troll_bonus = AGILITY;
std::string Troll::troll_img_way = "";
std::string Troll::troll_img_battle = "";

Troll::Troll(int new_pos_i, int new_pos_j,
             Direction new_eye_direction = DOWN) : Orc(new Mace(1),
                                                 new_pos_i, new_pos_j,
                                                 troll_img_way,
                                                 troll_img_battle,
                                                 new_eye_direction)
{
    this->setStrenght(troll_strenght);
    this->setAgility(troll_agility);
    this->setIntelligence(troll_intelligence);
    this->setStrenghtLevel(troll_strenght_level);
    this->setAgilityLevel(troll_agility_level);
    this->setIntelligencetLevel(troll_intelligence_level);
    this->setBonusLevel(troll_bonus);
}

void Troll::setImgWay(std::string new_img_way)
{
    troll_img_way = new_img_way;
}

void Troll::setImgBattle(string new_img_battle)
{
    troll_img_battle = new_img_battle;
}

Troll::~Troll()
{

}

