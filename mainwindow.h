#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProgressBar>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>

#include "packagefactory.h"
#include "AbstractAlgorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QComboBox;
class QRadioButton;
class QPushButton;
class QProgressBar;
class QTextEdit;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(AbstractPackageFactory *factory, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_StartThread_clicked();
    void updateProgressBar(int value);
    void updateTextEdit(QString text);


signals:
    void pushDataFactory(int, int);

private:

    Ui::MainWindow *ui;
    AbstractPackageFactory *factory;
    QProgressBar* progressThread;

    QTextEdit *ui_textEdit;

};
#endif // MAINWINDOW_H
