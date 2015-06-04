#include "bar.h"
using std::string;

Bar::Bar(int width, int height, int size, const char *color):width(width), height(height), size(size)
{
  size_bar = size;
  prop = float(width)/float(size);

  string name = "Images/Bar/bar";
  name += color;
  name += "_horizontalLeft.png";
  this->begin = new QPixmap(name.c_str());

  name = "Images/Bar/bar";
  name += color;
  name += "_horizontalMid.png";
  this->mid = new QPixmap(name.c_str());

  name = "Images/Bar/bar";
  name += color;
  name += "_horizontalRight.png";
  this->end = new QPixmap(name.c_str());

  this->begin_back = new QPixmap("Images/Bar/barBack_horizontalLeft.png");
  this->mid_back = new QPixmap("Images/Bar/barBack_horizontalMid.png");
  this->end_back = new QPixmap("Images/Bar/barBack_horizontalRight.png");
}

Bar::~Bar()
{}

void Bar::setSizeBar(int size_bar)
{
  this->size_bar = size_bar;
}

QPixmap Bar::getMid()
{
  int w = (width/size)*size - begin->width() - end->width();
  return mid->copy(0, 0, w, height);
}

QPixmap Bar::getEnd()
{
  return *end;
}

QPixmap Bar::getBegin()
{
  return *begin;
}

int Bar::getW()
{
  return width;
}

int Bar::getH()
{
  return height;
}

void Bar::draw(QPainter *obj, int x, int y)
{
  if(!width) return;

  int w = prop*size;

  //Desenhando o fundo
  obj->drawPixmap(x, y, begin->width(), height, *(this->begin_back));
  obj->drawPixmap(x + begin->width(), y, w, height, *(this->mid_back));
  obj->drawPixmap(x + begin->width() + w, y, end->width(), height, *(this->end_back));

  if(!size_bar) return;

  //Aproximando a barra (Savio enjoado)
  if(size_bar == size) w = prop*size;
  else if(prop * size_bar < end->width()/4) w = 1;
  else w = prop * size_bar  - end->width()/4;

  //Desenhando a barra
  obj->drawPixmap(x, y, begin->width(), height, *(this->begin));
  obj->drawPixmap(x + begin->width(), y, w, height, *(this->mid));
  obj->drawPixmap(x + begin->width() + w, y, end->width(), height, *(this->end));
}
