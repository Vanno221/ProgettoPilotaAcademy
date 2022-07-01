#include "packagefactory.h"

PackageFactory::PackageFactory()
{

}

AbstractAlgorithm* PackageFactory::createPackage(QString name){
    if (QString::compare(name, "MergeSort", Qt::CaseInsensitive) == 0){return new MergeSort(1);}
    if (QString::compare(name, "BubbleSort", Qt::CaseInsensitive) == 0){return new BubbleSort(1);}
    return nullptr;
}

void PackageFactory::test(int value){
    qDebug() << value;
}
