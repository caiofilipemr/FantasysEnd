#ifndef ELF_H
#define ELF_H

#include "Character/Player/player.h"

class Elf : public Player
{
private:
    static const int elf_accuracy, elf_dodge, elf_range_damage, elf_critical;
public:
    Elf(Weapon *new_weapon,
        int new_pos_i, int new_pos_j,
        std::string new_img_way, std::string new_img_battle, Direction new_eye_direction);
    void setSpecialCritical(int new_special_critical);
};

#endif // ELF_H
