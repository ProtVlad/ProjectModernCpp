#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <vector>
#include <stack>
#include "GameState.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <QtConcurrent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);
    virtual void keyPressEvent(QKeyEvent* e);

private slots:
    void on_startButton_clicked();
    void on_createButton_clicked();
    void on_joinButton_clicked();
    void on_clearButton_clicked();
    void on_undoButton_clicked();
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_signOutButton_clicked();
    void on_backButton_clicked();
    void on_password_textChanged();
    void createThread();

private:
    Ui::MainWindow* ui;
    std::vector<std::tuple<QPoint, QColor, int, bool>> points;
    std::stack<std::vector<std::tuple<QPoint, QColor, int, bool>>> previousDrawings;
    bool leftButton;
    QColor color;
    int size;
    bool surprise;
    bool verifyOutsideWindow;
    QColor surpriseStatus;
    int xpos;
    int ypos;
    int xRect;
    int yRect;
    std::vector<QColor>colors;
    std::vector<int> widths;
    std::stack<int> actionHistory;
    std::vector<QPoint> borders;
    GameState gameState;
    bool reg;
    QLabel* bigLogo;
    QLabel* logo;
    QString password;
    std::string username;
    std::string roomcode = "test";
    QTimer* timer;
    std::vector<std::string> players;
    int count = 0;
private:
    void colorChange(QMouseEvent* e);
    bool noText(QString guess);
    void setVisibilities(GameState state);
    void clear();
    void undo();
    void GetPlayersInRoom();
};
#endif // MAINWINDOW_H
