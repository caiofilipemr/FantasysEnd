#include "write.h"

const QString Write::letters_and_numbers[43] = {"Bebas Neueu - Caracteres/0.png", "Bebas Neueu - Caracteres/1.png",
                                                    "Bebas Neueu - Caracteres/2.png", "Bebas Neueu - Caracteres/3.png",
                                                    "Bebas Neueu - Caracteres/4.png", "Bebas Neueu - Caracteres/5.png",
                                                    "Bebas Neueu - Caracteres/6.png", "Bebas Neueu - Caracteres/7.png",
                                                    "Bebas Neueu - Caracteres/8.png", "Bebas Neueu - Caracteres/9.png",
                                                    "", "", "", "", "", "", "",
                                                    "Bebas Neueu - Caracteres/a.png", "Bebas Neueu - Caracteres/b.png",
                                                    "Bebas Neueu - Caracteres/c.png", "Bebas Neueu - Caracteres/d.png",
                                                    "Bebas Neueu - Caracteres/e.png", "Bebas Neueu - Caracteres/f.png",
                                                    "Bebas Neueu - Caracteres/g.png", "Bebas Neueu - Caracteres/h.png",
                                                    "Bebas Neueu - Caracteres/i.png", "Bebas Neueu - Caracteres/j.png",
                                                    "Bebas Neueu - Caracteres/k.png", "Bebas Neueu - Caracteres/l.png",
                                                    "Bebas Neueu - Caracteres/m.png", "Bebas Neueu - Caracteres/n.png",
                                                    "Bebas Neueu - Caracteres/o.png", "Bebas Neueu - Caracteres/p.png",
                                                    "Bebas Neueu - Caracteres/q.png", "Bebas Neueu - Caracteres/r.png",
                                                    "Bebas Neueu - Caracteres/s.png", "Bebas Neueu - Caracteres/t.png",
                                                    "Bebas Neueu - Caracteres/u.png", "Bebas Neueu - Caracteres/v.png",
                                                    "Bebas Neueu - Caracteres/w.png", "Bebas Neueu - Caracteres/x.png",
                                                    "Bebas Neueu - Caracteres/y.png", "Bebas Neueu - Caracteres/z.png",
                                                   }; //Se quiserem add isso em uma macro, fiquem a vontade :D
const QString Write::slash = "Bebas Neueu - Caracteres/barra.png";
const int Write::slash_width = 10;
const int Write::all_number_height = 14;

Write::Write()
{

}

void Write::writeHPorMP(QString p, QString p_max, int bar_x, int bar_y, int bar_w, int bar_h, QPainter *painter)
{
    int x = (bar_w / 2) - (slash_width / 2) + bar_x, y = ((bar_h - all_number_height) / 2) + bar_y, i, w;
    QPixmap actual_number;

    //Escrever a '/'
    painter->drawPixmap(x, y, slash_width, all_number_height, QPixmap(slash));

    //Escrever o HP
    i = p.length() - 1;
    do {
        actual_number = QPixmap(letters_and_numbers[p[i].digitValue()]);
        w = actual_number.width();
        x = x - w;
        painter->drawPixmap(x, y, w, all_number_height, actual_number);
        i--;
    } while (i >= 0);

    //Escrever o HP Max
    x = (bar_w / 2) - (slash_width / 2) + bar_x + slash_width;
    int size = p_max.length();
    for (i = 0; i < size; i++) {
        actual_number = QPixmap(letters_and_numbers[p_max[i].digitValue()]);
        w = actual_number.width();
        painter->drawPixmap(x, y, w, all_number_height, actual_number);
        x = x + w;
    }
}

void Write::writeText(QString text, int x, int y, QPainter *painter)
{
    int i, size, w;
    QPixmap actual_char;

    for (i = 0, size = text.length(); i < size; i++) {
        actual_char= QPixmap(letters_and_numbers[text[i].digitValue()]);
        w = actual_char.width();
        painter->drawPixmap(x, y, w, all_number_height, actual_char);
        x = x + w;
    }
}
