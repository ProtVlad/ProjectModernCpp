#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void paintEvent(QPaintEvent *e);
    virtual void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    std::vector<std::tuple<QPoint,QColor,int,bool>> points;
    std::vector<int> widths;
    bool leftButton=false;
    QColor color={0,0,0};
    int size=3;
    bool surprise=false;
    bool verifyOutsideWindow=false;
    QColor surpriseStatus={255,0,0};
    void colorChange(QMouseEvent *e);
    bool noText(QString guess);
    int xpos;
    int ypos;
    std::vector<QColor>colors;
};
#endif // MAINWINDOW_H
