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
    AbstractAlgorithm* createPackage(int selectionAlgorithm, int difficulty) override;
    void updateProgress(int value) override;
    void updateStatus(QString status) override;

};

#endif // PACKAGEFACTORY_H
