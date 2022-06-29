#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include<QObject>

class AbstractAlgorithm : public QObject{
    Q_OBJECT

private:
    int difficulty;

public:
    virtual ~AbstractAlgorithm() = default;
    virtual int getDifficulty() = 0;
    virtual void setDifficulty(int difficulty) = 0;
    virtual void sorting() = 0;
};

#endif // ABSTRACTALGORITHM_H
