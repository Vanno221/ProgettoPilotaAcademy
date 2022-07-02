#include "packagefactory.h"

PackageFactory::PackageFactory()
{

}


AbstractAlgorithm* PackageFactory::createPackage(int selectionAlgorithm, int difficulty){


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
            break;
    }


    QThread *myThread = new QThread();
    package->moveToThread(myThread);

    connect(myThread, &QThread::started, package, &AbstractAlgorithm::sorting);

    connect(package, &AbstractAlgorithm::stopSorting, package, &AbstractAlgorithm::deleteLater);

    connect(package, &AbstractAlgorithm::stopSorting, myThread, &QThread::isFinished);

    connect(myThread, &QThread::finished, myThread, &QThread::deleteLater);

    connect(package, &AbstractAlgorithm::result, this, &PackageFactory::updateProgress);
    connect(package, &AbstractAlgorithm::statusThread, this, &PackageFactory::updateStatus);

    //connect(package, &AbstractAlgorithm::statusThread, this, &PackageFactory::updateStatus);

    myThread->start();

    return nullptr;

}

void PackageFactory::updateProgress(int value){
    emit update(value);
}

void PackageFactory::updateStatus(QString status){
    emit updateStatusThread(status);
}

