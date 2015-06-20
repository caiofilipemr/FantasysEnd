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
#include <QMediaPlaylist>

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
    void keyReleaseEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent * event);

public slots:
    void mainMenu();
    void myUpdate();
    void myBattle();
    void myInventory();
    void transictionMapBattle();
    void transictionBattleMap();
    void transictionBattleGO();

private:
    Ui::Game *ui;
    QTimer *clock;
    Engine *my_engine;
    Direction atual_direction;
    QPainter * painter;
    GUIQT * my_GUI;
    Qt::Key player_key;
    QMediaPlayer *world_music, *instant_sfx, *battle_music;
    bool game_over, is_player_battle, aux_inv;
    bool is_battle, is_inventory, interactive_button, is_transiction;
    int x_mouse, y_mouse, i, trans_m_b_cont;

    enum PainterOption { P_NONE, P_MAP, P_BATTLE, P_GAME_OVER, P_MAIN_MENU };
    enum PainterTransiction { NONE, OPEN, CLOSE, INVENTORY, STATUS_BAR };
    enum PainterOver { O_NONE, PAUSE };
    PainterOption current_painter_option;
    PainterTransiction current_transiction;
    PainterOver current_over;
};

#endif // GAME_H
