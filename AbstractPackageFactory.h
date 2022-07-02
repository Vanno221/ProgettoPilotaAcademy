#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"
#include <QThread>

class AbstractPackageFactory : public QObject
{
    Q_OBJECT

public slots:
    virtual AbstractAlgorithm* createPackage(int selectionAlgorithm, int difficulty) = 0;
    //virtual void sortingValue(int value) = 0;
/*
signals:
    void updateProgress(int);
*/
};
#endif // ABSTRACTPACKAGEFACTORY_H
