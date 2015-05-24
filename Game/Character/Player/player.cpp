#include "player.h"

const int Player::speed_player = 1;
const int Player::mod_HP = 50;
const int Player::mod_MP = 50;
const int Player::mod_Damage = 2;
const int Player::mod_Guard = 1;

void Player::setHP()
{
    hp_max = hp = mod_HP * strenght;
}

void Player::setMP()
{
    mp_max = mp = mod_MP * intelligence;
}

void Player::setDamage()
{
    damage = mod_Damage * weapon->getDamage() * agility;
}

void Player::setGuard()
{
    guard = 0;
    if (armor) guard += armor->getGuard();
    if (shield) guard += shield->getGuard();
    if (weapon) guard += weapon->getGuard();
    guard = mod_Guard * guard;
}

void Player::setStrenght(int new_strenght)
{
    strenght = new_strenght;
    setHP();
}

void Player::setAgility(int new_agility)
{
    agility = new_agility;
    setDamage();
}

void Player::setIntelligence(int new_intelligence)
{
    intelligence = new_intelligence;
    setMP();
}

void Player::setWeapon(Weapon * new_weapon)
{
    weapon = new_weapon;
}

void Player::setShield(Shield *new_shield)
{
    shield = new_shield;
}

void Player::setArmor(Armor *new_armor)
{
    armor = new_armor;
}

void Player::addStrenght(int strenght_plus)
{
    strenght += strenght_plus;
    setHP();
}

void Player::addAgility(int agility_plus)
{
    agility += agility_plus;
    setDamage();
}

void Player::addIntelligence(int intelligence_plus)
{
    intelligence += intelligence_plus;
    setMP();
}

void Player::walk()
{
    switch (walk_direction) {
    case UP:
        pos_i--;
        break;
    case DOWN:
        pos_i++;
        break;

    case LEFT:
        pos_j--;
        break;

    case RIGHT:
        pos_j++;
        break;

    default:
        break;
    }
}

bool Player::canEquipWeapon(int weight){
    return strenght /3 > weight;
}

bool Player::canEquipShield(int weight){
    return strenght/2 > weight;
}

bool Player::canEquipArmor(int weight){
    return strenght > weight;
}

void Player::addItemInventory(Item * new_item){
    inventory->addItem(new_item);
}

Item* Player::removeItemInventory(int item_index){
    return inventory->removeItem(item_index);
}

Item *Player::removeItemInventory(Item * remove_item)
{
    return inventory->removeItem(remove_item);
}

Weapon *Player::getWeapon()
{
    return weapon;
}

Shield *Player::getShield()
{
    return shield;
}

Armor *Player::getArmor()
{
    return armor;
}

Player::Player(Weapon * new_weapon,
               int new_accuracy, int new_dodge,
               int new_range_damage, int new_critical,
               int new_pos_i, int new_pos_j, std::string new_img_way,
               Direction new_eye_direction = DOWN) : Level(),
                                                       Character(speed_player, new_accuracy,
                                                                 new_dodge, new_range_damage,
                                                                 new_critical, new_pos_i,
                                                                 new_pos_j, new_img_way, new_eye_direction),
                                                       weapon(new_weapon)

{
    armor = NULL;
    shield = NULL;
    inventory = new Inventory;
    setGuard();
}
