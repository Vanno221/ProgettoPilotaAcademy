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

   /*
   QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents_2->layout());

   QString labelProgress = tr("Progress #%1").arg(layout->count());

   QProgressBar *progressThread = new QProgressBar;

   QVBoxLayout *layout = new QVBoxLayout(progressThread);

   ui->scrollArea->setWidget(progressThread);
   ui->scrollArea->setWidgetResizable(true);

   layout->addStretch();
    */
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

}

void MainWindow::on_progressBar_Thread_valueChanged(int value)
{
    //ui->progressBar_Thread->setValue(ui->progressBar_Thread->value() + value);
}
