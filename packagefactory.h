#ifndef PACKAGEFACTORY_H
#define PACKAGEFACTORY_H
#include "mergesort.h"
#include "bubblesort.h"
#include "AbstractAlgorithm.h"
#include <QString>
#include "AbstractPackageFactory.h"

class PackageFactory : public AbstractPackageFactory
{
public:
    PackageFactory();
    AbstractAlgorithm* createPackage(QString name);
};

#endif // PACKAGEFACTORY_H
