#ifndef SQR_H
#define SQR_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>

class sqr : public QGraphicsRectItem
{

public:
    static void set_sqr_size(int square_capacity, int ui_scenes_width);
    explicit sqr(QString num);
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
    inline static int sqr_size = 67;

    QGraphicsTextItem *name;
    Color color = none;
};

#endif // SQR_H
