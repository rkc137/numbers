#include "sqr.h"

sqr::sqr(QString num)
{
    name = new QGraphicsTextItem(num, this);
}

sqr::Color sqr::get_color() const
{
    return color;
}

void sqr::set_pos(int pos_x, int pos_y)
{
    setRect(pos_x * sqr_size, pos_y * sqr_size, sqr_size, sqr_size);
    name->setPos(pos_x * sqr_size, pos_y * sqr_size);
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
