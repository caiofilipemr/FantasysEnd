#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <iostream>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QMediaPlayer>
#include <QFileInfo>
#include <QMouseEvent>

#include "Character/Player/Raca/Elf/archer.h"
#include "Character/Player/Raca/Elf/mage.h"
#include "Character/Player/Raca/Orc/troll.h"
#include "engine.h"
#include "guiqt.h"
#include "Interface/Inventory/inventinterface.h"

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);

public slots:
    void myUpdate();
    void myBattle();

private:
    Ui::Game *ui;
    QTimer *clock;
    Engine *my_engine;
    Direction atual_direction;
    QPainter * painter;
    GUIQT * my_GUI;
    QMediaPlayer *mp;
    bool game_over;
    bool is_battle, is_inventory, interactive_button;
    int x_mouse, y_mouse, i;
};

#endif // GAME_H
