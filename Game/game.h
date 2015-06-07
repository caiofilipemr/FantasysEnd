#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <iostream>
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>
#include <QMediaPlayer>
#include <QFileInfo>

#include "Character/Player/Raca/Elf/archer.h"
#include "Character/Player/Raca/Elf/mage.h"
#include "Character/Player/Raca/Orc/troll.h"
#include "engine.h"
#include "guiqt.h"

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

public slots:
    void myUpdate();


private:
    Ui::Game *ui;
    QTimer *clock;
    Engine *my_engine;
    Direction atual_direction;
    QPainter * painter;
    GUIQT * my_GUI;
    QMediaPlayer *mp;
    bool is_battle, game_over;
};

#endif // GAME_H
