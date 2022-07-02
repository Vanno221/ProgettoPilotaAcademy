#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"
#include <QThread>

class AbstractPackageFactory : public QObject
{
    Q_OBJECT

public slots:
    virtual AbstractAlgorithm* createPackage(int selectionAlgorithm, int difficulty) = 0;
    virtual void updateProgress(int value) = 0;

signals:
    void update(int);
};
#endif // ABSTRACTPACKAGEFACTORY_H
