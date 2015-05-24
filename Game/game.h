#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <iostream>

#include "Character/Player/Raca/Elf/archer.h"
#include "Character/Player/Raca/Elf/mage.h"
#include "Character/Player/Raca/Orc/troll.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private:
    Ui::Game *ui;
};

#endif // GAME_H
