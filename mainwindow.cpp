#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scena = new QGraphicsScene;
    scena->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->setScene(scena);

    connect(ui->big_dial, SIGNAL(sliderReleased()), SLOT(move()));
    connect(ui->little_dial, SIGNAL(sliderReleased()), SLOT(move()));
    connect(ui->action_new_game, SIGNAL(triggered()), SLOT(new_game()));

    sqr::set_sqr_size(wall_size, scena->width());
    for(int y = 1; y < wall_size + 1; y++)
    {
        for(int x = 1; x < wall_size + 1; x++)
        {
            map.insert(x * y, new sqr(x, y));
            scena->addItem(map[x * y]);
        }
    }
}

void MainWindow::move()
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
}

void MainWindow::new_game()
{
    big_dial_pos = little_dial_pos = 1;
    ui->big_dial->setValue(big_dial_pos);
    ui->little_dial->setValue(little_dial_pos);

    for(QMap<int, sqr*>::iterator i = map.begin(); i != map.end(); i++)
        i.value()->set_color(sqr::none);
}

MainWindow::~MainWindow()
{
    delete ui;
}
