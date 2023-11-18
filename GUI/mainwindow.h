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

private slots:
    void on_Gray_toggled();
    void on_Red_toggled();
    void on_Green_toggled();
    void on_Blue_toggled();
    void on_Orange_toggled();
    void on_Pink_toggled();
    void on_Yellow_toggled();
    void on_Brown_toggled();
    void on_White_toggled();
    void on_Black_toggled();
    void on_Surprise_toggled();

private:
    Ui::MainWindow *ui;
    std::vector<std::pair<QPoint,QColor>> points;
    bool leftButton=false;
    QColor color={0,0,0};
    bool surprise=false;
    QColor surpriseStatus={255,0,0};
    void colorChange(QMouseEvent *e);
};
#endif // MAINWINDOW_H
