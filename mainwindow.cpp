#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mergesort.h"

MainWindow::MainWindow(AbstractPackageFactory *factoryMain, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , factory(factoryMain)
{
    ui->setupUi(this);

    //SINTASSI: OGGETTO SENDER, METODO DEL SENDER (SIGNALS), OGGETTO A CUI VOGLIAMO PASSARE L'INFORMAZIONE, METODO DELLO SLOT
    connect(this, &MainWindow::pushDataFactory, factory, &AbstractPackageFactory::createPackage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_StartThread_clicked()
{
    const auto radioButtonList = ui->groupBox->findChildren<QRadioButton*>();

    for(auto&& singleBox : radioButtonList)
    {
        if (singleBox->isChecked() == true)
            emit pushDataFactory(ui->comboBox_Algorithm->currentIndex() , radioButtonList.indexOf(singleBox));
    }

    QProgressBar *progressThread = new QProgressBar();

    const auto progressBarList = ui->scrollArea->findChildren<QProgressBar*>();

    QLabel *labelprogress = new QLabel(tr("ProgressBar #%1").arg((progressBarList.count())+1));

    ui->scrollAreaWidgetContents->layout()->addWidget(labelprogress);
    ui->scrollAreaWidgetContents->layout()->addWidget(progressThread);


}

