#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scena = new QGraphicsScene;
    scena->setSceneRect(1, 1, 400, 400);
    ui->graphicsView->setScene(scena);

    connect(ui->big_dial, SIGNAL(sliderReleased()), this, SLOT(game()));
    connect(ui->little_dial, SIGNAL(sliderReleased()), this, SLOT(game()));
    connect(ui->action_new_game, SIGNAL(triggered()), SLOT(new_game()));
    //connect(ui->lineEdit, SIGNAL(editingFinished()), this, menyay());

    for(int y = 1; y < 10; y++)
    {
        for(int x = 1; x < 10; x++)
        {
            map.insert(x * y, new sqr(x , y));
        }
    }
    sqr *curret_sqr;
    int wall_size = int(qSqrt(map.size()));
    for(int y = 0, i = 0; y < wall_size; y++)
    {
        for(int x = 0; x < wall_size; x++, i++)
        {
            curret_sqr = map[map.keys()[i]];
            curret_sqr->set_pos(x, y);
            scena->addItem(curret_sqr);
        }
    }

}

//https://habr.com/ru/post/183764/  прикол
void MainWindow::game()
{
    sqr *curret_sqr = map[ui->big_dial->value() * ui->little_dial->value()];

    int index_curret_sqr = 0;
    for(int i = 0; i < map.size(); i++)
    {
        if(map[map.keys()[i]] == curret_sqr)
        {
             index_curret_sqr = i;
             break;
        }
    }

    if(curret_sqr->color != sqr::none)
    {
        ui->big_dial->setValue(big_dial_pos);
        ui->little_dial->setValue(little_dial_pos);
        return;
    }
    if(turn)
    {
        curret_sqr->setBrush(QBrush(QColor(255, 0, 0)));
        curret_sqr->color = sqr::red;
    }
    else
    {
        curret_sqr->setBrush(QBrush(QColor(0, 100, 255)));
        curret_sqr->color = sqr::blue;
    }
    big_dial_pos = ui->big_dial->value();
    little_dial_pos = ui->little_dial->value();
    turn = !turn;
    //ниже адский треш от безисходности
//    int wall_size = int(qSqrt(map.size()));
//    for(int i = -1; i < 2; i++)
//    {
//        if((index_curret_sqr - wall_size - i) && curret_sqr->color == map[map.keys()[index_curret_sqr - wall_size - i]]->color) //цвет верхнего сосоеда
//        {
//            if(curret_sqr->color == map[map.keys()[index_curret_sqr + wall_size - i * 2]]->color) //цвет нижнего сосоеда
//            {
//                if(curret_sqr->color == map[map.keys()[index_curret_sqr - (wall_size * 2)] - i * 3]->color) //цвет верхнего сосоеда верхнего сосоеда :)
//                {
//                    qDebug() << "YEAHHHH";
//                }
//                else if(curret_sqr->color == map[map.keys()[index_curret_sqr + (wall_size * 2)] - i * 3]->color)//цвет нижнего нижнего соседа
//                {
//                    qDebug() << "YEAHHHH";
//                }
//            }
//            else if(curret_sqr->color == map[map.keys()[index_curret_sqr - (wall_size * 2) - i * 2]]->color &&
//                    curret_sqr->color == map[map.keys()[index_curret_sqr - (wall_size * 3) - i * 3]]->color)
//            {
//                qDebug() << "YEAHHHH";
//            }
//        }
//        else if(curret_sqr->color == map[map.keys()[index_curret_sqr + wall_size - i]]->color &&
//                curret_sqr->color == map[map.keys()[index_curret_sqr + (wall_size * 2) - i * 2]]->color &&
//                curret_sqr->color == map[map.keys()[index_curret_sqr + (wall_size * 3) - i * 3]]->color)
//        {
//            qDebug() << "YEAHHHH";
//        }
//    }
}

void MainWindow::new_game()
{
    ui->big_dial->setValue(1);
    ui->little_dial->setValue(1);
    big_dial_pos = little_dial_pos = 1;
    sqr *curret_sqr;
    for(int i = 0, keys = map.size(); i < keys; i++)
    {
        curret_sqr = map[map.keys()[i]];
        curret_sqr->color = sqr::none;
        curret_sqr->setBrush(QBrush(QColor(255, 255, 255)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
