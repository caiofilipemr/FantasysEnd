#include "inventory.h"

Inventory::Inventory(int width, int height, int x, int y):
  width(width), height(height), x(x), y(y)
{}

void Inventory::setBackground(QPixmap *back)
{
  this->back = back;
}

Inventory::~Inventory()
{}

