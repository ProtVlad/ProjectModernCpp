/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *guessList;
    QLineEdit *guess;
    QComboBox *timeChoice;
    QComboBox *languageChoice;
    QComboBox *noPlayersChoice;
    QComboBox *noWordsChoice;
    QComboBox *hintsChoice;
    QLabel *timeLabel;
    QLabel *languageLabel;
    QLabel *noPlayersLabel;
    QLabel *noWordsLabel;
    QLabel *hintsLabel;
    QPushButton *startButton;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1500, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        guessList = new QListWidget(centralwidget);
        guessList->setObjectName("guessList");
        guessList->setGeometry(QRect(1140, 30, 261, 591));
        guessList->setSelectionMode(QAbstractItemView::NoSelection);
        guess = new QLineEdit(centralwidget);
        guess->setObjectName("guess");
        guess->setGeometry(QRect(1140, 650, 261, 24));
        timeChoice = new QComboBox(centralwidget);
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->addItem(QString());
        timeChoice->setObjectName("timeChoice");
        timeChoice->setGeometry(QRect(560, 110, 72, 24));
        languageChoice = new QComboBox(centralwidget);
        languageChoice->addItem(QString());
        languageChoice->addItem(QString());
        languageChoice->addItem(QString());
        languageChoice->setObjectName("languageChoice");
        languageChoice->setGeometry(QRect(560, 150, 72, 24));
        noPlayersChoice = new QComboBox(centralwidget);
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->addItem(QString());
        noPlayersChoice->setObjectName("noPlayersChoice");
        noPlayersChoice->setGeometry(QRect(560, 190, 72, 24));
        noWordsChoice = new QComboBox(centralwidget);
        noWordsChoice->addItem(QString());
        noWordsChoice->addItem(QString());
        noWordsChoice->addItem(QString());
        noWordsChoice->addItem(QString());
        noWordsChoice->addItem(QString());
        noWordsChoice->addItem(QString());
        noWordsChoice->setObjectName("noWordsChoice");
        noWordsChoice->setGeometry(QRect(560, 230, 72, 24));
        hintsChoice = new QComboBox(centralwidget);
        hintsChoice->addItem(QString());
        hintsChoice->addItem(QString());
        hintsChoice->addItem(QString());
        hintsChoice->addItem(QString());
        hintsChoice->addItem(QString());
        hintsChoice->addItem(QString());
        hintsChoice->setObjectName("hintsChoice");
        hintsChoice->setGeometry(QRect(560, 270, 72, 24));
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(514, 114, 31, 16));
        languageLabel = new QLabel(centralwidget);
        languageLabel->setObjectName("languageLabel");
        languageLabel->setGeometry(QRect(488, 154, 61, 16));
        noPlayersLabel = new QLabel(centralwidget);
        noPlayersLabel->setObjectName("noPlayersLabel");
        noPlayersLabel->setGeometry(QRect(440, 194, 101, 16));
        noWordsLabel = new QLabel(centralwidget);
        noWordsLabel->setObjectName("noWordsLabel");
        noWordsLabel->setGeometry(QRect(448, 234, 101, 16));
        hintsLabel = new QLabel(centralwidget);
        hintsLabel->setObjectName("hintsLabel");
        hintsLabel->setGeometry(QRect(512, 274, 31, 16));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(560, 630, 80, 24));
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(360, 580, 531, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        errorLabel->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1500, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        timeChoice->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        timeChoice->setItemText(1, QCoreApplication::translate("MainWindow", "20", nullptr));
        timeChoice->setItemText(2, QCoreApplication::translate("MainWindow", "30", nullptr));
        timeChoice->setItemText(3, QCoreApplication::translate("MainWindow", "40", nullptr));
        timeChoice->setItemText(4, QCoreApplication::translate("MainWindow", "50", nullptr));
        timeChoice->setItemText(5, QCoreApplication::translate("MainWindow", "60", nullptr));
        timeChoice->setItemText(6, QCoreApplication::translate("MainWindow", "70", nullptr));
        timeChoice->setItemText(7, QCoreApplication::translate("MainWindow", "80", nullptr));

        languageChoice->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        languageChoice->setItemText(1, QCoreApplication::translate("MainWindow", "Romanian", nullptr));
        languageChoice->setItemText(2, QCoreApplication::translate("MainWindow", "English", nullptr));

        noPlayersChoice->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        noPlayersChoice->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        noPlayersChoice->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        noPlayersChoice->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        noPlayersChoice->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        noPlayersChoice->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        noPlayersChoice->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        noPlayersChoice->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        noWordsChoice->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        noWordsChoice->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        noWordsChoice->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        noWordsChoice->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        noWordsChoice->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        noWordsChoice->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        hintsChoice->setItemText(0, QCoreApplication::translate("MainWindow", "-", nullptr));
        hintsChoice->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        hintsChoice->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        hintsChoice->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        hintsChoice->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        hintsChoice->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        timeLabel->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        languageLabel->setText(QCoreApplication::translate("MainWindow", "Language", nullptr));
        noPlayersLabel->setText(QCoreApplication::translate("MainWindow", "Number of players", nullptr));
        noWordsLabel->setText(QCoreApplication::translate("MainWindow", "Number of words", nullptr));
        hintsLabel->setText(QCoreApplication::translate("MainWindow", "Hints", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">All fields must have a value before starting the game!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
