#include "sqr.h"

sqr::sqr(int x, int y) : QGraphicsRectItem((x - 1) * sqr_size, (y - 1) * sqr_size, sqr_size, sqr_size)
{
    name = new QGraphicsTextItem(QString::number(x * y), this);
    name->setPos(QPoint(rect().x(), rect().y()));
}

sqr::Color sqr::get_color() const
{
    return color;
}

void sqr::set_color(enum Color c)
{
    color = c;
    switch(color)
    {
    case red:
        setBrush(QBrush(QColor(255, 0, 0)));
        break;
    case blue:
        setBrush(QBrush(QColor(0, 100, 255)));
        break;
    case none:
        setBrush(QBrush(QColor(255, 255, 255)));
    }
}

void sqr::set_sqr_size(int square_capacity, int ui_scenes_width)
{
    sqr_size = ui_scenes_width / square_capacity;
}
