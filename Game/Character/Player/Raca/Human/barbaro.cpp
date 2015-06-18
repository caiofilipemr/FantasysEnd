#include "barbaro.h"

const int Barbaro::barb_strenght = 14;
const int Barbaro::barb_intelligence = 5;
const int Barbaro::barb_agility = 8;
const int Barbaro::barb_strenght_level = 2;
const int Barbaro::barb_intelligence_level = 0;
const int Barbaro::barb_agility_level = 1;
const int Barbaro::barb_bonus = INTELLIGENCE;
std::string Barbaro::barbaro_img_way = "Character/barbaro.png";
std::string Barbaro::barbaro_img_battle= "Character/barbaro.png";

Barbaro::Barbaro(int new_pos_i, int new_pos_j,
                 Direction new_eye_direction = DOWN): Human(new Axe(1),
                                                      new_pos_i, new_pos_j,
                                                      barbaro_img_way,
                                                      barbaro_img_battle,
                                                      new_eye_direction)
{
    this->setStrenght(barb_strenght);
    this->setAgility(barb_agility);
    this->setIntelligence(barb_intelligence);
    this->setStrenghtLevel(barb_strenght_level);
    this->setAgilityLevel(barb_agility_level);
    this->setIntelligencetLevel(barb_intelligence_level);
    this->setBonusLevel(barb_bonus);
}

void Barbaro::setImgWay(std::string new_img_way)
{
    barbaro_img_way = new_img_way;
}

void Barbaro::setImgBattle(string new_img_battle)
{
    barbaro_img_battle = new_img_battle;
}

Barbaro::~Barbaro()
{
}

