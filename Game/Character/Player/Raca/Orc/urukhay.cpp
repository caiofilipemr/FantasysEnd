#include "urukhay.h"

const int Urukhay::hay_strenght = 10;
const int Urukhay::hay_agility = 10;
const int Urukhay::hay_intelligence = 7;
const int Urukhay::hay_strenght_level = 2;
const int Urukhay::hay_agility_level = 1;
const int Urukhay::hay_intelligence_level = 0;
const int Urukhay::hay_bonus = AGILITY;
std::string Urukhay::urukhay_img_way = "Character/urukhay.png";
std::string Urukhay::urukhay_img_battle = "Character/urukhay.png";

Urukhay::Urukhay(int new_pos_i, int new_pos_j,
                 Direction new_eye_direction = DOWN) : Orc(new Sword(1),
                                                     new_pos_i, new_pos_j,
                                                     urukhay_img_way,
                                                     urukhay_img_battle,
                                                     new_eye_direction)
{
    this->setStrenght(hay_strenght);
    this->setAgility(hay_agility);
    this->setIntelligence(hay_intelligence);
    this->setStrenghtLevel(hay_strenght_level);
    this->setAgilityLevel(hay_agility_level);
    this->setIntelligencetLevel(hay_intelligence_level);
    this->setBonusLevel(hay_bonus);
}

void Urukhay::setImgWay(std::string new_img_way)
{
    urukhay_img_way = new_img_way;
}

void Urukhay::setImgBattle(string new_img_battle)
{
    urukhay_img_battle = new_img_battle;
}

Urukhay::~Urukhay()
{

}

