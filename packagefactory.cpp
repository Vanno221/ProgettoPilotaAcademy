#include "packagefactory.h"

PackageFactory::PackageFactory()
{

}

AbstractAlgorithm* PackageFactory::createPackage(QString name){
    if (QString::compare(name, "MergeSort", Qt::CaseInsensitive) == 0){return new MergeSort();}
    if (QString::compare(name, "BubbleSort", Qt::CaseInsensitive) == 0){return new BubbleSort();}
    return nullptr;
}
