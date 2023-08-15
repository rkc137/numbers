#include "sqr.h"

sqr::sqr(int x, int y)
{
    name = new QGraphicsTextItem(QString::number(x * y), this);
}


void sqr::set_pos(int pos_x, int pos_y)
{
    setRect(pos_x * sqr_size, pos_y * sqr_size, sqr_size, sqr_size);
    name->setPos(pos_x * sqr_size, pos_y * sqr_size);
}

void sqr::set_color(bool turn)
{
    if(turn)
    {
        setBrush(QBrush(QColor(255, 0, 0)));
        color = sqr::red;
    }
    else
    {
        setBrush(QBrush(QColor(0, 100, 255)));
        color = sqr::blue;
    }
}

//void set_sqr_size(int square_capacity, int ui_scenes_width)
//{
//    sqr_size = ui_scenes_width / square_capacity;
//}
