#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"
#include <QThread>

class AbstractPackageFactory : public QObject
{
    Q_OBJECT

public slots:
    virtual AbstractAlgorithm* createPackage(int selectionAlgorithm, int difficulty) = 0;

};
#endif // ABSTRACTPACKAGEFACTORY_H
