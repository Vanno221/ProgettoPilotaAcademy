#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "AbstractAlgorithm.h"
#include <iostream>

class BubbleSort : public AbstractAlgorithm
{
public:
    BubbleSort(int difficulty, int id);
    void sorting() override;
    int getDifficulty() override;
    void setDifficulty(int difficulty) override;

private:
    int difficulty;
    int id;
};
#endif // BUBBLESORT_H

