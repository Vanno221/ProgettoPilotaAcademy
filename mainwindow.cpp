#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mergesort.h"

MainWindow::MainWindow(AbstractPackageFactory *factoryMain, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , factory(factoryMain)
{
    ui->setupUi(this);

    ui_textEdit = findChild<QTextEdit*>("textEdit");

    //CONNECT SINTAX: sender object, sender method (SIGNALS), receiving object, receiving method (SLOT)
    connect(this, &MainWindow::pushDataFactory, factory, &AbstractPackageFactory::createPackage);
    connect(factory, &AbstractPackageFactory::update, this, &MainWindow::updateProgressBar);
    connect(factory, &AbstractPackageFactory::updateStatusThread, this, &MainWindow::updateTextEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


//Manage widgets behaviour when starting the Start button

void MainWindow::on_pushButton_StartThread_clicked()
{
    //Make a radioButton list to keep trace of the three different difficulty choices
    const auto radioButtonList = ui->groupBox->findChildren<QRadioButton*>();

    progressThread = new QProgressBar();
    //Set start value to zero
    progressThread->setValue(0);

    //Make a progressBar list to keep trace of the labels
    const auto progressBarList = ui->scrollArea->findChildren<QProgressBar*>();
    QLabel *labelprogress = new QLabel(tr("ProgressBar #%1").arg((progressBarList.count())+1));

    ui->scrollAreaWidgetContents->layout()->addWidget(labelprogress);
    ui->scrollAreaWidgetContents->layout()->addWidget(progressThread);


    //Manage radio buttons when no selection has been done
    int tmp{};
    //singleBox is the index which runs the radioButton List
    for(auto&& singleBox: radioButtonList){
        if(singleBox->isChecked() == false)
            tmp++;
    }
    if(tmp==3)
        ui_textEdit->append("No difficulty inserted, please choose one!");


    //Manage the different choices in the radioButton: Easy - Medium - Hard
    for(auto&& singleBox : radioButtonList)
    {
        if (singleBox->isChecked() == true)
            //Emitting the signal for both Type_Algorithm and Difficulty_Algorithm
            emit pushDataFactory(ui->comboBox_Algorithm->currentIndex() , radioButtonList.indexOf(singleBox));                      
    }
}

void MainWindow::updateProgressBar(int value){
    progressThread->setValue(progressThread->value() + value);
}

void MainWindow::updateTextEdit(QString text){
    ui_textEdit->append(text);
}
