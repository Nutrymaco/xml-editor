#include "mainwindow.h"
#include "personxmlconverter.h"

#include <QApplication>
#include <qdom.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
