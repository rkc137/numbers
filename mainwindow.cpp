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

    connect(ui->big_dial, SIGNAL(sliderReleased()), SLOT(game()));
    connect(ui->little_dial, SIGNAL(sliderReleased()), SLOT(game()));
    connect(ui->action_new_game, SIGNAL(triggered()), SLOT(new_game()));

    for(int y = 1; y < 10; y++)
        for(int x = 1; x < 10; x++)
            map.insert(x * y, new sqr(QString::number(x * y)));

    QMap<int, sqr*>::iterator i = map.begin();
    int wall_size = int(qSqrt(map.size()));
    sqr::set_sqr_size(wall_size, scena->width());
    for(int y = 0; y < wall_size; y++)
    {
        for(int x = 0; x < wall_size; x++, i++)
        {
            i.value()->set_pos(x, y);
            scena->addItem(i.value());
        }
    }
}

//https://habr.com/ru/post/183764/  прикол
void MainWindow::game()
{
    sqr *curret_sqr = map[ui->big_dial->value() * ui->little_dial->value()];

    if(curret_sqr->get_color() != sqr::none)
    {
        ui->big_dial->setValue(big_dial_pos);
        ui->little_dial->setValue(little_dial_pos);
        return;
    }

    curret_sqr->set_color(turn ? sqr::red : sqr::blue);
    turn = !turn;

    big_dial_pos = ui->big_dial->value();
    little_dial_pos = ui->little_dial->value();

/*  int index_curret_sqr = 0;
    for(int i = 0; i < map.size(); i++)
    {
        if(map[map.keys()[i]] == curret_sqr)
        {
             index_curret_sqr = i;//какой же говно код какой ужас а самое главное что это мог кто то увидеть <:O
             break;
        }
    }
    //ниже адский треш от безисходности
    int wall_size = int(qSqrt(map.size()));
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
*/
}

void MainWindow::new_game()
{
    ui->big_dial->setValue(1);
    ui->little_dial->setValue(1);
    big_dial_pos = little_dial_pos = 1;

    for(QMap<int, sqr*>::iterator i = map.begin(); i != map.end(); i++)
        i.value()->set_color(sqr::none);
}

MainWindow::~MainWindow()
{
    delete ui;
}
