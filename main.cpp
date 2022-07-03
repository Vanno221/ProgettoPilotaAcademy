#include "mainwindow.h"
#include "packagefactory.h"
#include "AbstractPackageFactory.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Stylesheet code:

    //Load an application style
    QFile styleFile( ":/stylesheet/qss/stylesheet.qss" );
    styleFile.open( QFile::ReadOnly );
    //Apply the loaded stylesheet
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    //Manage factory
    AbstractPackageFactory* factory = new PackageFactory();

    //Passing factory to MainWindow
    MainWindow w (factory);

    w.show();
    return a.exec();
}
