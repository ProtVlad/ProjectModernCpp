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
        if (!surprise)
            points.push_back({e->pos(), color});
        else
            colorChange(e);
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
        if (!surprise)
            points.push_back({e->pos(), color});
        else
            colorChange(e);
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
        if (index==0)
        {
            pen.setColor(points[index].second);
            p.setPen(pen);
        }
        else
            if (points[index].second!=points[index-1].second)
            {
                pen.setColor(points[index].second);
                p.setPen(pen);
            }
        p.drawPoint(points[index].first);
    }
}


void MainWindow::on_Gray_toggled()
{
    color=Qt::gray;
    surprise=false;
}

void MainWindow::on_Red_toggled()
{
    color={255,0,0};
    surprise=false;
}

void MainWindow::on_Green_toggled()
{
    color={0,255,0};
    surprise=false;
}

void MainWindow::on_Blue_toggled()
{
    color={0,0,255};
    surprise=false;
}

void MainWindow::on_Orange_toggled()
{
    color={255,128,0};
    surprise=false;
}

void MainWindow::on_Pink_toggled()
{
    color={255,128,192};
    surprise=false;
}


void MainWindow::on_Yellow_toggled()
{
    color={255,255,0};
    surprise=false;
}


void MainWindow::on_Brown_toggled()
{
    color={185,122,87};
    surprise=false;
}

void MainWindow::on_White_toggled()
{
    color={255,255,255};
    surprise=false;
}

void MainWindow::on_Black_toggled()
{
    color={0,0,0};
    surprise=false;
}


void MainWindow::on_Surprise_toggled()
{
    surprise=true;
}

void MainWindow::colorChange(QMouseEvent *e)
{
    bool oneAction=false;
    if (surpriseStatus.red()==255 && surpriseStatus.green()!=255 && surpriseStatus.blue()==0 && oneAction==false)
    {
        surpriseStatus.setGreen(surpriseStatus.green()+15);
        oneAction=true;
    }
    if (surpriseStatus.red()!=0 && surpriseStatus.green()==255 && surpriseStatus.blue()==0 && oneAction==false)
    {
        surpriseStatus.setRed(surpriseStatus.red()-15);
        oneAction=true;
    }
    if (surpriseStatus.red()==0 && surpriseStatus.green()==255 && surpriseStatus.blue()!=255 && oneAction==false)
    {
        surpriseStatus.setBlue(surpriseStatus.blue()+15);
        oneAction=true;
    }
    if (surpriseStatus.red()==0 && surpriseStatus.green()!=0 && surpriseStatus.blue()==255 && oneAction==false)
    {
        surpriseStatus.setGreen(surpriseStatus.green()-15);
        oneAction=true;
    }
    if (surpriseStatus.red()!=255 && surpriseStatus.green()==0 && surpriseStatus.blue()==255 && oneAction==false)
    {
        surpriseStatus.setRed(surpriseStatus.red()+15);
        oneAction=true;
    }
    if (surpriseStatus.red()==255 && surpriseStatus.green()==0 && surpriseStatus.blue()!=0 && oneAction==false)
    {
        surpriseStatus.setBlue(surpriseStatus.blue()-15);
        oneAction=true;
    }
    points.push_back({e->pos(),surpriseStatus});
}
