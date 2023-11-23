#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->guessList->setFocusPolicy(Qt::NoFocus);
    setFocusPolicy(Qt::StrongFocus);
    xpos=100;
    ypos=500;
    colors={{160,160,164},{255,0,0},{0,255,0},{0,0,255},{255,128,0},{255,128,192},{255,255,0},{185,122,87},{255,255,255},{0,0,0}};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton && e->pos().x()>xpos-15 && e->pos().x()<xpos+30*(colors.size()+1)-15 && e->pos().y()>ypos-15 && e->pos().y()<ypos+15)
    {
        if ((e->pos().x()-xpos+15)/30==colors.size())
            surprise=true;
        else
        {
            color=colors[(e->pos().x()-xpos+15)/30];
            surprise=false;
        }
    }
    if (e->button()==Qt::LeftButton && e->pos().x()>100 && e->pos().x()<400 &&  e->pos().y()>100 && e->pos().y()<400)
    {
        leftButton=true;

        if (!surprise)
            points.push_back({e->pos(), color, size, true});
        else
        {
            colorChange(e);
            std::get<3>(points[points.size()-1])=true;
        }
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftButton=false;
    verifyOutsideWindow=false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (leftButton)
    {
        if(e->pos().x()>100 && e->pos().x()<400 &&  e->pos().y()>100 && e->pos().y()<400)
        {
            if (!surprise)
            {
                points.push_back({e->pos(), color, size, verifyOutsideWindow});
            }
            else
                colorChange(e);
            verifyOutsideWindow=false;
        }
        else
        {
            verifyOutsideWindow=true;
        }
        update();
    }
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(30);
    for (int i=0; i<colors.size(); i++)
    {
        pen.setColor(colors[i]);
        p.setPen(pen);
        p.drawPoint(QPoint {xpos,ypos});
        xpos+=30;
    }
    QRect r(xpos-15, ypos-15, 30, 30);
    pen.setWidth(1);
    pen.setColor({0,0,0});
    p.setBrush(Qt::white);
    p.setPen(pen);
    p.drawRect(r);
    p.drawText(r, Qt::AlignCenter, "?");
    xpos-=30*colors.size();
    p.setPen(pen);
    for (int index=0;index<points.size();index++)
    {
        if (index==0)
        {
            pen.setColor(std::get<1>(points[index]));
            pen.setWidth(std::get<2>(points[index]));
            p.setPen(pen);
            p.drawPoint(std::get<0>(points[index]));
        }
        else
        {
            if (std::get<1>(points[index])!=std::get<1>(points[index-1]))
            {
                pen.setColor(std::get<1>(points[index]));
                p.setPen(pen);
            }
            if (std::get<2>(points[index])!=std::get<2>(points[index-1]))
            {
                pen.setWidth(std::get<2>(points[index]));
                p.setPen(pen);
            }
        }
        if (index!=0)
        {
            if (std::get<3>(points[index])==false)
                p.drawLine(std::get<0>(points[index-1]),std::get<0>(points[index]));
            else
                p.drawPoint(std::get<0>(points[index]));
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Return)
    {
        if (!(ui->guess->text().isEmpty()) && !noText(ui->guess->text()) && ui->guess->hasFocus())
        {
            ui->guessList->addItem(ui->guess->text());
            ui->guess->clear();
        }
    }
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
    points.push_back({e->pos(),surpriseStatus,size,verifyOutsideWindow});
}

bool MainWindow::noText(QString guess)
{
    bool isEmpty=true;
    for (int index=0; index<guess.size(); index++)
    {
        if(guess[index]!=' ')
                isEmpty=false;
    }
    return isEmpty;
}

void MainWindow::on_size3_toggled()
{
    size=3;
}


void MainWindow::on_size5_toggled()
{
    size=5;
}


void MainWindow::on_size10_toggled()
{
    size=10;
}

void MainWindow::on_size15_toggled()
{
    size=15;
}
