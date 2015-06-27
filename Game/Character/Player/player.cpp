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
    inventory->setMaxWeight(strenght);
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
    setDamage();
    setGuard();
}

void Player::setShield(Shield *new_shield)
{
    shield = new_shield;
    setGuard();
}

void Player::setArmor(Armor *new_armor)
{
    armor = new_armor;
    setGuard();
}

void Player::setDirection(Direction new_direction)
{
    if (this->eye_direction == new_direction || new_direction == SLEEP) this->walk_direction = new_direction;
    else if (!(this->is_walking)) this->eye_direction = new_direction;
}

void Player::addStrenght(int strenght_plus)
{
    strenght += strenght_plus;
    setHP();
    inventory->setMaxWeight(strenght);
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

bool Player::canEquipWeapon(Weapon *w){
    return (w->getLevelItem() <= level && w->getWeight() <= strenght);
}

bool Player::canEquipShield(Shield *s){
    return (s->getLevelItem() <= level && s->getWeight() <= strenght / 2);
}

bool Player::canEquipArmor(Armor *a){
    return (a->getLevelItem() <= level && a->getWeight() <= strenght);
}

void Player::addItemInventory(Item * new_item){
    inventory->addItem(new_item);
}

Item* Player::removeItemInventory(int item_index){
    return inventory->removeItem(item_index);
}

Inventory* Player::getInventory(){
  return inventory;
}

Item *Player::removeItemInventory(Item * remove_item)
{
    return inventory->removeItem(remove_item);
}

std::vector<Commands *> Player::getCommands(int index)
{
    return inventory->getItem(index)->getCommands();
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

void Player::update(Map *my_map)
{
    if (is_walking) {
        if (cont < limit)
            cont++;
        else {
            is_walking = false;
            cont = 0;
            back_cordenates.i = this->pos_i; //Não esta sendo usado
            back_cordenates.j = this->pos_j;
            my_map->removeAColision(Cordenates(this->pos_i, this->pos_j));
            walk_direction = SLEEP;
        }
    }
    else {
        Cordenates cord = Cordenates(this->pos_i, this->pos_j) + walk_direction;
        if (walk_direction != SLEEP && !my_map->hasColision(cord)) { //Se vai andar para algum lugar e se esse lugar não tiver colisão, então:
            my_map->setAColision(cord);
            is_walking = true;
            this->walk();
        }
    }
}

void Player::die(Map *)
{
    throw GAME_OVER;
}

Cordenates Player::getBackCordenates()
{
    return back_cordenates;
}

void Player::setInventory(Inventory *inv)
{
    inventory = inv;
}

Player::Player(Weapon * new_weapon,
               int new_accuracy, int new_dodge,
               int new_range_damage, int new_critical,
               int new_pos_i, int new_pos_j, std::string new_img_way, string new_img_battle,
               Direction new_eye_direction = DOWN) : Level(),
                                                       Character(speed_player, new_accuracy,
                                                                 new_dodge, new_range_damage,
                                                                 new_critical, new_pos_i,
                                                                 new_pos_j, new_img_way, new_img_battle, new_eye_direction),
                                                                 weapon(new_weapon), back_cordenates(new_pos_i, new_pos_j)

{
    armor = NULL;
    shield = NULL;
    inventory = new Inventory;
    setGuard();
}
