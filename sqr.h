#ifndef SQR_H
#define SQR_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>

const int sqr_size = 67;

class sqr : public QGraphicsRectItem
{

public:
    explicit sqr(int x, int y);
    enum Color
    {
        none,
        red,
        blue
    };
    Color get_color() const;
    void set_pos(int pos_x, int pos_y);
    void set_color(enum Color c);

private:
    QGraphicsTextItem *name;
    Color color = none;
};

//void set_sqr_size(int square_capacity, int ui_scenes_width);

#endif // SQR_H
