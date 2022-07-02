#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include<QObject>
#include <QDebug>

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

    void startSorting(bool = false);
    void isRunningSorting(bool = false);
    void stopSorting(bool = false);
    void result(int number);
};

#endif // ABSTRACTALGORITHM_H
