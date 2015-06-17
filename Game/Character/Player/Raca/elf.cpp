#include "elf.h"

const int Elf::elf_accuracy = 90;
const int Elf::elf_dodge = 5;
const int Elf::elf_range_damage = 7;
const int Elf::elf_critical = 50;

Elf::Elf(Weapon * new_weapon,
         int new_pos_i, int new_pos_j, std::string new_img_way, string new_img_battle,
         Direction new_eye_direction = DOWN) : Player(new_weapon,
                                                        elf_accuracy, elf_dodge,
                                                        elf_range_damage, elf_critical,
                                                        new_pos_i, new_pos_j, new_img_way,
                                                        new_img_battle,
                                                        new_eye_direction)
{
}
