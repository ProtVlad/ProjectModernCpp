﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , leftButton(false)
    , color({ 0,0,0 })
    , size(3)
    , surprise(false)
    , verifyOutsideWindow(false)
    , surpriseStatus({ 255,0,0 })
    , xpos(100)
    , ypos(650)
    , colors({ {160,160,164},{255,0,0},{0,255,0},{0,0,255},{255,128,0},{255,128,192},{255,255,0},{185,122,87},{255,255,255},{0,0,0} })
    , widths({ 3, 5,10, 15 })
    , borders({ {100,100}, {100, 500}, {900, 100}, {900, 500} })
    , gameState(0)
    , reg(false)
{
    bigLogo = new QLabel(this);
    bigLogo->setPixmap(QPixmap("images//big_logo.png"));
    logo = new QLabel(this);
    logo->setPixmap(QPixmap("images//logoTTP.png"));
    ui->setupUi(this);
    ui->guessList->setFocusPolicy(Qt::NoFocus);
    setFocusPolicy(Qt::StrongFocus);
    setVisibilities(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    if (gameState == 4)
    {
        if (e->button() == Qt::LeftButton && e->pos().x() > xpos && e->pos().x() < xpos + 30 * (colors.size() + 1) && e->pos().y() > ypos && e->pos().y() < ypos + 30)
        {
            if ((e->pos().x() - xpos) / 30 == colors.size())
                surprise = true;
            else
            {
                color = colors[(e->pos().x() - xpos) / 30];
                surprise = false;
            }
        }
        if (e->button() == Qt::LeftButton && e->pos().x() > xpos && e->pos().x() < xpos + 30 * (widths.size()) && e->pos().y() > ypos + 30 && e->pos().y() < ypos + 60)
            size = widths[(e->pos().x() - xpos) / 30];
        if (e->button() == Qt::LeftButton && e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
        {
            leftButton = true;

            if (!surprise)
                points.push_back({ e->pos(), color, size, true });
            else
            {
                colorChange(e);
                std::get<3>(points[points.size() - 1]) = true;
            }
            update();
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
    if (gameState == 4)
    {
        if (leftButton)
        {
            actionHistory.push(points.size() - 1);
            leftButton = false;
        }
        verifyOutsideWindow = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    if (gameState == 4)
        if (leftButton)
        {
            if (e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
            {
                if (!surprise)
                {
                    points.push_back({ e->pos(), color, size, verifyOutsideWindow });
                }
                else
                    colorChange(e);
                verifyOutsideWindow = false;
            }
            else
                verifyOutsideWindow = true;
            update();
        }
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    QPen pen;
    QBrush brush;
    if (gameState == 4)
    {
        for (int i = 0; i < colors.size(); i++)
        {
            QRect r(xpos, ypos, 30, 30);
            pen.setWidth(1);
            pen.setColor({ 0,0,0 });
            brush.setColor(colors[i]);
            brush.setStyle(Qt::SolidPattern);
            p.setBrush(brush);
            p.setPen(pen);
            p.drawRect(r);
            if (i < widths.size())
            {
                QRect r(xpos, ypos + 30, 30, 30);
                pen.setWidth(1);
                pen.setColor({ 0,0,0 });
                p.setBrush(Qt::white);
                p.setPen(pen);
                p.drawRect(r);
                r = { xpos + 15 - widths[i] / 2, ypos + 45 - widths[i] / 2, widths[i], widths[i] };
                p.setBrush(Qt::black);
                p.setPen(pen);
                p.drawEllipse(r);
            }
            xpos += 30;
        }
        QRect r(xpos, ypos, 30, 30);
        pen.setWidth(1);
        pen.setColor({ 0,0,0 });
        p.setBrush(Qt::white);
        p.setPen(pen);
        p.drawRect(r);
        p.drawText(r, Qt::AlignCenter, "?");
        xpos -= 30 * colors.size();
        QRect border(borders[0].x(), borders[0].y(), borders[3].x() - borders[0].x(), borders[3].y() - borders[0].y());
        p.drawRect(border);
        for (int index = 0; index < points.size(); index++)
        {
            if (index == 0)
            {
                pen.setColor(std::get<1>(points[index]));
                pen.setWidth(std::get<2>(points[index]));
                p.setPen(pen);
                p.drawPoint(std::get<0>(points[index]));
            }
            else
            {
                if (std::get<1>(points[index]) != std::get<1>(points[index - 1]))
                {
                    pen.setColor(std::get<1>(points[index]));
                    p.setPen(pen);
                }
                if (std::get<2>(points[index]) != std::get<2>(points[index - 1]))
                {
                    pen.setWidth(std::get<2>(points[index]));
                    p.setPen(pen);
                }
            }
            if (index != 0)
            {
                if (std::get<3>(points[index]) == false)
                    p.drawLine(std::get<0>(points[index - 1]), std::get<0>(points[index]));
                else
                    p.drawPoint(std::get<0>(points[index]));
            }
        }
        pen.setWidth(17);
        pen.setColor(Qt::black);
        p.setPen(pen);
        p.drawLine(borders[0], borders[1]);
        p.drawLine(borders[0], borders[2]);
        p.drawLine(borders[1], borders[3]);
        p.drawLine(borders[2], borders[3]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Return)
    {
        if (gameState == 1)
        {
            if (ui->username->text().isEmpty() || noText(ui->username->text()))
                ui->emptyUsername->setVisible(true);
            else
                ui->emptyUsername->setVisible(false);
            if (ui->password->text().isEmpty())
                ui->emptyPassword->setVisible(true);
            else
                ui->emptyPassword->setVisible(false);
            if (!(ui->username->text().isEmpty() || noText(ui->username->text())) && !ui->password->text().isEmpty())
            {
                if (reg)
                {
                    gameState = 0;
                    setVisibilities(gameState);
                    update();
                    ui->username->clear();
                    ui->password->clear();
                    reg = false;
                }
                else
                {
                    gameState = 2;
                    setVisibilities(gameState);
                    update();
                }
            }
        }
        if (gameState == 3 || gameState == 4)
            if (!(ui->guess->text().isEmpty()) && !noText(ui->guess->text()) && ui->guess->hasFocus())
            {
                QString userGuess = ui->username->text() + ": " + ui->guess->text();
                ui->guessList->addItem(userGuess);
                ui->guess->clear();
            }
    }
}

void MainWindow::colorChange(QMouseEvent* e)
{
    bool oneAction = false;
    if (surpriseStatus.red() == 255 && surpriseStatus.green() != 255 && surpriseStatus.blue() == 0 && oneAction == false)
    {
        surpriseStatus.setGreen(surpriseStatus.green() + 15);
        oneAction = true;
    }
    if (surpriseStatus.red() != 0 && surpriseStatus.green() == 255 && surpriseStatus.blue() == 0 && oneAction == false)
    {
        surpriseStatus.setRed(surpriseStatus.red() - 15);
        oneAction = true;
    }
    if (surpriseStatus.red() == 0 && surpriseStatus.green() == 255 && surpriseStatus.blue() != 255 && oneAction == false)
    {
        surpriseStatus.setBlue(surpriseStatus.blue() + 15);
        oneAction = true;
    }
    if (surpriseStatus.red() == 0 && surpriseStatus.green() != 0 && surpriseStatus.blue() == 255 && oneAction == false)
    {
        surpriseStatus.setGreen(surpriseStatus.green() - 15);
        oneAction = true;
    }
    if (surpriseStatus.red() != 255 && surpriseStatus.green() == 0 && surpriseStatus.blue() == 255 && oneAction == false)
    {
        surpriseStatus.setRed(surpriseStatus.red() + 15);
        oneAction = true;
    }
    if (surpriseStatus.red() == 255 && surpriseStatus.green() == 0 && surpriseStatus.blue() != 0 && oneAction == false)
    {
        surpriseStatus.setBlue(surpriseStatus.blue() - 15);
        oneAction = true;
    }
    points.push_back({ e->pos(),surpriseStatus,size,verifyOutsideWindow });
}

bool MainWindow::noText(QString text)
{
    bool isEmpty = true;
    for (int index = 0; index < text.size(); index++)
    {
        if (text[index] != ' ')
            isEmpty = false;
    }
    return isEmpty;
}

void MainWindow::setVisibilities(int state)
{
    switch (state) {
    case 0:
    {
        setStyleSheet("QMainWindow {background-image: url(images//background.png)}");
        bigLogo->setGeometry(700, 200, 400, 300);
        bigLogo->setScaledContents(true);
        bigLogo->setVisible(true);
        logo->setVisible(false);
        ui->hintsChoice->setVisible(false);
        ui->hintsLabel->setVisible(false);
        ui->noPlayersChoice->setVisible(false);
        ui->noPlayersLabel->setVisible(false);
        ui->noWordsChoice->setVisible(false);
        ui->noWordsLabel->setVisible(false);
        ui->languageChoice->setVisible(false);
        ui->languageLabel->setVisible(false);
        ui->timeChoice->setVisible(false);
        ui->timeLabel->setVisible(false);
        ui->startButton->setVisible(false);
        ui->errorLabel->setVisible(false);
        ui->guess->setVisible(false);
        ui->guessList->setVisible(false);
        ui->emptyUsername->setVisible(false);
        ui->emptyPassword->setVisible(false);
        ui->clearButton->setVisible(false);
        ui->undoButton->setVisible(false);
        ui->usernameLabel->setVisible(false);
        ui->username->setVisible(false);
        ui->passwordLabel->setVisible(false);
        ui->password->setVisible(false);
        ui->createButton->setVisible(false);
        ui->joinButton->setVisible(false);
        ui->signOutButton->setVisible(false);
        ui->backButton->setVisible(false);
        ui->loginButton->setVisible(true);
        ui->registerButton->setVisible(true);
        break;
    }
    case 1:
    {
        setStyleSheet("QMainWindow {background-image: url(images//background.png)}");
        bigLogo->setGeometry(700, 200, 400, 300);
        bigLogo->setScaledContents(true);
        bigLogo->setVisible(true);
        logo->setVisible(false);
        ui->hintsChoice->setVisible(false);
        ui->hintsLabel->setVisible(false);
        ui->noPlayersChoice->setVisible(false);
        ui->noPlayersLabel->setVisible(false);
        ui->noWordsChoice->setVisible(false);
        ui->noWordsLabel->setVisible(false);
        ui->languageChoice->setVisible(false);
        ui->languageLabel->setVisible(false);
        ui->timeChoice->setVisible(false);
        ui->timeLabel->setVisible(false);
        ui->startButton->setVisible(false);
        ui->errorLabel->setVisible(false);
        ui->guess->setVisible(false);
        ui->guessList->setVisible(false);
        ui->emptyUsername->setVisible(false);
        ui->clearButton->setVisible(false);
        ui->undoButton->setVisible(false);
        ui->loginButton->setVisible(false);
        ui->registerButton->setVisible(false);
        ui->signOutButton->setVisible(false);
        ui->backButton->setVisible(true);
        ui->usernameLabel->setVisible(true);
        ui->username->setVisible(true);
        ui->passwordLabel->setVisible(true);
        ui->password->setVisible(true);
        break;
    }
    case 2:
    {
        setStyleSheet("QMainWindow {background-image: url(images//background.png)}");
        bigLogo->setGeometry(700, 200, 400, 300);
        bigLogo->setScaledContents(true);
        bigLogo->setVisible(true);
        logo->setVisible(false);
        ui->hintsChoice->setVisible(false);
        ui->hintsLabel->setVisible(false);
        ui->noPlayersChoice->setVisible(false);
        ui->noPlayersLabel->setVisible(false);
        ui->noWordsChoice->setVisible(false);
        ui->noWordsLabel->setVisible(false);
        ui->languageChoice->setVisible(false);
        ui->languageLabel->setVisible(false);
        ui->timeChoice->setVisible(false);
        ui->timeLabel->setVisible(false);
        ui->startButton->setVisible(false);
        ui->errorLabel->setVisible(false);
        ui->guess->setVisible(false);
        ui->guessList->setVisible(false);
        ui->emptyUsername->setVisible(false);
        ui->clearButton->setVisible(false);
        ui->undoButton->setVisible(false);
        ui->loginButton->setVisible(false);
        ui->registerButton->setVisible(false);
        ui->usernameLabel->setVisible(false);
        ui->username->setVisible(false);
        ui->passwordLabel->setVisible(false);
        ui->password->setVisible(false);
        ui->backButton->setVisible(false);
        ui->signOutButton->setVisible(true);
        ui->createButton->setVisible(true);
        ui->joinButton->setVisible(true);
        break;
    }
    case 3:
    {
        bigLogo->setGeometry(450, 350, 400, 300);
        bigLogo->setScaledContents(true);
        bigLogo->setVisible(true);
        logo->setVisible(false);
        ui->hintsChoice->setVisible(true);
        ui->hintsLabel->setVisible(true);
        ui->noPlayersChoice->setVisible(true);
        ui->noPlayersLabel->setVisible(true);
        ui->noWordsChoice->setVisible(true);
        ui->noWordsLabel->setVisible(true);
        ui->languageChoice->setVisible(true);
        ui->languageLabel->setVisible(true);
        ui->timeChoice->setVisible(true);
        ui->timeLabel->setVisible(true);
        ui->startButton->setVisible(true);
        ui->guess->setVisible(true);
        ui->guessList->setVisible(true);
        ui->usernameLabel->setVisible(false);
        ui->username->setVisible(false);
        ui->createButton->setVisible(false);
        ui->joinButton->setVisible(false);
        ui->emptyUsername->setVisible(false);
        ui->loginButton->setVisible(false);
        ui->registerButton->setVisible(false);
        ui->signOutButton->setVisible(false);
        break;
    }
    case 4:
    {
        bigLogo->setVisible(false);
        logo->setGeometry(5, 5, 100, 98);
        logo->setScaledContents(true);
        logo->setVisible(true);
        ui->hintsChoice->setVisible(false);
        ui->hintsLabel->setVisible(false);
        ui->noPlayersChoice->setVisible(false);
        ui->noPlayersLabel->setVisible(false);
        ui->noWordsChoice->setVisible(false);
        ui->noWordsLabel->setVisible(false);
        ui->languageChoice->setVisible(false);
        ui->languageLabel->setVisible(false);
        ui->timeChoice->setVisible(false);
        ui->timeLabel->setVisible(false);
        ui->startButton->setVisible(false);
        ui->errorLabel->setVisible(false);
        ui->clearButton->setVisible(true);
        ui->undoButton->setVisible(true);
        ui->loginButton->setVisible(false);
        ui->registerButton->setVisible(false);
        break;
    }
    default:
        break;
    }

}

void MainWindow::clear()
{
    if (!points.empty())
    {
        previousDrawings.push(points);
        points.clear();
        actionHistory.push(-1);
        update();
    }
}

void MainWindow::undo()
{
    if (actionHistory.empty())
        return;
    else
        if (actionHistory.size() == 1)
        {
            points.clear();
            actionHistory.pop();
        }
        else
            if (actionHistory.top() == -1)
            {
                points = previousDrawings.top();
                previousDrawings.pop();
                actionHistory.pop();
            }
            else
            {
                int lastUndoPoint = actionHistory.top();
                actionHistory.pop();
                for (int index = lastUndoPoint; index > actionHistory.top(); index--)
                    points.erase(points.begin() + index);
            }
    update();
}

void MainWindow::on_startButton_clicked()
{
    if (ui->hintsChoice->currentText() != '-' && ui->noPlayersChoice->currentText() != '-' && ui->noWordsChoice->currentText() != '-' &&
        ui->languageChoice->currentText() != '-' && ui->timeChoice->currentText() != '-')
    {
        gameState = 4;
        setVisibilities(gameState);
        update();
    }
    else
        ui->errorLabel->setVisible(true);
}


void MainWindow::on_createButton_clicked()
{
    gameState = 3;
    setVisibilities(gameState);
    update();
}


void MainWindow::on_joinButton_clicked()
{
    gameState = 3;
    setVisibilities(gameState);
    update();
}


void MainWindow::on_clearButton_clicked()
{
    clear();
}

void MainWindow::on_undoButton_clicked()
{
    undo();
}

void MainWindow::on_loginButton_clicked()
{
    gameState = 1;
    setVisibilities(gameState);
    update();
}

void MainWindow::on_registerButton_clicked()
{
    gameState = 1;
    setVisibilities(gameState);
    update();
    reg = true;
}

void MainWindow::on_signOutButton_clicked()
{
    gameState = 0;
    setVisibilities(gameState);
    ui->username->clear();
    ui->password->clear();
    update();
}

void MainWindow::on_backButton_clicked()
{
    gameState = 0;
    setVisibilities(gameState);
    ui->username->clear();
    ui->password->clear();
    update();
}

void MainWindow::on_password_textChanged()
{
    if (password.size() < ui->password->text().size())
        password = password + ui->password->text()[ui->password->text().size() - 1];
    else
        password.resize(ui->password->text().size());
    QString stars;
    for (int index = 0; index < password.size(); index++)
        stars = stars + '*';
    ui->password->setText(stars);
}
