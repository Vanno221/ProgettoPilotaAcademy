#include "mainwindow.h"
#include "packagefactory.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*
    PackageFactory* factory = new PackageFactory();

    AbstractAlgorithm* test = factory->createPackage("Merge");
    AbstractAlgorithm* test2 = factory->createPackage("Quick");

    test->sorting();
    test2->sorting();
    */

    w.show();
    return a.exec();
}
