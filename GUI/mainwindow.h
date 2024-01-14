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
#include <random>
#include <map>
#include "Points.h"

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
    void CreateThread();
    void on_timeChoice_currentTextChanged();
    void on_languageChoice_currentTextChanged();
    void on_noPlayersChoice_currentTextChanged();
    void on_noWordsChoice_currentTextChanged();
    void on_hintsChoice_currentTextChanged();
    void on_roundsChoice_currentTextChanged();

private:
    Ui::MainWindow* m_ui;
    std::map<int, Points> m_points;
    std::stack<std::map<int, Points>> m_previousDrawings;
    bool m_leftButton;
    QColor m_color;
    int m_size;
    bool m_surprise;
    bool m_verifyOutsideWindow;
    QColor m_surpriseStatus;
    int m_xpos;
    int m_ypos;
    int m_xRect;
    int m_yRect;
    std::vector<QColor>m_colors;
    std::vector<int> m_widths;
    std::stack<int> m_actionHistory;
    std::vector<QPoint> m_borders;
    GameState m_gameState;
    bool m_reg;
    QLabel* m_bigLogo;
    QLabel* m_logo;
    QString m_password;
    std::string m_username;
    std::string m_roomcode;
    QTimer* m_timer;
    std::vector<std::string> m_players;
    bool m_host;
    QString m_userGuess;
    int m_currentTime;
    bool m_chosen = false;
    std::vector<std::string> m_words;
    std::vector<std::string> m_customWords;
    int m_wordX = 150;
    int m_wordY = 350;
    std::string m_chosenWord;

private:
    void ColorChange(QMouseEvent* e);
    bool NoText(QString guess);
    void SetVisibilities(GameState state);
    void Clear();
    void Undo();
    void GetPlayersInRoom();
    void GetSettings();
    void GetGuessesInChat();
    void GetGameState();
    void GetDrawing();
    void GetChosenWords();
    void ModifySettings();
    void ReplaceCharacters(std::string& text);
    uint16_t GenerateRandomNumber(uint16_t min, uint16_t max);
    std::string GenerateCode();
    void RunTimer();
};
#endif // MAINWINDOW_H
