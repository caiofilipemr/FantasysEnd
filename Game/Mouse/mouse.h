#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
public:
    Mouse();
    ~Mouse();
    virtual void setCursor(int x, int y) = 0;
protected:
    int x_mouse, y_mouse;
};

#endif // MOUSE_H
