#ifndef ENGINE_H
#define ENGINE_H

#include "map.h"
#include "Character/Monster/stalker.h"
#include "Character/Monster/sleeper.h"
#include "Character/Player/Raca/Elf/archer.h"
#include "Character/Player/Raca/Elf/mage.h"
#include "Character/Player/Raca/Orc/troll.h"
#include "Character/Player/Raca/Orc/urukhay.h"
#include "Character/Player/Raca/Human/barbaro.h"
#include "Character/Player/Raca/Human/rogue.h"
#include "stone.h"
#include "chest.h"
#include "globalfunctions.h"
#include "Enums.h"
#include "globalfunctions.h"
#include "cellarray.h"
#include "battle.h"
#include "Item/randitens.h"
class GUI
{
protected:
    Player * draw_player;
    Map *draw_map;
    std::vector<Monster *> *draw_mobs;
public:
    virtual void drawMap(/*Player * draw_player, Map *draw_map*/) = 0;
    virtual void drawInventory() = 0;
    virtual void drawBattle() = 0;
    virtual void drawBrokenStone() = 0;
    virtual void drawGameOver() = 0;
    virtual void setDrawPlayer(Player * new_draw_player) = 0;
    virtual void setDrawMap(Map * new_draw_map) = 0;
    virtual void setDrawMobs(std::vector<Monster *> * new_draw_mobs) = 0;
    virtual void drawMainMenu() = 0;
    void setCursor(int x, int y);
};



class Engine
{
private:
    static const int number_of_mobs;

    Map *my_map;
    vector<Monster *> mobs;
    Player *my_player;
    Stone *my_stones;
//    Chest *my_chests;
    Monster *battle_mob;
    GUI *engine_GUI;
    Battle *my_battle;
    bool is_battle;
public:
    Engine(GUI * new_engine_GUI);
    ~Engine();
    void update();
    void setPlayerDirection(Direction new_direction);
    Cordenates getPlayerCordenates();
    Cordenates getTemp();
    bool isBattle();
    int battle(BattleOptions op, Exceptions &exc_atk, Exceptions &exc_def);
    void gameOver();
    bool isWalking();
    std::vector<string> getCommands(int index);
    void interation();
    void setPlayer(PlayerClass pc);
};

#endif // ENGINE_H
