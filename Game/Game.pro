#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T16:49:39
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    Character/Monster/monster.cpp \
    Character/Monster/sleeper.cpp \
    Character/Monster/stalker.cpp \
    Character/Monster/walker.cpp \
    Character/Player/player.cpp \
    Character/character.cpp \
    Item/Potion/agilityup.cpp \
    Item/Potion/healfhp.cpp \
    Item/Potion/healfmp.cpp \
    Item/Potion/intelligenceup.cpp \
    Item/Potion/potion.cpp \
    Item/Potion/strengtup.cpp \
    Item/armor.cpp \
    Item/item.cpp \
    Item/shield.cpp \
    Item/weapon.cpp \
    chest.cpp \
    object.cpp \
    stone.cpp \
    Character/Player/level.cpp \
    Item/weapons/bow.cpp \
    Item/weapons/sword.cpp \
    Item/weapons/axe.cpp \
    Item/weapons/dagger.cpp \
    Item/weapons/rod.cpp \
    Item/weapons/mace.cpp \
    Character/Player/Raca/elf.cpp \
    Character/Player/Raca/Elf/archer.cpp \
    Character/Player/Raca/Elf/mage.cpp \
    Character/Player/Raca/human.cpp \
    Character/Player/Raca/orcs.cpp \
    Character/Player/Raca/Human/barbaro.cpp \
    Character/Player/Raca/Human/rogue.cpp \
    Character/Player/Raca/Orc/troll.cpp \
    Character/Player/Raca/Orc/urukhay.cpp \
    Item/inventory.cpp \
    globalfunctions.cpp \
    cellarray.cpp \
    map.cpp \
    commands.cpp \
    engine.cpp \
    interation.cpp \
    guiqt.cpp \
    battle.cpp \
    Interface/Bar/bar.cpp \
    Interface/Inventory/inventinterface.cpp \
    Interface/Inventory/Colision/colision.cpp \
    Interface/Inventory/Colision/rectangle.cpp \
    Mouse/mouse.cpp \
    Interface/Inventory/messagebox.cpp \
    Interface/Write/write.cpp \
    cordenates.cpp \
    Item/randitens.cpp \
    Interface/mainmenu.cpp \
    Interface/StatusBar/statusbar.cpp \
    directionvector.cpp
    Item/randitens.cpp

HEADERS  += game.h \
    Character/Monster/monster.h \
    Character/Monster/sleeper.h \
    Character/Monster/stalker.h \
    Character/Monster/walker.h \
    Character/Player/level.h \
    Character/Player/player.h \
    Character/character.h \
    Item/Potion/agilityup.h \
    Item/Potion/healfhp.h \
    Item/Potion/healfmp.h \
    Item/Potion/intelligenceup.h \
    Item/Potion/potion.h \
    Item/Potion/strengtup.h \
    Item/armor.h \
    Item/item.h \
    Item/shield.h \
    Item/weapon.h \
    chest.h \
    object.h \
    stone.h \
    Item/weapons/bow.h \
    Item/weapons/sword.h \
    Item/weapons/axe.h \
    Item/weapons/dagger.h \
    Item/weapons/rod.h \
    Item/weapons/mace.h \
    Character/Player/Raca/elf.h \
    Character/Player/Raca/Elf/archer.h \
    Character/Player/Raca/Elf/mage.h \
    Enums.h \
    Character/Player/Raca/human.h \
    Character/Player/Raca/orcs.h \
    Character/Player/Raca/Human/barbaro.h \
    Character/Player/Raca/Human/rogue.h \
    Character/Player/Raca/Orc/troll.h \
    Character/Player/Raca/Orc/urukhay.h \
    Item/inventory.h \
    globalfunctions.h \
    macros.h \
    cellarray.h \
    map.h \
    commands.h \
    engine.h \
    interation.h \
    guiqt.h \
    battle.h \
    Interface/Bar/bar.h \
    Interface/Inventory/inventinterface.h \
    Interface/Inventory/Colision/colision.h \
    Interface/Inventory/Colision/rectangle.h \
    Mouse/mouse.h \
    Interface/Inventory/messagebox.h \
    Interface/Write/write.h \
    cordenates.h \
    Item/randitens.h \
    Interface/mainmenu.h \
    Interface/StatusBar/statusbar.h \
    directionvector.h
    Item/randitens.h

FORMS    += game.ui

RESOURCES += \
    Images.qrc
