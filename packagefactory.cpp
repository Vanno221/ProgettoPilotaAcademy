#include "packagefactory.h"

PackageFactory::PackageFactory()
{

}


AbstractAlgorithm* PackageFactory::createPackage(int selectionAlgorithm, int difficulty){
    static int id{1};
    AbstractAlgorithm* package = nullptr;

    switch (selectionAlgorithm) {

        case 0:
            package = new BubbleSort(difficulty, id++);
            break;

        case 1:
            package = new MergeSort(difficulty, id++);
            break;

        default:
            qDebug("Nessun Oggetto creato");
            break;
    }

    //Instantiate myThread
    QThread *myThread = new QThread();
    //Move the algorithm package into myThread
    package->moveToThread(myThread);

    //Manage relation between package and myThrea via connect()
    connect(myThread, &QThread::started, package, &AbstractAlgorithm::sorting);
    connect(package, &AbstractAlgorithm::stopSorting, package, &AbstractAlgorithm::deleteLater);
    connect(package, &AbstractAlgorithm::stopSorting, myThread, &QThread::isFinished);
    connect(myThread, &QThread::finished, myThread, &QThread::deleteLater);

    //Manage the update of Progress bar and the status of myThread via Text edit
    connect(package, &AbstractAlgorithm::result, this, &PackageFactory::updateProgress);
    connect(package, &AbstractAlgorithm::statusThread, this, &PackageFactory::updateStatus);

    myThread->start();

    return nullptr;

}

void PackageFactory::updateProgress(int value){
    emit update(value);
}

void PackageFactory::updateStatus(QString status){
    emit updateStatusThread(status);
}

