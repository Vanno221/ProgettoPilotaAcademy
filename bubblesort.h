#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "AbstractAlgorithm.h"

class BubbleSort : public AbstractAlgorithm
{
public:

    BubbleSort();
    void sorting() override;
    int getDifficulty() override;
    void setDifficulty(int difficulty) override;
private:
    int difficulty;
};

#endif // BUBBLESORT_H
