#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mergesort.h"

MainWindow::MainWindow(AbstractPackageFactory *factoryMain, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , factory(factoryMain)
{

    ui->setupUi(this);

    connect(this, &MainWindow::pushDataFactory, factory, &AbstractPackageFactory::createPackage);

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
    /*



    //SINTASSI: OGGETTO SENDER, METODO DEL SENDER (SIGNALS), OGGETTO A CUI VOGLIAMO PASSARE L'INFORMAZIONE, METODO DELLO SLOT


    connect(package, &AbstractAlgorithm::result, this,&MainWindow::on_progressBar_Thread_valueChanged);


    myThread->start();

    */

    const auto radioButtonList = ui->groupBox->findChildren<QRadioButton*>();

    for(auto&& singleBox : radioButtonList)
    {
        if (singleBox->isChecked() == true)
            emit pushDataFactory(ui->comboBox_Algorithm->currentIndex() , radioButtonList.indexOf(singleBox));
    }

}

void MainWindow::on_progressBar_Thread_valueChanged(int value)
{
    ui_progressBar_Thread->setValue(ui_progressBar_Thread->value() + value);
}
