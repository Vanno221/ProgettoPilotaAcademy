#include "packagefactory.h"

PackageFactory::PackageFactory()
{

}

AbstractAlgorithm* PackageFactory::createPackage(int selectionAlgorithm, int difficulty){

    qDebug() << selectionAlgorithm << difficulty;

    AbstractAlgorithm* package = nullptr;

    switch (selectionAlgorithm) {

        case 0:
            package = new BubbleSort(difficulty);
            break;
        case 1:
            package = new MergeSort(difficulty);
            break;

        default:
            qDebug("Nessun Oggetto creato");
    }

    QThread *myThread = new QThread();
    package->moveToThread(myThread);

    connect(myThread, &QThread::started, package, &AbstractAlgorithm::sorting);

    connect(package, &AbstractAlgorithm::stopSorting, package, &AbstractAlgorithm::deleteLater);

    //myThread->start();

    return nullptr;
}

