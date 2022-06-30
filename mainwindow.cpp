#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mergesort.h"
#include <QDebug>

MainWindow::MainWindow(AbstractPackageFactory *factoryMain, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , factory(factoryMain)
{

    ui->setupUi(this);

    ui_radioButton_Easy = findChild<QRadioButton*>("radioButton_Easy");
    ui_radioButton_Medium = findChild<QRadioButton*>("radioButton_Medium");
    ui_radioButton_Hard = findChild<QRadioButton*>("radioButton_Hard");
    ui_comboBox_Algorithm = findChild<QComboBox*>("comboBox_Algorithm");
    ui_pushButton_StartThread = findChild<QPushButton*>("pushButton_StartThread");
    ui_progressBar_Thread = findChild<QProgressBar*>("progressBar_Thread");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_StartThread_clicked()
{
    QThread *myThread = new QThread();

/*  // It doesn't work ....
    if(ui->comboBox_Algorithm->currentIndex()==1){
        AbstractAlgorithm* package = factory->createPackage("MergeSort");
    }
    if(ui->comboBox_Algorithm->currentIndex()==0){
        AbstractAlgorithm* package = factory->createPackage("BubbleSort");
    }
*/

    AbstractAlgorithm* package = factory->createPackage("MergeSort");

//    if(myThread->currentThread()->isRunning())
//      qDebug("isRunning");

    package->moveToThread(myThread);

    connect(myThread, &QThread::started, package, &AbstractAlgorithm::sorting);
    connect(package, &AbstractAlgorithm::result, this,&MainWindow::on_progressBar_Thread_valueChanged);
    connect(package, &AbstractAlgorithm::sortingFinished, package, &AbstractAlgorithm::deleteLater);

    myThread->start();
}

void MainWindow::on_progressBar_Thread_valueChanged(int value)
{
    ui_progressBar_Thread->setValue(ui_progressBar_Thread->value() + value);
}
