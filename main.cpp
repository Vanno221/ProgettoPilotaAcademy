#include "mainwindow.h"
#include "packagefactory.h"
#include "AbstractPackageFactory.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AbstractPackageFactory* factory = new PackageFactory();

    MainWindow w (factory);

    w.show();
    return a.exec();
}
