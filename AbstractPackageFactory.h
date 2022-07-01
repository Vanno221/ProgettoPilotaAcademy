#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"

class AbstractPackageFactory : public QObject
{
    Q_OBJECT
public:
    virtual AbstractAlgorithm* createPackage(QString name) = 0;

public slots:
    virtual void test(int value) = 0;
};
#endif // ABSTRACTPACKAGEFACTORY_H
