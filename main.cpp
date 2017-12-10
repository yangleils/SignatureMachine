#include "mainwindow.h"
#include "users.h"
#include <QApplication>
#include "ssql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Users userSelect;
    userSelect.show();



    /*
    MainWindow w;
    w.show();
    */

    return a.exec();
}
