#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(900, 500);
    w.setWindowIcon(QIcon(":/images/winicon.ico"));
    w.show();
    return a.exec();
}
