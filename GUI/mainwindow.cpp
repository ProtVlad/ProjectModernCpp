#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->guessList->setFocusPolicy(Qt::NoFocus);
    setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
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
