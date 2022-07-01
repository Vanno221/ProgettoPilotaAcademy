#include "mergesort.h"

MergeSort::MergeSort(int difficulty) : difficulty(difficulty)
{

}

void MergeSort::sorting(){

    emit startSorting(true);

    for(int i = 0; i < 34; i++){
     int z = 3;
     emit isRunningSorting(true);
     emit result(z);
    }
    emit stopSorting(true);

}

int MergeSort::getDifficulty(){
    return this->difficulty;
}

void MergeSort::setDifficulty(int difficulty){
    this->difficulty = difficulty;
}
