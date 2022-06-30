#ifndef ABSTRACTPACKAGEFACTORY_H
#define ABSTRACTPACKAGEFACTORY_H
#include "AbstractAlgorithm.h"

class AbstractPackageFactory
{
public:
    virtual AbstractAlgorithm* createPackage(QString name) = 0;
};
#endif // ABSTRACTPACKAGEFACTORY_H
