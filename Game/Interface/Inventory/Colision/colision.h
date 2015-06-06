#ifndef COLISION_H
#define COLISION_H


class Colision
{
public:
  Colision(int x, int y);
  ~Colision();
  virtual bool is_colision(int x, int y) const = 0;
  int getX();
  int getY();

protected:
  int x, y;

};

#endif // COLISION_H
