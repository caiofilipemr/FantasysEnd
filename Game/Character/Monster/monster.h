#ifndef MONSTER_H
#define MONSTER_H

#include "Character/character.h"

class Monster : public Character
{
protected:
    Object *player;
    int drop_xp, monster_level;
    std::vector<Item*> itens_list;
    void move();
    int per[4], chance[4], back_chance[4];
    static std::string img_monster_die;
    bool *can_go;
    static int quantity_monster, all_is_walking, cont_monster, max_item;
public:
    Monster(int new_level_monster,
            int new_hp, int new_mp,
            int new_damage, int new_guard,
            int new_speed, int new_accuracy,
            int new_dodge, int new_range_damage,
            int new_critical, int new_pos_i,
            int new_pos_j, std::string new_img_way,
            std::string new_img_battle,
            Direction new_eye_direction);
    virtual ~Monster();
    bool addItens(Item * new_item);
    void update(Map * my_map);
    int getDropXP();
    bool canAddItem();
    std::vector<Item*> dropItens();
    int getMonsterLevel();
    void setStalk(Object *player);
    void setCanGo(bool *can);
    void die(Map * my_map);
    static void setImgMonsterDie(std::string new_img_die);
    static bool getMonsterIsWalking();
    void monsterUpdate();
    int getCont();
    static int getContMonster();
};

#endif // MONSTER_H
