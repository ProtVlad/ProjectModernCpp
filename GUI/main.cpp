#include <iostream>
#include <cpr/cpr.h>
#include <crow.h>

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:13034/products" });

    if (response.error) {
        std::cerr << "Eroare la conectarea la server: " << response.error.message << std::endl;
    }
    else {
        std::cout << "Raspuns de la server: " << response.text << std::endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
