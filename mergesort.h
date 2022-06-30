#ifndef MERGESORT_H
#define MERGESORT_H
#include "AbstractAlgorithm.h"

class MergeSort : public AbstractAlgorithm
{
public:
    MergeSort();
    int getDifficulty() override;
    void setDifficulty(int difficulty) override;

public slots:
    void sorting() override;

private:
    int difficulty;
};

#endif // MERGESORT_H
