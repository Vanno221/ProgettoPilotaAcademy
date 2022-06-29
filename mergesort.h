#ifndef MERGESORT_H
#define MERGESORT_H
#include "AbstractAlgorithm.h"

class MergeSort : public AbstractAlgorithm
{
public:
    MergeSort();
    void sorting() override;
    int getDifficulty() override;
    void setDifficulty(int difficulty) override;
private:
    int difficulty;
};

#endif // MERGESORT_H
