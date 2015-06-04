#include "engine.h"

const int Engine::number_of_mobs = 1;

Engine::Engine(GUI *new_engine_GUI) : engine_GUI(new_engine_GUI)
{
    CellArray::instance();
    my_player = new Archer(30, 30, DOWN);
    my_map = new Map("mapa.txt", "roguelikeSheet_transparent.png");
    CellArray::instance()->setCell(my_map->getCordenates().i, my_map->getCordenates().j, my_map->getColision());
    mobs.push_back(new Stalker(10, 10, 10, 10, 1, 90, 6, 5, 3, 30, 31, "", DOWN));
    mobs[0]->setStalk(my_player);
    engine_GUI->setDrawPlayer(my_player);
    engine_GUI->setDrawMap(my_map);
    my_battle = NULL;
}

void Engine::update()
{
    try {
        my_player->update(my_map);
        for (int i = 0; i < mobs.size(); i++) {
            mobs[i]->setDirection(DOWN);
            mobs[i]->setCanGo(my_map->getCanGo(mobs[i]->getCordenates()));
            mobs[i]->update(my_map);
            //engine_GUI->drawMap(my_player, my_map);
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
    return mobs[0]->getCordenates();
}

bool Engine::isBattle()
{
    //Arrumar uma solução MELHOR!!!
    bool is_battle = false;
    for (int i = 0; i < number_of_mobs; i++) {
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
            Character *temp1 = my_player, *temp2 = mobs[i];
            my_battle = new Battle(&temp1, &temp2);
            return is_battle;
        }
    }
    return is_battle;
}

void Engine::battle(BattleOptions op)
{
    switch (op) {
    case ATTACK:
        std::cerr << "HP player: " << my_player->getHP();
        std::cerr << "HP player: " << mobs.front()->getHP();
        try {
            my_battle->attack();
        } catch (Exceptions exc) {
            throw;
        } catch (Character ** dead_character) {
            try {
                (*dead_character)->die(my_map);
                size_t i;
                for (i = 0; i < mobs.size() && mobs[i] != (*dead_character); i++);
                if (i == mobs.size()) throw "Error!";
                my_player->addXP(mobs[i]->getDropXP());
                delete mobs[i];
                mobs.erase(mobs.begin() + i);
            } catch (Exceptions exc) {
                if (exc == GAME_OVER) gameOver();
                else throw;
            }
        }
        break;

    case MAGIC_SPECIAL:

        break;

    case ITEM:

        break;

    case RUN:

        break;

    default:
        break;
    }
}

void Engine::gameOver()
{

}
