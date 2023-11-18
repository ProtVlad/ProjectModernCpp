#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton)
    {
        leftButton=true;
        points.push_back({e->pos()});
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftButton=false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (leftButton)
    {
        points.push_back({e->pos()});
        update();
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    p.setPen(pen);
    for (int index=0;index<points.size();index++)
    {
        p.drawPoint(points[index]);
    }
}

