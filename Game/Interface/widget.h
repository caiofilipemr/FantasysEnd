#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include "bar.h"

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    Bar *barra;
};

#endif // WIDGET_H
