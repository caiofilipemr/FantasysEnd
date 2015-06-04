#ifndef INVENTORY_H
#define INVENTORY_H

#include <QPainter>

class Inventory
{
public:
    Inventory(int width, int height, int x, int y);
    void setBackground(QPixmap * back);
    ~Inventory();
private:
    int width, height, x, y;
    QPixmap *back;
};

#endif // INVENTORY_H
