#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include<QObject>
#include <QDebug>
#include <QString>

class AbstractAlgorithm : public QObject{
    Q_OBJECT

private:
    int difficulty;

public:
    virtual ~AbstractAlgorithm() = default;
    virtual int getDifficulty() = 0;
    virtual void setDifficulty(int difficulty) = 0;

public slots:
    virtual void sorting() = 0;

signals:

    void statusThread(QString status);
    void result(int number);
    void stopSorting();
};

#endif // ABSTRACTALGORITHM_H
