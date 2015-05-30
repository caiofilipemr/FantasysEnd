#include "engine.h"

const int Engine::number_of_mobs = 1;

Engine::Engine()
{
    CellArray::instance();
    my_player = new Archer(10, 10, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
    CellArray::instance()->setCell(my_map->getCordenates().i, my_map->getCordenates().j, my_map->getColision());
    mobs = new Monster*[number_of_mobs];
    mobs[0] = new Stalker(10, 10, 10, 10, 1, 90, 6, 5, 3, 2, 1, "", DOWN);
    mobs[0]->setStalk(my_player);
}

void Engine::update()
{
    try {
        if (my_map->hasColision(my_player->getCordenates() + my_player->getDirection())) my_player->update();
        mobs[0]->setDirection(DOWN);
        mobs[0]->setCanGo(my_map->getCanGo(mobs[0]->getCordenates()));
        mobs[0]->update();
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
    return mobs[0]->getCordenates();
}

bool Engine::isBattle()
{
    //Arrumar uma solução MELHOR!!!
    for (int i = 0; i < number_of_mobs; i++) {
        if (mobs[i]) {
            if ((mobs[i]->getCordenates() + UP) == my_player->getCordenates()) {
                battle_mob = mobs[i];
                mobs[i]->setEyeDirection(UP);
                return true;
            }
            if ((mobs[i]->getCordenates() + DOWN) == my_player->getCordenates()) {
                battle_mob = mobs[i];
                mobs[i]->setEyeDirection(DOWN);
                return true;
            }
            if ((mobs[i]->getCordenates() + RIGHT) == my_player->getCordenates()) {
                battle_mob = mobs[i];
                mobs[i]->setEyeDirection(RIGHT);
                return true;
            }
            if ((mobs[i]->getCordenates() + LEFT) == my_player->getCordenates()){
                battle_mob = mobs[i];
                mobs[i]->setEyeDirection(LEFT);
                return true;
            }
        }
    }
    return false;
}
