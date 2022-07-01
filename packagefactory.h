#ifndef PACKAGEFACTORY_H
#define PACKAGEFACTORY_H
#include "mergesort.h"
#include "bubblesort.h"
#include "AbstractAlgorithm.h"
#include <QString>
#include "AbstractPackageFactory.h"
#include <QDebug>

class PackageFactory : public AbstractPackageFactory
{

public:
    PackageFactory();
    AbstractAlgorithm* createPackage(QString name) override;
    void test(int value) override;
};

#endif // PACKAGEFACTORY_H
