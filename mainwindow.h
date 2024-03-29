#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QtMath>
#include <QMap>
#include <QDebug>
#include "sqr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scena;
    QMap<int, sqr*> map;
    int wall_size = 9;
    bool turn = false;
    int big_dial_pos = 1, little_dial_pos = 1;

public slots:
    void move();
    void new_game();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
