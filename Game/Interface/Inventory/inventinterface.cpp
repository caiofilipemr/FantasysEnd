#include "inventinterface.h"

const int InventoryGUI::inv_i = 3;
const int InventoryGUI::inv_j = 5;
const int InventoryGUI::chest_i = 5;

InventoryGUI::InventoryGUI(int width, int height, int widthGUI, int heightGUI, Player *player, QPainter *obj): width(width), height(height),
                                                                                                               x(widthGUI/2 - width/2),
                                                                                                               y(heightGUI/2 - height/2),
                                                                                                               widthGUI(widthGUI), heightGUI(heightGUI),
                                                                                                               player(player), obj(obj)
{
    squary = new QPixmap("Inventory/squary_press.png");
    back = new QPixmap("Inventory/inventory.png");
    row_item = row_command = -1;
    squary_width = width * 0.088889;
    squary_height = height * 0.144145;
    margin_width = width * 0.0078;
    inv = new Rectangle(width * 0.503 + x, height * 0.25 + y, width * 0.467, height * 0.4505);
    chest = new Rectangle(width * 0.503 + x, height * 0.811 + y, width * 0.467, height * 0.1441);
    weapon = new Rectangle(width * 0.397 + x, height * 0.305 + y, 36, 36);
    shield = new Rectangle(width * 0.397 + x, height * 0.56 + y, 36, 36);
    armor = new Rectangle(width * 0.397 + x, height * 0.82 + y, 36, 36);
    messagebox = new MessageBox(0, 0, player);
    message = false;
    current_IS = IS_NONE;
    chestrandom = NULL;
}

void InventoryGUI::setCursor(int x, int y, ButtonCursor click)
{
    x_mouse = x; y_mouse = y;
    cur_click = click;
    action_message.clear();
    is_row_command = false;

    if (cur_click == BUTTON_LEFT) {
        if (message) { //Não é necessário fazer essa pergunta, se a messagebox retornar falso caso não esteja aberta!!! Verificar possibilidade de implemnetar tal carecteristica
            messagebox->setCursor(x_mouse, y_mouse);
            if (messagebox->isColision()) {
                row_command = messagebox->getRowCommand();
                x_mouse = y_mouse = 0;
                message = false;
                is_row_command = true;
                return;
            }
            message = false;
        }
    }
    else if (cur_click == BUTTON_RIGHT) {
        if (inv->is_colision(x_mouse, y_mouse)) {
            int column = (x_mouse - inv->getX()) / (squary_width + margin_width), line = (y_mouse - inv->getY())/(squary_height + margin_width);
            row_item = line * 5 + column % 5;
            if (row_item < player->getInventory()->size()) {
                messagebox->setPosition(x_mouse, y_mouse);
                message = true;
            }
        }
    }

    if (inv->is_colision(x_mouse, y_mouse)) {
        int column = (x_mouse - inv->getX()) / (squary_width + margin_width), line = (y_mouse - inv->getY())/(squary_height + margin_width);
        row_item = line * 5 + column % 5;
        if (row_item < player->getInventory()->size()) current_IS = IS_INVENTORY;
        else current_IS = IS_NONE;
    } else if (chest->is_colision(x_mouse, y_mouse)) {
        int column = (x_mouse - inv->getX()) / (squary_width + margin_width);
        row_item = column % 5;
        if (chestrandom && row_item < chestrandom->getSize()) current_IS = IS_CHEST;
        else current_IS = IS_NONE;
    } else {
        row_item = -1;
        if (weapon->is_colision(x_mouse, y_mouse) && player->getWeapon()) {
            current_IS = IS_WEAPON;
        } else if (player->getShield() && shield->is_colision(x_mouse, y_mouse)) {
            current_IS = IS_SHIELD;
        } else if (player->getArmor() && armor->is_colision(x_mouse, y_mouse)) {
            current_IS = IS_ARMOR;
        } else {
            current_IS = IS_NONE;
        }
    }
}

int InventoryGUI::getRowItem()
{
    return row_item;
}

InventorySelection InventoryGUI::getInventorySelection()
{
    return current_IS;
}

int InventoryGUI::getRowCommand()
{
    return row_command;
}

bool InventoryGUI::isRowCommand()
{
    return is_row_command;
}

void InventoryGUI::draw()
{
    obj->drawPixmap(0, 0, widthGUI, heightGUI, *(this->squary));
    obj->drawPixmap(x, y, width, height, *(this->back));

    int i, s;
    for (i = 0, s = player->getInventory()->size(); i < s; i++) {
        try{
            obj->drawPixmap(width * 0.503 + x + margin_width * (i % 5) + 35 * (i % 5), height * 0.25 + y + 35 * (i / 5) + margin_width * (i / 5),
                            32, 32, QPixmap(QString::fromStdString(player->getInventory()->getItem(i)->getImg_way())));
        } catch(const char * what){
            std::cout << what;
        }
    }
    if (chestrandom) {
        for (i = 0, s = chestrandom->getSize(); i < s; i++) {
        obj->drawPixmap(width * 0.505 + x + margin_width * (i%5) + 35 * (i%5), height * 0.81 + y + 35 * (i / 5) + margin_width * (i / 5),
                        32, 32, QPixmap(QString::fromStdString(chestrandom->getItem(i)->getImg_way())));
        }
    }
    if (player->getWeapon()) obj->drawPixmap(width*0.397 + x, height*0.305 + y,32,32,QPixmap(QString::fromStdString(player->getWeapon()->getImg_way())));
    if (player->getShield()) obj->drawPixmap(width*0.397 + x, height*0.56 + y,32,32,QPixmap(QString::fromStdString(player->getShield()->getImg_way())));
    if (player->getArmor()) obj->drawPixmap(width*0.397 + x, height*0.82 + y,32,32,QPixmap(QString::fromStdString(player->getArmor()->getImg_way())));

    if (!action_message.isEmpty())
        Write::writeText(action_message, 0, 0, 15 * 32, y, obj);

    switch (current_IS) {
    case IS_INVENTORY:
        obj->drawPixmap((row_item % 5) * squary_width + inv->getX() + margin_width * (row_item % 5), (row_item / 5) * squary_height + inv->getY() + (row_item / 5) * margin_width, squary_width, squary_height, *squary);
        showInfos(player->getInventory()->getItem(row_item));
        if (message) messagebox->draw(obj, commands);
        break;

    case IS_CHEST:
        obj->drawPixmap((row_item % 5) * squary_width + chest->getX() + margin_width * (row_item % 5), chest->getY(), squary_width, squary_height, *squary);
        showInfos(chestrandom->getItem(row_item));
        break;

    case IS_WEAPON:
        obj->drawPixmap(width * 0.397 + x, height * 0.305 + y, 36, 36, *squary);
        showInfos(player->getWeapon());
        break;

    case IS_SHIELD:
        obj->drawPixmap(width * 0.397 + x, height * 0.56 + y, 36, 36, *squary);
        showInfos(player->getShield());
        break;

    case IS_ARMOR:
        obj->drawPixmap(width * 0.397 + x, height * 0.82 + y, 36, 36, *squary);
        showInfos(player->getArmor());
        break;

    default:
        break;
    }

}

void InventoryGUI::showInfos(Item *show_item)
{
    Write::writeText(QString::fromStdString(show_item->getItemName()), 0, 0, 15 * 32, y, obj);

    Information info = show_item->getInfos();
    QString info_msg = "   ";

    for (int i = 0; i < info.getSize(); i++) {
        info_msg += QString::fromStdString(info.getInfoName(i));
        info_msg += "  ";
        info_msg += QString::number(info.getInfo(i));
        info_msg += "   ";
    }
    Write::writeText(info_msg, 0, y + height, 15 * 32, heightGUI - (y + height), obj);
}

void InventoryGUI::setChest(Chest *new_chest)
{
    chestrandom = new_chest;
}

void InventoryGUI::setCommands(vector<string> new_commands)
{
    commands = new_commands;
}

void InventoryGUI::clear()
{
    chestrandom = NULL;
    setCursor(0, 0, ButtonCursor(BUTTON_LEFT));
    message = false;
}

void InventoryGUI::clearCursor()
{
    setCursor(0, 0, ButtonCursor(BUTTON_LEFT));
    message = false;
}

int InventoryGUI::takeItemChest()
{
    if (cur_click != BUTTON_RIGHT || current_IS != IS_CHEST) throw "No item to take!";
    current_IS = IS_NONE;
    action_message = "TOOK ITEM";
    return row_item;
}
