#include "engine.h"

Engine::Engine()
{
    my_player = new Archer(5, 9, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
    CellArray::instance()->setCell(my_map->getCordenates().i, my_map->getCordenates().j, my_map->getColision());
    mobs = new Monster*[5];
    mobs[0] = new Stalker(10, 10, 10, 10, 1, 90, 6, 5, 3, 8, 8, "", DOWN);
}

void Engine::update()
{
    try {
        if (my_map->hasColision(my_player->getCordenates() + my_player->getDirection())) my_player->update();
        mobs[0]->setStalk(my_player);
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
