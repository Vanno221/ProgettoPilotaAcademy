#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProgressBar>
#include <QPushButton>

#include "packagefactory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QComboBox;
class QRadioButton;
class QPushButton;
class QProgressBar;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(AbstractPackageFactory *factory, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_StartThread_clicked();
    void on_progressBar_Thread_valueChanged(int value); 


private:

    Ui::MainWindow *ui;

    AbstractPackageFactory *factory;

    QRadioButton *ui_radioButton_Easy;
    QRadioButton *ui_radioButton_Medium;
    QRadioButton *ui_radioButton_Hard;

    QPushButton *ui_pushButton_StartThread;

    QComboBox *ui_comboBox_Algorithm;

    QProgressBar *ui_progressBar_Thread;


};
#endif // MAINWINDOW_H
