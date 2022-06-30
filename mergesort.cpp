#include "mergesort.h"

MergeSort::MergeSort()
{

}

void MergeSort::sorting(){

    for(int i = 0; i < 34; i++){
        int z = 3;
        emit result(z);
    }

    emit sortingFinished();
}


int MergeSort::getDifficulty(){
    return this->difficulty;
}

void MergeSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}
