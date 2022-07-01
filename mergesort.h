#ifndef MERGESORT_H
#define MERGESORT_H
#include "AbstractAlgorithm.h"

class MergeSort : public AbstractAlgorithm
{
public:
    MergeSort(int difficulty);
    int getDifficulty() override;
    void setDifficulty(int difficulty) override;

    static int min(int a, int b);
    void merge(int data[],int p, int q,int r);

public slots:
    void sorting() override;

private:
    int difficulty;
};

#endif // MERGESORT_H
