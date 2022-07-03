#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"
#include <QThread>
#include <QString>


class AbstractPackageFactory : public QObject
{
    Q_OBJECT

public slots:
    virtual AbstractAlgorithm* createPackage(int selectionAlgorithm, int difficulty) = 0;
    virtual void updateProgress(int value) = 0;
    virtual void updateStatus(QString status) = 0;

signals:
    void update(int);                                   //Signal for transmitting progressBar update to the MainWindow
    void updateStatusThread(QString);                   //Signal for transmitting thread status to the MainWindow
};
#endif // ABSTRACTPACKAGEFACTORY_H
