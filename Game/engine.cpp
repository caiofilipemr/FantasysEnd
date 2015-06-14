#include "engine.h"
const int Engine::number_of_mobs = 3;

Engine::Engine(GUI *new_engine_GUI) : engine_GUI(new_engine_GUI)
{
    CellArray::instance();
    my_player = new Archer(40, 60, DOWN);
    my_map = new Map("Maps/mapa.txt", "Images/roguelikeSheet_transparent.png");
    CellArray::instance()->setCell(my_map->getCordenates().i, my_map->getCordenates().j, my_map->getColision());
    mobs.push_back(new Stalker(1, 1, 30, 55, "Battle/drag_es__1.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Walker(1, 1, 35, 60, "Battle/drag_es__1.png","Battle/0 [updated].png", DOWN));
    mobs.push_back(new Sleeper(1, 1, 30, 60, "Battle/drag_es__1.png","Battle/0 [updated].png", DOWN));

    for (size_t i = 0; i < mobs.size(); i++) mobs[i]->setStalk(my_player);

    engine_GUI->setDrawPlayer(my_player);
    engine_GUI->setDrawMap(my_map);
    engine_GUI->setDrawMobs(&mobs);
    my_battle = NULL;
    is_battle = false;
}

void Engine::update()
{
    try {
        my_player->update(my_map);
        for (size_t i = 0; i < mobs.size(); i++) {
            if (!is_battle) {
                mobs[i]->setCanGo(my_map->getCanGo(mobs[i]->getCordenates()));
                mobs[i]->update(my_map);
            }
        }
    } catch (const char * e) { cerr << e << endl; }
}

void Engine::setPlayerDirection(Direction new_direction)
{
    my_player->setDirection(new_direction);
}

Cordenates Engine::getPlayerCordenates()
{
    return my_player->getCordenates();
}

Cordenates Engine::getTemp()
{
    if (mobs.size())
        return mobs[0]->getCordenates();
    return Cordenates(0,0);
}

bool Engine::isBattle()
{
    is_battle = false;
    //Arrumar uma solução MELHOR!!!
    if (/*!mobs[0]->getIsWalking()*/!Monster::getMonsterIsWalking()) {
        for (int i = 0; i < mobs.size(); i++) {
            if (mobs[i]) {
                if ((mobs[i]->getCordenates() + UP) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(UP);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + DOWN) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(DOWN);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + RIGHT) == my_player->getCordenates()) {
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(RIGHT);
                    is_battle = true;
                }
                else if ((mobs[i]->getCordenates() + LEFT) == my_player->getCordenates()){
                    battle_mob = mobs[i];
                    mobs[i]->setEyeDirection(LEFT);
                    is_battle = true;
                }
                if (is_battle) {
                    my_battle = new Battle(my_player, mobs[i]);
                    return is_battle;
                }
            }
        }
    }
    return is_battle;
}

int Engine::battle(BattleOptions op)
{
    if (is_battle) {
        switch (op) {
        case ATTACK:
            try {
                return my_battle->attack();
            } catch (Character * dead_character) {
                try {
                    (dead_character)->die(my_map);
                    size_t i;
                    for (i = 0; i < mobs.size() && mobs[i] != (dead_character); i++);
                    if (i == mobs.size()) throw "Error!";
                    my_player->addXP(mobs[i]->getDropXP());
                    delete mobs[i];
                    mobs.erase(mobs.begin() + i);
                    is_battle = false;
                    delete my_battle;
                    my_battle = NULL;
                    throw CHARACTER_DIE;
                } catch (Exceptions exc) {
                    if (exc == GAME_OVER) {
                        is_battle = false;
                        gameOver();
                        throw;
                    }
                    throw;
                }
            }
            break;

        case MAGIC_SPECIAL:

            break;

        case ITEM:

            break;
 //criar uma static em Monster para saber se o isWalking --SAVIO
        case RUN:

            break;

        default:
            break;
        }
    }
}

void Engine::gameOver()
{

}

bool Engine::isWalking() //talvez temp, estou com sono, nao sei kk
{
    if (my_player->getIsWalking()) return true;
//    for (size_t i = 0; i < mobs.size(); i++) {
//        if (mobs[i]->getIsWalking()) return true;
//    }
    //if (Monster::getMonsterIsWalking()) return true;
    return false;
}

std::vector<string> Engine::getCommands(int index)
{
    std::vector <Commands *> cmds = my_player->getCommands(index);
    std::vector<string> cmd_name;
    for (size_t i = 0; i < cmds.size(); i++) cmd_name[i] = cmds[i]->getCmdName();
    return cmd_name;
}
