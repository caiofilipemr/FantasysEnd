#include "engine.h"

Engine::Engine()
{
    my_player = new Archer(1, 1, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
}

void Engine::update()
{
    my_player->walk();
}

void Engine::setPlayerDirection(Direction new_direction)
{
    my_player->setDirection(new_direction);
}

Cordenates Engine::getPlayerCordenates()
{
    return my_player->getCordenates();
}
