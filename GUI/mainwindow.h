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
    bool leftButton;
    QColor color;
    int size;
    bool surprise;
    bool verifyOutsideWindow;
    QColor surpriseStatus;
    void colorChange(QMouseEvent *e);
    bool noText(QString guess);
    int xpos;
    int ypos;
    std::vector<QColor>colors;
    std::vector<int> widths;
};
#endif // MAINWINDOW_H
